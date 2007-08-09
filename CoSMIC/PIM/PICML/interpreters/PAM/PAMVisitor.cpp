#include "PAM/PAMVisitor.h"

#include <algorithm>
#include <functional>
#include <sstream>
#include <boost/bind.hpp>
#include <boost/ref.hpp>


namespace PICML
{
  using Utils::CreateUuid;
  using std::set;
  using std::vector;
  using std::string;
  using std::map;
  using boost::bind;
  using boost::ref;
  using boost::cref;

  PAMVisitor::PAMVisitor (const Udm::Object& focusObject,
                          const set<Udm::Object>& selectedObjects)
    : focusObject_ (focusObject),
      selectedObjects_ (selectedObjects)
  {
  }

  PAMVisitor::~PAMVisitor ()
  {
  }

  void PAMVisitor::Visit_RootFolder (const RootFolder& rf)
  {
    this->rootFolder_ = rf;
    vector<PredefinedTypes>
      predefinedTypes = this->rootFolder_.PredefinedTypes_kind_children();
    vector<String>
      stringType = predefinedTypes.begin()->String_kind_children();
    if (stringType.begin() != stringType.end())
      this->stringType_ = *stringType.begin();
    vector<Boolean>
      booleanType = predefinedTypes.begin()->Boolean_kind_children();
    if (booleanType.begin() != booleanType.end())
      this->booleanType_ = *booleanType.begin();
    vector<LongInteger>
      longType = predefinedTypes.begin()->LongInteger_kind_children();
    if (longType.begin() != longType.end())
      this->longType_ = *longType.begin();
    vector<ShortInteger>
      shortType = predefinedTypes.begin()->ShortInteger_kind_children();
    if (shortType.begin() != shortType.end())
      this->shortType_ = *shortType.begin();

    if (this->focusObject_ != Udm::null && !this->selectedObjects_.empty())
      throw udm_exception ("focusObject non-null && selectedObjects non-empty");

    if (this->focusObject_ != Udm::null)
      this->selectedObjects_.insert (this->focusObject_);
    if (this->selectedObjects_.size() == 1)
      {
        set<DeploymentPlan> plans;
        transform (this->selectedObjects_.begin(), this->selectedObjects_.end(),
                   inserter (plans, plans.begin()),
                   UdmCaster<DeploymentPlan>());
        for_each (plans.begin(), plans.end(),
                  bind (&DeploymentPlan::Accept, _1, ref (*this)));
        this->UpdateDeploymentPlans (plans);
        this->CleanUpAssemblies();
      }
    else if (selectedObjects_.empty())
      {
        set<DeploymentPlans> dps = rf.DeploymentPlans_kind_children();
        for_each (dps.begin(), dps.end(),
                  bind (&DeploymentPlans::Accept, _1, ref (*this)));
      }
    else
      {
        set<DeploymentPlan> plans;
        transform (this->selectedObjects_.begin(), this->selectedObjects_.end(),
                   inserter (plans, plans.begin()),
                   UdmCaster<DeploymentPlan>());
        this->MergeDeploymentPlans (plans);
        this->UpdateDeploymentPlans (plans);
        this->CleanUpAssemblies();
      }
  }

  void PAMVisitor::MergeDeploymentPlans (set<DeploymentPlan>& plans)
  {
    set<DeploymentPlan>::iterator pBegin, pEnd;
    set<Node> nodes;
    multimap<Node, CollocationGroup> nodeCgMap;
    for (boost::tie (pBegin, pEnd) = make_pair (plans.begin(), plans.end());
         pBegin != pEnd;
         ++pBegin)
      {
        DeploymentPlan plan = *pBegin;
        set<CollocationGroup> cgs = plan.CollocationGroup_kind_children();
        set<CollocationGroup>::iterator cgBegin, cgEnd;
        for (boost::tie (cgBegin, cgEnd) = make_pair (cgs.begin(), cgs.end());
             cgBegin != cgEnd;
             ++cgBegin)
          {
            CollocationGroup cg = *cgBegin;
            set<InstanceMapping> instanceMapping = cg.dstInstanceMapping();
            if (!instanceMapping.empty())
              {
                InstanceMapping mapping = *instanceMapping.begin();
                NodeReference nodeRef = mapping.dstInstanceMapping_end();
                Node node = nodeRef.ref();
                nodes.insert (node);
                nodeCgMap.insert (make_pair (node, cg));
              }
          }
      }
    set<Node>::iterator nBegin, nEnd;
    for (boost::tie (nBegin, nEnd) = make_pair (nodes.begin(), nodes.end());
         nBegin != nEnd;
         ++nBegin)
      {
        Node node = *nBegin;
        // Collect all the candidate instances
        set<Component> candidateInstances;
        set<Component> candidateTypes;
        multimap<Node, CollocationGroup>::iterator cgBegin, cgEnd;
        for (boost::tie (cgBegin, cgEnd) = nodeCgMap.equal_range (node);
             cgBegin != cgEnd;
             ++cgBegin)
          {
            CollocationGroup cg = cgBegin->second;
            set<CollocationGroup_Members_Base> cgmembers = cg.members();
            this->CreateCandidateComponents (cgmembers,
                                             candidateTypes,
                                             candidateInstances);
          }
        this->CreatePhysicalAssemblies (candidateTypes);
      }
  }

  void PAMVisitor::Visit_DeploymentPlans (const DeploymentPlans& dps)
  {
    set<DeploymentPlan> plans = dps.DeploymentPlan_kind_children();
    for_each (plans.begin(), plans.end(),
              bind (&DeploymentPlan::Accept, _1, ref (*this)));
    this->UpdateDeploymentPlans (plans);
    this->CleanUpAssemblies();
  }

  void PAMVisitor::Visit_DeploymentPlan (const DeploymentPlan& plan)
  {
    // Visit each Collocation Group
    set<CollocationGroup> cgs = plan.CollocationGroup_kind_children();
    for_each (cgs.begin(), cgs.end(),
              bind (&CollocationGroup::Accept, _1, ref (*this)));
  }

  void PAMVisitor::Visit_CollocationGroup (const CollocationGroup& cg)
  {
    set<CollocationGroup_Members_Base> cgmembers = cg.members();
    set<Component> candidateTypes;
    set<Component> candidateInstances;
    this->CreateCandidateComponents (cgmembers,
                                     candidateTypes,
                                     candidateInstances);
    this->CreatePhysicalAssemblies (candidateTypes);
  }

  void PAMVisitor::CleanUpAssemblies ()
  {
    CliqueSets::iterator begin, end;
    for (boost::tie (begin, end) = make_pair (this->cliqueSets_.begin(),
                                              this->cliqueSets_.end());
         begin != end;
         ++begin)
      {
        set<Component> clique (begin->begin(), begin->end());
        if (clique.size() == 1)
          continue;
        for_each (clique.begin(), clique.end(), UdmObjectDeleter<Component>());
      }
  }

  void PAMVisitor::ConnectCgNodeRef(const CollocationGroup& cg)
  {
    // Connect the CollocationGroup with the appropriate NodeReference
    InstanceMapping newMapping = InstanceMapping::Create (this->asmPlan_);
    set<InstanceMapping> oldNodeRefs  = cg.dstInstanceMapping();
    if (oldNodeRefs.begin() == oldNodeRefs.end())
      return;
    typedef set<NodeReference, ReferenceSorter<NodeReference> > NodeRefs;
    NodeRefs nodeRefs
      = this->asmPlan_.NodeReference_kind_children_sorted (ReferenceSorter<NodeReference>());
    NodeReference assocNode = (*oldNodeRefs.begin()).dstInstanceMapping_end();
    NodeRefs::iterator nIter = nodeRefs.find (assocNode);
    if (nIter != nodeRefs.end())
      {
        NodeReference target = *nIter;
        newMapping.srcInstanceMapping_end() = this->asmCg_;
        newMapping.dstInstanceMapping_end() = target;
      }
  }

  void PAMVisitor::CloneDeploymentPlanElements(const DeploymentPlan& plan)
  {
    // Clone all the properties
    typedef vector<Property>::iterator PropIter;
    PropIter pBegin, pEnd;
    vector<Property> planProps = plan.Property_kind_children();
    CloneSequence (planProps.begin(), planProps.end(), this->asmPlan_);
    // Clone all the node references
    vector<NodeReference> nodeRefs = plan.NodeReference_kind_children();
    CloneSequence (nodeRefs.begin(), nodeRefs.end(), this->asmPlan_);
  }


  void PAMVisitor::UpdateDeploymentPlans (const set<DeploymentPlan>& plans)
  {
    set<Component> globalVisited;
    set<DeploymentPlan>::const_iterator pBegin, pEnd;
    for (boost::tie (pBegin, pEnd) = make_pair (plans.begin(), plans.end());
         pBegin != pEnd;
         ++pBegin)
      {
        DeploymentPlan plan (*pBegin);
        this->asmPlan_ = DeploymentPlan::Create (plan.parent());
        this->asmPlan_.name() = string (plan.name()) + "_Asm";
        this->CloneDeploymentPlanElements (plan);
        set<Component> localVisited;
        vector<CollocationGroup>::iterator cgBegin, cgEnd;
        vector<CollocationGroup> cgs = plan.CollocationGroup_kind_children();
        for (boost::tie (cgBegin, cgEnd) = make_pair (cgs.begin(), cgs.end());
             cgBegin != cgEnd;
             ++cgBegin)
          {
            CollocationGroup cg = *cgBegin;
            this->asmCg_ = Clone (cg, this->asmPlan_);
            this->ConnectCgNodeRef(cg);
            set<CollocationGroup_Members_Base> cgmembers = cg.members();
            set<Component> types, instances;
            this->CreateCandidateComponents (cgmembers,
                                             types,
                                             instances);
            set<Component>::iterator cBegin, cEnd;
            for (boost::tie (cBegin, cEnd) = make_pair (instances.begin(),
                                                        instances.end());
                 cBegin != cEnd;
                 ++cBegin)
              {
                Component comp = *cBegin;
                string compName = comp.name();
                // Find the cliqueInstance corr. to comp
                Component instance;
                CliqueMap::iterator compIter = this->cliqueMap_.find (comp);
                if (compIter == this->cliqueMap_.end())
                  {
                    // The current component is a normal component, i.e.,
                    // not part of a physical assembly
                    instance = comp;
                  }
                else
                  {
                    // The current component is part of a physical assembly
                    instance = compIter->second;
                  }
                string instanceName = instance.name();
                // Have we ever created a reference to this component
                // in this plan?
                set<Component>::iterator local = localVisited.find (instance);
                if (local != localVisited.end())
                  continue;
                // Have we ever created a reference to this component
                // before?
                set<Component>::iterator global = globalVisited.find (instance);
                if (global == globalVisited.end())
                  {
                    // This is the first time that we are encountering this
                    // component instance.
                    ComponentRef
                      compRef = ComponentRef::Create (this->asmPlan_);
                    compRef.ref() = instance;
                    compRef.name() = instance.name();
                    set<CollocationGroup> cgset;
                    cgset.insert (this->asmCg_);
                    compRef.setCollocationGroup() = cgset;
                    // We have visited this guy atleast once
                    globalVisited.insert (instance);
                    // We have visited this guy once in this plan
                    localVisited.insert (instance);
                  }
                else
                  {
                    // Some other plan has already created a reference
                    // to this clique instance.  Create a
                    // SharedComponentReference to it.
                    ComponentAssembly parent
                      = comp.ComponentAssembly_parent();
                    set<ComponentRef> sharedCompRefs
                      = parent.ComponentRef_kind_children();
                    Referred<Component, ComponentRef> referred (instance);
                    set<ComponentRef>::iterator found;
                    found = find_if (sharedCompRefs.begin(),
                                     sharedCompRefs.end(),
                                     referred);
                    if (found != sharedCompRefs.end())
                      {
                        // Create a Shared Component to the created
                        // reference
                        SharedComponentReference sharedComponent
                          = SharedComponentReference::Create (this->asmPlan_);
                        sharedComponent.ref() = *found;
                        sharedComponent.name() = found->name();
                        // Add the shared component to the current
                        // collocation group
                        set<CollocationGroup> cgset;
                        cgset.insert (this->asmCg_);
                        sharedComponent.setCollocationGroup() = cgset;
                        localVisited.insert (instance);
                      }
                    else
                      {
                        throw
                          udm_exception ("Unable to find reference to shared"
                                         "component in component assembly");
                      }
                  }
              }
          }
      }
  }

  string PAMVisitor::CreateCliqueString (const set<Component>& clique)
  {
    set<string> names;
    set<Component>::const_iterator cBegin, cEnd;
    for (boost::tie (cBegin, cEnd) = make_pair (clique.begin(),
                                                clique.end());
         cBegin != cEnd;
         ++cBegin)
      {
        Component comp (*cBegin);
        names.insert (comp.name());
      }
    stringstream ss;
    copy (names.begin(), names.end(), ostream_iterator<string> (ss, "_"));
    string name = ss.str();
    // Remove the trailing underscore
    name.erase (name.end() - 1);
    return name;
  }


  void PAMVisitor::UpdateAssembly (const set<Component>& clique)
  {
    if (clique.size() == 1)
      return;
    set<ComponentAssembly> cliqueAssemblies;
    transform (clique.begin(), clique.end(),
               inserter (cliqueAssemblies, cliqueAssemblies.begin()),
               AssemblyParent());
    bool asmCreated = false;
    set<ComponentAssembly>::iterator asmBegin, asmEnd;
    for (boost::tie (asmBegin, asmEnd) = make_pair (cliqueAssemblies.begin(),
                                                    cliqueAssemblies.end());
         asmBegin != asmEnd;
         ++asmBegin)
      {
        ComponentAssembly cliqueAsm = *asmBegin;
        if (!asmCreated)
          {
            // Create component instance inside the assembly
            this->asmInstance_ = this->asmComp_.CreateInstance (cliqueAsm);
            this->asmInstance_.name() = CreateCliqueString (clique);
            this->asmInstance_.UUID() = Utils::CreateUuid();
            this->UpdateComponentConnections (cliqueAsm, this->asmInstance_,
                                              clique);
            this->UpdateAttributes (cliqueAsm, this->asmInstance_, clique);
            asmCreated = true;
          }
        else
          {
            // Create a reference to the current asmInstance
            ComponentRef compRef = ComponentRef::Create (cliqueAsm);
            compRef.ref() = this->asmInstance_;
            compRef.name() = this->asmInstance_.name();
            this->UpdateComponentConnections (cliqueAsm, this->asmInstance_,
                                              clique);
          }
        // Update the Component QoS properties
        //         UpdateConnection (cliqueAsm, this->asmInstance_, clique,
        //                           &ComponentAssembly::ComponentQoS_kind_children,
        //                           &ComponentQoS::srcComponentQoS_end);
      }
    set<Component>::const_iterator cBegin, cEnd;
    for (boost::tie (cBegin, cEnd) = make_pair (clique.begin(),
                                                clique.end());
         cBegin != cEnd;
         ++cBegin)
      {
        Component temp (*cBegin);
        this->cliqueMap_[temp] = this->asmInstance_;
      }
  }

  void PAMVisitor::UpdateComponentConnections (const ComponentAssembly& container,
                                               const Component& asmInstance,
                                               const set<Component>& clique)
  {
    // Update the receptacles
    UpdatePortConnection (container, asmInstance, clique,
                          &ComponentAssembly::invoke_kind_children,
                          &invoke::srcinvoke_end,
                          &Component::RequiredRequestPort_kind_children,
                          &RequiredRequestPort::parent);
    // Update the facets
    UpdatePortConnection (container, asmInstance, clique,
                          &ComponentAssembly::invoke_kind_children,
                          &invoke::dstinvoke_end,
                          &Component::ProvidedRequestPort_kind_children,
                          &ProvidedRequestPort::parent);
    // Update the event emitters
    UpdatePortConnection (container, asmInstance, clique,
                          &ComponentAssembly::emit_kind_children,
                          &emit::srcemit_end,
                          &Component::OutEventPort_kind_children,
                          &OutEventPort::parent);
    // Update the event consumers (emitter source)
    UpdatePortConnection (container, asmInstance, clique,
                          &ComponentAssembly::emit_kind_children,
                          &emit::dstemit_end,
                          &Component::InEventPort_kind_children,
                          &InEventPort::parent);
    // Update the event publisher side
    UpdatePortConnection (container, asmInstance, clique,
                          &ComponentAssembly::publish_kind_children,
                          &publish::srcpublish_end,
                          &Component::OutEventPort_kind_children,
                          &OutEventPort::parent);
    // Update the event consumer (publisher source)
    UpdatePortConnection (container, asmInstance, clique,
                          &ComponentAssembly::deliverTo_kind_children,
                          &deliverTo::dstdeliverTo_end,
                          &Component::InEventPort_kind_children,
                          &InEventPort::parent);
  }

  void PAMVisitor::CollectPorts (const Component& comp,
                                 vector<ProvidedRequestPort>& facets,
                                 vector<RequiredRequestPort>& receptacles,
                                 vector<OutEventPort>& publishers,
                                 vector<InEventPort>& consumers,
                                 SupportedInterfaces& supportedInterfaces,
                                 ReadonlyAttributes& readonlyAttributes,
                                 Attributes& attributes)
  {
    vector<ProvidedRequestPort>
      facet_children = comp.ProvidedRequestPort_kind_children();
    copy (facet_children.begin(), facet_children.end(),
          back_inserter (facets));
    vector<RequiredRequestPort>
      receptacle_children = comp.RequiredRequestPort_kind_children();
    copy (receptacle_children.begin(), receptacle_children.end(),
          back_inserter (receptacles));
    vector<InEventPort> consumer_children = comp.InEventPort_kind_children();
    copy (consumer_children.begin(), consumer_children.end(),
          back_inserter (consumers));
    vector<OutEventPort> publisher_children = comp.OutEventPort_kind_children();
    copy (publisher_children.begin(), publisher_children.end(),
          back_inserter (publishers));
    vector<ReadonlyAttribute>
      readattr_children = comp.ReadonlyAttribute_kind_children();
    // Differentiate between read-only attributes and attributes
    IsReadOnlyAttribute predicate;
    copy (boost::make_filter_iterator (predicate,
                                       readattr_children.begin(),
                                       readattr_children.end()),
          boost::make_filter_iterator (predicate,
                                       readattr_children.end(),
                                       readattr_children.end()),
          inserter (readonlyAttributes, readonlyAttributes.begin()));
    vector<Attribute> attr_children = comp.Attribute_kind_children();
    copy (attr_children.begin(), attr_children.end(),
          inserter (attributes, attributes.begin()));
    vector<Supports> supp_interfaces = comp.Supports_kind_children();
    copy (supp_interfaces.begin(), supp_interfaces.end(),
          inserter (supportedInterfaces, supportedInterfaces.begin()));
  }

  void PAMVisitor::CreateAsmAttributes (const Component& comp,
                                        const Component& asmComp)
  {
    string prefix = comp.name();
    prefix += "_";
    // Differentiate between read-only attributes and attributes
    vector<ReadonlyAttribute>
      readattr_children = comp.ReadonlyAttribute_kind_children();
    IsReadOnlyAttribute predicate;
    NamePrefixer<ReadonlyAttribute> readOnlypred (prefix);
    CloneSequence (boost::make_filter_iterator (predicate,
                                                readattr_children.begin(),
                                                readattr_children.end()),
                   boost::make_filter_iterator (predicate,
                                                readattr_children.end(),
                                                readattr_children.end()),
                   asmComp,
                   readOnlypred);
    NamePrefixer<Attribute> attrPred (prefix);
    vector<Attribute> attr_children = comp.Attribute_kind_children();
    CloneSequence (attr_children.begin(), attr_children.end(), asmComp, attrPred);
  }

  MonolithicImplementation PAMVisitor::GetMonolithicImpl (const Component& comp)
  {
    MonolithicImplementation monolith;
    vector<ComponentImplementations> folders = this->rootFolder_.ComponentImplementations_kind_children();
    vector<ComponentImplementations>::iterator fBegin, fEnd;
    for (boost::tie (fBegin, fEnd) = make_pair (folders.begin(),
                                                folders.end());
         fBegin != fEnd;
         ++fBegin)
      {
        ComponentImplementations folder (*fBegin);
        vector<ComponentImplementationContainer> containers = folder.ComponentImplementationContainer_kind_children();
        vector<ComponentImplementationContainer>::iterator cBegin, cEnd;
        for (boost::tie (cBegin, cEnd) = make_pair (containers.begin(),
                                                    containers.end());
             cBegin != cEnd;
             ++cBegin)
          {
            ComponentImplementationContainer container (*cBegin);
            vector<ComponentImplementation> impls = container.ComponentImplementation_kind_children();
            vector<ComponentImplementation>::iterator iBegin, iEnd;
            for (boost::tie (iBegin, iEnd) = make_pair (impls.begin(),
                                                        impls.end());
                 iBegin != iEnd;
                 ++iBegin)
              {
                ComponentImplementation impl (*iBegin);
                if (Udm::IsDerivedFrom (impl.type(),
                                        MonolithicImplementation::meta))
                  {
                    MonolithicImplementation
                      mimpl (UdmCaster<MonolithicImplementation>()(impl));
                    Component temp (comp);
                    Component type = temp.Archetype();
                    if (string(mimpl.name()) == string (comp.name()))
                      return mimpl;
                    else if (string(mimpl.name()) == string(type.name()))
                      monolith = mimpl;
                  }
              }
          }
      }
    return monolith;
  }

  void PAMVisitor::UpdateAttributes (const ComponentAssembly& container,
                                     const Component& asmInstance,
                                     const set<Component>& clique)
  {
    set<Component>::const_iterator begin, end;
    for (boost::tie (begin, end) = make_pair (clique.begin(), clique.end());
         begin != end;
         ++begin)
      {
        Component instance (*begin);
        Component type = instance.Archetype();
        MonolithicImplementation mimpl = GetMonolithicImpl (instance);
        vector<ReadonlyAttribute>
          attrs = asmInstance.ReadonlyAttribute_kind_children();
        set<ConfigProperty> configProps = mimpl.dstConfigProperty();
        set<ConfigProperty>::iterator pBegin, pEnd;
        for (boost::tie (pBegin, pEnd) = make_pair (configProps.begin(),
                                                    configProps.end());
             pBegin != pEnd;
             ++pBegin)
          {
            Property cProperty = pBegin->dstConfigProperty_end();
            vector<ReadonlyAttribute>::iterator attrIter;
            string attrName = string (type.name()) + "_";
            attrName += cProperty.name();
            NameMatcher<ReadonlyAttribute> propMatcher (attrName);
            attrIter = find_if (attrs.begin(), attrs.end(), propMatcher);
            if (attrIter != attrs.end())
              {
                Property property = Clone (cProperty, container);
                AttributeValue conn = AttributeValue::Create (container);
                conn.srcAttributeValue_end() = *attrIter;
                conn.dstAttributeValue_end() = property;
              }
          }
      }
  }

  bool PAMVisitor::CreateInterfaceDefinitions (const set<Component>& clique)
  {
    set<File> files;
    set<Package> modules;
    set<FileRef, ReferenceSorter<FileRef> > fileRefs;
    vector<ProvidedRequestPort> facets;
    vector<RequiredRequestPort> receptacles;
    vector<OutEventPort> publishers;
    vector<InEventPort> consumers;

    set<Supports, ReferenceSorter<Supports> > supportedInterfaces;
    set<ReadonlyAttribute, NameSorter<ReadonlyAttribute> > readonlyAttributes;
    set<Attribute, NameSorter<Attribute> > attributes;
    set<string> componentTypes;

    // Don't create new interfaces for cliques of size == 1, i.e,
    // isolated components.
    if (clique.size() == 1)
      return false;
    set<Component>::const_iterator cBegin, cEnd;
    for (boost::tie (cBegin, cEnd) = make_pair (clique.begin(),
                                                clique.end());
         cBegin != cEnd;
         ++cBegin)
      {
        Component temp (*cBegin);
        Component comp = temp.Archetype();
        // Sort the names to eliminate spurious physical assembly types
        componentTypes.insert (comp.name());
        Package package = comp.Package_parent();
        modules.insert (comp.Package_parent());
        File file = package.File_parent();
        if (file == Udm::null)
          {
            Package parent = package.Package_parent();
            file = parent.File_parent();
            while (file == Udm::null)
              {
                parent = parent.Package_parent();
                file = parent.File_parent();
              }
          }
        files.insert (file);
        vector<FileRef> refs = file.FileRef_kind_children();
        copy (refs.begin(), refs.end(),
              inserter (fileRefs, fileRefs.begin()));
        this->CollectPorts (comp, facets, receptacles, publishers, consumers,
                            supportedInterfaces, readonlyAttributes,
                            attributes);
      }
    stringstream ss;
    copy (componentTypes.begin(), componentTypes.end(),
          ostream_iterator<string> (ss, "_"));
    this->asmName_ = ss.str();
    // Remove the trailing underscore
    this->asmName_.erase (this->asmName_.end() - 1);
    AsmInfo asmInfo;
    AsmInfoMap::iterator found = this->createdAsms_.find (this->asmName_);
    if (found != this->createdAsms_.end())
      {
        asmInfo = found->second;
        this->asmComp_ = asmInfo.asmComp;
        this->asmHome_ = asmInfo.asmHome;
        this->asmPackage_ = asmInfo.asmPackage;
        return false;
      }
    InterfaceDefinitions folder = (*files.begin()).parent();
    // Create File
    File asmFile = File::Create (folder);
    asmFile.name() = this->asmName_;
    // Populate File References
    CloneSequence (fileRefs.begin(), fileRefs.end(), asmFile);
    // Create Package
    this->asmPackage_ = Package::Create (asmFile);
    this->asmPackage_.name() = (*modules.begin()).name();
    // Create Component
    this->asmComp_ = Component::Create (this->asmPackage_);
    this->asmComp_.name() = this->asmName_;
    // Create ports
    CloneSequence (facets.begin(), facets.end(), this->asmComp_);
    CloneSequence (receptacles.begin(), receptacles.end(), this->asmComp_);
    CloneSequence (publishers.begin(), publishers.end(), this->asmComp_);
    CloneSequence (consumers.begin(), consumers.end(), this->asmComp_);
    CloneSequence (readonlyAttributes.begin(),
                   readonlyAttributes.end(),
                   this->asmComp_);
    CloneSequence (attributes.begin(), attributes.end(), this->asmComp_);
    // Create attributes in the physical assembly to match attributes of
    // each component instance that is merged to form the physical assembly
    for (boost::tie (cBegin, cEnd) = make_pair (clique.begin(),
                                                clique.end());
         cBegin != cEnd;
         ++cBegin)
      {
        Component temp (*cBegin);
        Component comp = temp.Archetype();
        this->CreateAsmAttributes (comp, this->asmComp_);
      }

    // Create Supported Interfaces
    CloneSequence (supportedInterfaces.begin(),
                   supportedInterfaces.end(),
                   this->asmComp_);
    // Create Component Home
    this->asmHome_ = ComponentFactory::Create (this->asmPackage_);
    this->asmHome_.name() = this->asmName_ + "Home";
    ManagesComponent
      connection = ManagesComponent::Create (this->asmPackage_);
    connection.srcManagesComponent_end() = this->asmHome_;
    connection.dstManagesComponent_end() = this->asmComp_;
    asmInfo.asmComp = this->asmComp_;
    asmInfo.asmHome = this->asmHome_;
    asmInfo.asmPackage = this->asmPackage_;
    this->createdAsms_[this->asmName_] = asmInfo;
    return true;
  }

  void PAMVisitor::CreateImplementationArtifacts (const set<Component>& clique)
  {
    ImplementationArtifacts folder
      = ImplementationArtifacts::Create (this->rootFolder_);
    folder.name() = string (this->asmComp_.name()) + "_Artifacts";

    ArtifactContainer container = ArtifactContainer::Create (folder);
    container.name() = this->asmComp_.name();

    ImplementationArtifact stub
      = this->CreateImplementationArtifact (container, "_stub");
    ImplementationArtifact svnt
      = this->CreateImplementationArtifact (container, "_svnt");
    ImplementationArtifact exec
      = this->CreateImplementationArtifact (container, "_exec");

    Property svntEntryPoint = this->CreateEntryPoint (container, true);
    this->CreateArtifactExecParameter (container, svnt, svntEntryPoint);

    Property execEntryPoint = this->CreateEntryPoint (container, false);
    this->CreateArtifactExecParameter (container, exec, execEntryPoint);

    this->CreateArtifactDependency (container, svnt, stub);
    this->CreateArtifactDependency (container, exec, stub);
    this->CreateArtifactDependency (container, exec, svnt);
    this->CreateMonolithicImplementation (stub, svnt, exec);
  }


  ImplementationArtifact PAMVisitor::CreateImplementationArtifact (const ArtifactContainer& container, const string& suffix)
  {
    string name = this->asmComp_.name();
    name += suffix;
    ImplementationArtifact
      artifact = ImplementationArtifact::Create (container);
    artifact.name() = name;
    artifact.UUID() = Utils::CreateUuid();
    artifact.location() = this->asmComp_.name();
    return artifact;
  }

  Property PAMVisitor::CreateEntryPoint (const ArtifactContainer& container,
                                         bool servant)
  {
    Property entryPoint = Property::Create (container);
    entryPoint.name() = "entryPoint";
    string entryPointVal ("create_");
    entryPointVal += this->asmPackage_.name();
    entryPointVal += "_";
    entryPointVal += this->asmHome_.name();
    entryPointVal += servant ? "_Servant": "_Impl";
    entryPoint.DataValue() = entryPointVal;
    DataType stringType = DataType::Create (entryPoint);
    stringType.ref() = this->stringType_;
    stringType.name() = "String";
    entryPoint.DataType_child() = stringType;
    return entryPoint;
  }

  void PAMVisitor::CreateArtifactDependency (const ArtifactContainer& container,
                                             const ImplementationArtifact& source,
                                             const ImplementationArtifact& target)
  {
    ArtifactDependency dependency = ArtifactDependency::Create (container);
    dependency.srcArtifactDependency_end() = source;
    dependency.dstArtifactDependency_end() = target;
  }

  void PAMVisitor::CreateArtifactExecParameter (const ArtifactContainer& container, const ImplementationArtifact& source, const Property& target)
  {
    ArtifactExecParameter execParameter
      = ArtifactExecParameter::Create (container);
    execParameter.srcArtifactExecParameter_end() = source;
    execParameter.dstArtifactExecParameter_end() = target;
  }


  void PAMVisitor::CreatePrimaryArtifact (const ComponentImplementationContainer& container,
                                          const MonolithicImplementation& source,
                                          const ImplementationArtifact& target)
  {
    ImplementationArtifactReference ref = ImplementationArtifactReference::Create (container);
    ref.ref() = target;
    ref.name() = target.name();
    MonolithprimaryArtifact primaryArtifact
      = MonolithprimaryArtifact::Create (container);
    primaryArtifact.srcMonolithprimaryArtifact_end() = source;
    primaryArtifact.dstMonolithprimaryArtifact_end() = ref;
  }

  void PAMVisitor::CreateImplements (const ComponentImplementationContainer& container,
                                     const MonolithicImplementation& source)
  {
    ComponentRef ref = ComponentRef::Create (container);
    ref.ref() = this->asmComp_;
    ref.name() = this->asmComp_.name();
    Implements implements = Implements::Create (container);
    implements.srcImplements_end() = source;
    implements.dstImplements_end() = ref;
  }

  void PAMVisitor::CreateMonolithicImplementation (const ImplementationArtifact& stub,
                                                   const ImplementationArtifact& svnt,
                                                   const ImplementationArtifact& exec)
  {
    ComponentImplementations folder
      = ComponentImplementations::Create (this->rootFolder_);
    folder.name()  = string (this->asmComp_.name()) + "_Implementations";
    ComponentImplementationContainer container
      = ComponentImplementationContainer::Create (folder);
    container.name() = string (this->asmComp_.name());

    MonolithicImplementation asmMonolith = MonolithicImplementation::Create (container);
    asmMonolith.name() = this->asmComp_.name();
    asmMonolith.UUID() = Utils::CreateUuid();
    this->CreatePrimaryArtifact (container, asmMonolith, stub);
    this->CreatePrimaryArtifact (container, asmMonolith, svnt);
    this->CreatePrimaryArtifact (container, asmMonolith, exec);
    this->CreateImplements (container, asmMonolith);
  }

  void PAMVisitor::CreatePhysicalAssemblies (set<Component>& candidateTypes)
  {
    if (candidateTypes.empty())
      return;
    CliqueSets cliqueSets;
    this->GenerateCliqueSets (candidateTypes, cliqueSets);
    CliqueSets::const_iterator begin, end;
    // Use the counter to uniquify the names of the instances
    this->asmInstanceCounter_ = 0;
    for (boost::tie (begin, end) = make_pair (cliqueSets.begin(),
                                              cliqueSets.end());
         begin != end;
         ++begin, ++this->asmInstanceCounter_)
      {
        set<Component> clique (begin->begin(), begin->end());
        if (this->CreateInterfaceDefinitions(clique))
          {
            this->CreateImplementationArtifacts(clique);
          }
        this->UpdateAssembly (clique);
      }
    this->cliqueSets_.insert (cliqueSets.begin(), cliqueSets.end());
  }

  void PAMVisitor::CreateCandidateComponents (set<CollocationGroup_Members_Base>& cgmembers,
                                              set<Component>& candidateTypes,
                                              set<Component>& candidateInstances)
  {
    for (set<CollocationGroup_Members_Base>::iterator iter = cgmembers.begin();
         iter != cgmembers.end();
         ++iter)
      {
        CollocationGroup_Members_Base cgmem (*iter);
        if (Udm::IsDerivedFrom (cgmem.type(), ComponentRef::meta))
          {
            ComponentRef compRef = ComponentRef::Cast (cgmem);
            Component comp = compRef.ref();
            if (comp.isInstance())
              {
                Component type = comp.Archetype();
                candidateTypes.insert (type);
                candidateInstances.insert (comp);
                this->candidateMap_.insert(make_pair(type, comp));
              }
            else
              {
                throw
                  udm_exception (string ("Invalid reference ")
                                 + string (compRef.name())
                                 + string (" to non-instance ")
                                 + string(comp.name()));
              }
          }
      }
  }

  void PAMVisitor::GenerateCliqueSets (set<Component>& candidateTypes,
                                       CliqueSets& cliqueSets)
  {
    typedef set<Component>::iterator CompIter;
    for (CandidateMap::size_type count = 1;
         !this->candidateMap_.empty() && !candidateTypes.empty();
         ++count)
      {
        set<Component> sameCountTypes;
        CompIter tBegin, tEnd;
        for (boost::tie (tBegin, tEnd)
               = make_pair (candidateTypes.begin(),
                            candidateTypes.end());
             tBegin != tEnd;
             ++tBegin)
          {
            if (this->candidateMap_.count (*tBegin) == count)
              sameCountTypes.insert (*tBegin);
          }
        for (boost::tie (tBegin, tEnd)
               = make_pair (sameCountTypes.begin(),
                            sameCountTypes.end());
             tBegin != tEnd;
             ++tBegin)
          {
            candidateTypes.erase (remove (candidateTypes.begin(),
                                          candidateTypes.end(),
                                          *tBegin),
                                  candidateTypes.end());
          }
        set<Component> candidateComps;
        for (CandidateMap::size_type i = 0; i < count; ++i)
          {
            for (boost::tie (tBegin, tEnd)
                   = make_pair (sameCountTypes.begin(),
                                sameCountTypes.end());
                 tBegin != tEnd;
                 ++tBegin)
              {
                CandidateMap::iterator vBegin =
                  this->candidateMap_.lower_bound (*tBegin);
                if (vBegin == this->candidateMap_.end())
                  throw udm_exception ("Candidate type not found in map");
                candidateComps.insert (vBegin->second);
                this->candidateMap_.erase (vBegin);
              }
          }
        this->CalculateCliques (candidateComps, cliqueSets);
      }
  }

  void PAMVisitor::CalculateCliques (set<Component>& candidateInstances,
                                     CliqueSets& cliqueSets)
  {
    if (candidateInstances.size() == 1)
      {
        cliqueSets.insert (candidateInstances);
        return;
      }
    typedef set<Component>::iterator CompIter;
    CompIter outerBegin, outerEnd;
    Graph g (candidateInstances.size());
    size_t index = 0;
    // Fill the graph with component information
    for (boost::tie (outerBegin, outerEnd)
           = make_pair (candidateInstances.begin(),
                        candidateInstances.end());
         outerBegin != outerEnd;
         ++outerBegin, ++index)
      {
        Vertex v = vertex (index, g);
        g[v].component = *outerBegin;
        g[v].name = outerBegin->name();
      }
    boost::tie (outerBegin, outerEnd) = make_pair (candidateInstances.begin(),
                                                   candidateInstances.end());
    PAMPredicate<Component> pred (candidateInstances);
    for (size_t i = 0; outerBegin != outerEnd; ++outerBegin, ++i)
      {
        CompIter innerBegin = candidateInstances.begin();
        CompIter innerEnd = candidateInstances.end();
        // Move to where outer is currently pointing
        advance (innerBegin, distance (innerBegin, outerBegin));
        // Move forward to enable comparison
        advance (innerBegin, 1);
        for (size_t j = i+1;innerBegin != innerEnd; ++innerBegin, ++j)
          {
            if (pred (*outerBegin, *innerBegin))
              {
                Vertex source = vertex (i, g);
                Vertex target = vertex (j, g);
                add_edge (source, target, g);
              }
          }
      }

    while (num_vertices (g))
      {
        set<Vertex> gVertices;
        graph_traits<Graph>::vertex_iterator begin, end;
        boost::tie (begin, end) = vertices (g);
        copy (begin, end, inserter (gVertices, gVertices.begin()));

        set<Vertex> clique;
        set<Vertex> processedVertices;
        try
          {
            MaximalClique (clique, gVertices, processedVertices, g);
          }
        catch (set<Vertex>& myClique)
          {
            typedef set<Vertex>::iterator CompVertexIter;
            CompVertexIter cBegin, cEnd, cNext;
            boost::tie (cBegin, cEnd) = make_pair (myClique.begin(),
                                                   myClique.end());
            set<Component> cliqueComps;
            for (; cBegin != cEnd; ++cBegin)
              {
                cliqueComps.insert (g[*cBegin].component);
              }
            cliqueSets.insert (cliqueComps);
            boost::tie (cBegin, cEnd)
              = make_pair (myClique.begin(), myClique.end());
            for (cNext = cBegin; cBegin != cEnd; cBegin = cNext)
              {
                ++cNext;
                remove_vertex (*cBegin, g);
              }
          }
      }
  }


  // Algorithm call: IK_*( 0, V[G], 0).
  //
  // IK_*(R, P, X)
  // 1: if P = 0 and X = 0 then
  // 2:   Report R as a maximal clique
  // 3: else
  // 4:   Let up be the pivot vertex (maximum degree vertex) chosen from P U X.
  // 5:   Assume P = {u1,u2, ...,uk}
  // 6:   for i 1 to k do
  // 7:       if ui is not a neighbor of up then
  // 8:          P = P - {ui}
  // 9:          Rnew = R U {ui}
  // 10:         Pnew = P () N[ui]
  // 11:         Xnew = X () N[ui]
  // 12:         IK_*(Rnew, Pnew, Xnew)
  // 13:         X = X U {ui}

  void
  PAMVisitor::MaximalClique (set<Vertex>& clique,
                             set<Vertex>& unprocessedVertices,
                             set<Vertex>& processedVertices,
                             Graph& g)
  {
    if (unprocessedVertices.empty() && processedVertices.empty())
      {
        //         set<Vertex>::iterator cBegin, cEnd;
        //         boost::tie (cBegin, cEnd) = make_pair (clique.begin(), clique.end());
        //         if (cBegin != cEnd)
        //           {
        //             cout << "Reporting clique (";
        //             cout << g[*cBegin].name;
        //             ++cBegin;
        //             while (cBegin != cEnd)
        //               {
        //                 cout << "," << g[*cBegin].name;
        //                 ++cBegin;
        //               }
        //             cout << ")\n";
        //           }
        throw clique;
      }
    else
      {
        set<Vertex> combinedVertices;
        set_union (unprocessedVertices.begin(), unprocessedVertices.end(),
                   processedVertices.begin(), processedVertices.end(),
                   inserter (combinedVertices, combinedVertices.begin()));
        DegreeSorter<Graph> dsort (g);
        set<Vertex>::iterator max_ele = max_element (combinedVertices.begin(),
                                                     combinedVertices.end(),
                                                     dsort);
        Vertex maxVertex = *max_ele;
        set<Vertex>::iterator pbegin = unprocessedVertices.begin();
        set<Vertex>::iterator pend = unprocessedVertices.end();
        for (; pbegin != pend; ++pbegin)
          {
            Vertex vertex = *pbegin;
            if (!is_adjacent (g, vertex, maxVertex))
              {
                set<Vertex> tempUnprocessedVertices;
                remove_copy (unprocessedVertices.begin(),
                             unprocessedVertices.end(),
                             inserter (tempUnprocessedVertices,
                                       tempUnprocessedVertices.begin()),
                             vertex);

                set<Vertex> newClique (clique.begin(), clique.end());
                newClique.insert (vertex);

                set<Vertex> adjacencySet;
                AdjIter adjBegin, adjEnd;
                boost::tie (adjBegin, adjEnd) = adjacent_vertices (vertex, g);
                copy (adjBegin,
                      adjEnd,
                      inserter (adjacencySet, adjacencySet.begin()));

                set<Vertex> newUnprocessedVertices;
                set_intersection (tempUnprocessedVertices.begin(),
                                  tempUnprocessedVertices.end(),
                                  adjacencySet.begin(), adjacencySet.end(),
                                  inserter (newUnprocessedVertices,
                                            newUnprocessedVertices.begin()));

                set<Vertex> newProcessedVertices;
                set_intersection (processedVertices.begin(),
                                  processedVertices.end(),
                                  adjacencySet.begin(), adjacencySet.end(),
                                  inserter (newProcessedVertices,
                                            newProcessedVertices.begin()));

                MaximalClique (newClique, newUnprocessedVertices,
                               newProcessedVertices, g);
                processedVertices.insert (vertex);
              }
          }
      }
  }

  void PAMVisitor::Visit_ComponentImplementations (const ComponentImplementations& cimpls)
  {
    set<ComponentImplementationContainer>
      cics = cimpls.ComponentImplementationContainer_kind_children();
    for_each (cics.begin(), cics.end(),
              bind (&ComponentImplementationContainer::Accept, _1, ref (*this)));
  }

  void PAMVisitor::Visit_ComponentImplementationContainer (const ComponentImplementationContainer& cic)
  {
    set<ComponentAssembly> asms = cic.ComponentAssembly_kind_children();
    for (set<ComponentAssembly>::iterator iter = asms.begin();
         iter != asms.end();
         ++iter)
      {
        UdmUtil::copy_assoc_map dummy;
        ComponentAssembly cic = *iter;
        ComponentAssembly ciccopy = ComponentAssembly::Create (cic.parent());
        UdmUtil::CopyObjectHierarchy (cic.__impl(),
                                      ciccopy.__impl(),
                                      cic.__impl()->__getdn(),
                                      dummy);
      }
  }
}
