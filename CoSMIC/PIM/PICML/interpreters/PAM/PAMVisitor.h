// $Id$

#ifndef PAM_VISITOR_H
#define PAM_VISITOR_H

#include "PAM/PAM_Export.h"
#include "PICML/PICML.h"

// Utility includes
#include "Utils/Utils.h"
#include "UdmUtil.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
#include <utility>
#include <exception>
#include <memory>
#include <map>

#include <boost/tuple/tuple.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/iterator/filter_iterator.hpp>

namespace PICML
{
  using std::set;
  using std::vector;
  using std::string;
  using std::map;
  using std::multimap;

  using boost::adjacency_list;
  using boost::graph_traits;
  using boost::vecS;
  using boost::listS;
  using boost::undirectedS;
  using boost::filter_iterator;

  using std::cout;
  using std::endl;
  using std::list;
  using std::remove_copy;
  using std::copy;
  using std::transform;
  using std::find;
  using std::find_if;
  using std::set_intersection;
  using std::set_union;
  using std::set_difference;
  using std::binary_function;
  using std::exception;

  struct VertexInfo
  {
    Component component;
    string name;
  };

  typedef adjacency_list<listS, listS, undirectedS, VertexInfo> Graph;
  typedef graph_traits<Graph>::vertex_descriptor Vertex;
  //typedef graph_traits<Graph>::edge_descriptor Edge;
  typedef graph_traits<Graph>::vertex_iterator VertexIter;
  typedef graph_traits<Graph>::edge_iterator EdgeIter;
  typedef graph_traits<Graph>::adjacency_iterator AdjIter;

  typedef set<Component> Clique;
  typedef set<Clique> CliqueSets;
  typedef set<CliqueSets> SetOfCliqueSets;

  typedef vector<ProvidedRequestPort> FacetSet;
  typedef vector<RequiredRequestPort> ReceptacleSet;
  typedef vector<OutEventPort> PublisherSet;
  typedef vector<InEventPort> ConsumerSet;

  typedef map<Component, FacetSet> FacetMap;
  typedef map<Component, ReceptacleSet> ReceptacleMap;
  typedef map<Component, PublisherSet> PublisherMap;
  typedef map<Component, ConsumerSet> ConsumerMap;

  template <class Graph, class Vertex = graph_traits<Graph>::vertex_descriptor>
  struct DegreeSorter
    : public binary_function<Vertex,Vertex,bool>
  {
    DegreeSorter (Graph& g)
      : g_ (g)
    {}

    bool operator()(const Vertex& lhs, const Vertex& rhs)
    {
      return (degree (lhs, g_) < degree (rhs, g_));
    }
  private:
    Graph& g_;
  };

  template <class T>
  struct NameMatcher
    : public unary_function<T,bool>
  {
    NameMatcher (string name)
      : name_ (name)
    {}

    bool operator()(const T& ele)
    {
      return name_ == string(ele.name());
    }
  private:
    string name_;
  };

  struct AssemblyParent
    : public unary_function<Component, ComponentAssembly>
  {
    ComponentAssembly operator() (const Component& comp)
    {
      ComponentAssembly assembly = comp.ComponentAssembly_parent();
      if (assembly == Udm::null)
        {
          string message = comp.getPath (".", false, true, "name", true);
          message += "'s assembly parent is null";
          throw udm_exception (message.c_str());
        }
      return assembly;
    }
  };

  template <class T>
  struct UdmObjectDeleter
    : public unary_function<T, void>
  {
    void operator() (const T& element)
    {
      if (element != Udm::null)
        element.parent() = 0;
    }
  };

  template <class T>
  struct NameSorter
    : public binary_function<T,T,bool>
  {
    bool operator()(const T& lhs, const T& rhs)
    {
      string left (lhs.name());
      string right (rhs.name());
      return left < right;
    }
  };

  template <class T>
  struct NamePrefixer
    : public unary_function<T, T>
  {
    NamePrefixer (const string& prefix)
      : prefix_ (prefix)
    {}

    T operator() (const T& element)
    {
      string name = prefix_ + string(element.name());
      element.name() = name;
      return element;
    }
  private:
    string prefix_;
  };

  template <class T>
  struct UdmCaster
    : public unary_function<Udm::Object, T>
  {
    T operator() (const Udm::Object& element)
    {
      return T::Cast (element);
    }
  };

  template <class T>
  struct ReferenceSorter
    : public binary_function<T,T,bool>
  {
    bool operator()(const T& lhs, const T& rhs) const
    {
      Udm::Object left (lhs.ref());
      Udm::Object right (rhs.ref());
      return left < right;
    }
  };

  template <class T, class U>
  struct Referred
    : public unary_function<bool, U>
  {
    Referred (const T& element)
      : element_ (element)
    {}

    bool operator() (const U& reference)
    {
      return element_ == reference.ref();
    }
  private:
    const T& element_;
  };

  struct IsReadOnlyAttribute
  {
    bool operator() (const ReadonlyAttribute& attr)
    {
      return Udm::IsDerivedFrom (attr.type(), ReadonlyAttribute::meta)
        && !Udm::IsDerivedFrom (attr.type(), Attribute::meta);
    }
  };

  struct IsEventEmitter
  {
    bool operator() (const OutEventPort& eventSource)
    {
      return eventSource.single_destination();
    }
  };

  template <class Container, class Comp, class ConnColl, class Conn,
            class PortEnd, class PortColl, class Parent, class PortType>
  void UpdatePortConnection (const Container& container,
                             const Comp& instance,
                             const set<Comp>& clique,
                             ConnColl (Container::*connColl)() const,
                             PortEnd (Conn::*portEnd)() const,
                             PortColl (Comp::*portColl)() const,
                             Parent (PortType::*parent)() const)
  {
    vector<Conn> connections = (container.*connColl)();
    vector<Conn>::iterator iBegin, iEnd;
    for (boost::tie (iBegin, iEnd) = make_pair (connections.begin(),
                                                connections.end());
         iBegin != iEnd;
         ++iBegin)
      {
        Conn conn = *iBegin;
        PortType port = (conn.*portEnd)();
        Comp portComp = Comp::Cast ((port.*parent)());
        set<Comp>::const_iterator portCompIter;
        portCompIter = find (clique.begin(), clique.end(), portComp);
        if (portCompIter != clique.end())
          {
            vector<PortType> ports = (instance.*portColl)();
            vector<PortType>::iterator portIter;
            NameMatcher<PortType> matcher (port.name());
            portIter = find_if (ports.begin(), ports.end(), matcher);
            if (portIter != ports.end())
              {
                PortType endPort = *portIter;
                (conn.*portEnd)() = endPort;
              }
          }
      }
  }

  template <class Container, class Comp, class ConnColl,
            class Conn, class CompEnd>
  void UpdateConnection (const Container& container,
                         const Comp& instance,
                         const set<Comp>& clique,
                         ConnColl (Container::*connColl)() const,
                         CompEnd (Conn::*compEnd)() const)
  {
    vector<Conn> connections = (container.*connColl)();
    vector<Conn>::iterator iBegin, iEnd;
    for (boost::tie (iBegin, iEnd) = make_pair (connections.begin(),
                                                connections.end());
         iBegin != iEnd;
         ++iBegin)
      {
        Conn conn = *iBegin;
        Comp comp;
        Udm::Object end = (conn.*compEnd)();
        if (Udm::IsDerivedFrom (end.type(), Component::meta))
          {
            comp = Comp::Cast(end);
          }
        set<Comp>::const_iterator compIter;
        compIter = find (clique.begin(), clique.end(), comp);
        if (compIter != clique.end())
          {
            (conn.*compEnd)() = instance;
          }
      }
  }

  template <class T>
  struct PAMPredicate
    : public binary_function<T,T,bool>
  {
    PAMPredicate (const set<T>& components)
    {
      for (set<T>::const_iterator iter = components.begin();
           iter != components.end();
           ++iter)
        {
          T comp (*iter);
          FacetSet facets = comp.ProvidedRequestPort_kind_children();
          sort (facets.begin(), facets.end(),
                NameSorter<ProvidedRequestPort>());
          facetMap_.insert (make_pair (comp, facets));

          ReceptacleSet receptacles = comp.RequiredRequestPort_kind_children();
          sort (receptacles.begin(), receptacles.end(),
                NameSorter<RequiredRequestPort>());
          receptacleMap_.insert (make_pair (comp, receptacles));

          PublisherSet publishers = comp.OutEventPort_kind_children();
          sort (publishers.begin(), publishers.end(),
                NameSorter<OutEventPort>());
          publisherMap_.insert (make_pair (comp, publishers));

          ConsumerSet consumers = comp.InEventPort_kind_children();
          sort (consumers.begin(), consumers.end(),
                NameSorter<InEventPort>());
          consumerMap_.insert (make_pair (comp, consumers));
        }
    }

    template <class PortMap, class Key>
    bool intersects (PortMap& container, const Key& lhs, const Key& rhs)
    {
      typedef typename PortMap::value_type::second_type::value_type PortType;
      vector<PortType> intersectionSet;
      set_intersection (container[lhs].begin(), container[lhs].end(),
                        container[rhs].begin(), container[rhs].end(),
                        back_inserter (intersectionSet),
                        NameSorter<PortType>());
      return !intersectionSet.empty();
    }

    bool operator() (const T& lhs, const T& rhs)
    {
      if (intersects (facetMap_, lhs, rhs)
          || intersects (receptacleMap_, lhs, rhs)
          || intersects (publisherMap_, lhs, rhs)
          || intersects (consumerMap_, lhs, rhs))
        return false;

      // Check for clash between emitters and receptacles
      IsEventEmitter predicate;
      vector<MgaObject> mgaObjects;
      set_intersection (boost::make_filter_iterator (predicate,
                                                     publisherMap_[lhs].begin(),
                                                     publisherMap_[lhs].end()),
                        boost::make_filter_iterator (predicate,
                                                     publisherMap_[lhs].end(),
                                                     publisherMap_[lhs].end()),
                        receptacleMap_[rhs].begin(), receptacleMap_[rhs].end(),
                        back_inserter (mgaObjects),
                        NameSorter<MgaObject>());
      set_intersection (boost::make_filter_iterator (predicate,
                                                     publisherMap_[rhs].begin(),
                                                     publisherMap_[rhs].end()),
                        boost::make_filter_iterator (predicate,
                                                     publisherMap_[rhs].end(),
                                                     publisherMap_[rhs].end()),
                        receptacleMap_[lhs].begin(), receptacleMap_[lhs].end(),
                        back_inserter (mgaObjects),
                        NameSorter<MgaObject>());
      return mgaObjects.empty();
    }

  private:
    FacetMap facetMap_;
    ReceptacleMap receptacleMap_;
    PublisherMap publisherMap_;
    ConsumerMap consumerMap_;
  };

  template <class T>
  struct identity
    : public unary_function<T, T>
  {
    const T& operator() (const T& element) const
    {
      return element;
    }
  };

  template <class T, class U>
  T Clone (const T& old, const U& parent = old.parent())
  {
    UdmUtil::copy_assoc_map dummy;
    T newcopy = T::Create (parent);
    UdmUtil::CopyObjectHierarchy (old.__impl(),
                                  newcopy.__impl(),
                                  old.__impl()->__getdn(),
                                  dummy);
    return newcopy;
  }

  template <class InputIterator, class U>
  void CloneSequence (InputIterator first, InputIterator last, const U& parent)
  {
    for (; first != last; ++first)
      {
        Clone (*first, parent);
      }
  }

  template <class InputIterator, class U, class Pred>
  void CloneSequence (InputIterator first, InputIterator last, const U& parent,
                      Pred pred)
  {
    for (; first != last; ++first)
      {
        pred(Clone (*first, parent));
      }
  }

  class PAM_Export PAMVisitor: public Visitor
  {
  public:
    PAMVisitor (const Udm::Object& focusObject,
                const set<Udm::Object>& selectedObjects);
    ~PAMVisitor();

    virtual void Visit_RootFolder(const RootFolder&);
    virtual void Visit_DeploymentPlans (const DeploymentPlans& dps);
    virtual void Visit_DeploymentPlan (const DeploymentPlan& plan);
    virtual void Visit_CollocationGroup (const CollocationGroup& cg);
    virtual void Visit_ComponentImplementations (const ComponentImplementations&);
    virtual void Visit_ComponentImplementationContainer(const ComponentImplementationContainer& cic);

  private:
    typedef set<Supports, ReferenceSorter<Supports> > SupportedInterfaces;
    typedef set<ReadonlyAttribute, NameSorter<ReadonlyAttribute> > ReadonlyAttributes;
    typedef set<Attribute, NameSorter<Attribute> > Attributes;
    MonolithicImplementation GetMonolithicImpl (const Component& comp);
    string CreateCliqueString (const set<Component>& clique);
    void CreatePhysicalAssemblies (set<Component>& candidateInstances);
    void UpdateAttributes (const ComponentAssembly& container,
                           const Component& asmInstance,
                           const set<Component>& clique);
    void CreateAsmAttributes (const Component& comp,
                              const Component& asmComp);
    bool CreateInterfaceDefinitions (const set<Component>& clique);
    void CreateImplementationArtifacts (const set<Component>& clique);
    void UpdateAssembly (const set<Component>& clique);
    void UpdateDeploymentPlans (const set<DeploymentPlan>& plans);
    void CloneDeploymentPlanElements(const DeploymentPlan& plan);
    void ConnectCgNodeRef(const CollocationGroup& cg);
    void CleanUpAssemblies ();
    void MergeDeploymentPlans (set<DeploymentPlan>& plans);
    void CollectPorts (const Component& comp,
                       vector<ProvidedRequestPort>& facets,
                       vector<RequiredRequestPort>& receptacles,
                       vector<OutEventPort>& publishers,
                       vector<InEventPort>& consumers,
                       SupportedInterfaces& supportedInterfaces,
                       ReadonlyAttributes& readonlyAttributes,
                       Attributes& attributes);
    ImplementationArtifact CreateImplementationArtifact (const ArtifactContainer& container, const string& suffix);
    Property CreateEntryPoint (const ArtifactContainer& container,
                               bool servant);
    void CreateArtifactDependency (const ArtifactContainer& container,
                                   const ImplementationArtifact& source,
                                   const ImplementationArtifact& target);
    void CreateArtifactExecParameter (const ArtifactContainer& container,
                                      const ImplementationArtifact& source,
                                      const Property& target);

    void CreatePrimaryArtifact (const ComponentImplementationContainer& container,
                                const MonolithicImplementation& source,
                                const ImplementationArtifact& target);
    void CreateImplements (const ComponentImplementationContainer& container,
                           const MonolithicImplementation& source);
    void CreateMonolithicImplementation (const ImplementationArtifact& stub,
                                         const ImplementationArtifact& svnt,
                                         const ImplementationArtifact& exec);
    void CreateCandidateComponents (set<CollocationGroup_Members_Base>& cgmembers,
                                    set<Component>& candidateTypes,
                                    set<Component>& candidateInstances);
    void CalculateCliques (set<Component>& candidateInstances,
                           CliqueSets& cliqueSets);
    void MaximalClique (set<Vertex>& clique,
                        set<Vertex>& unprocessedVertices,
                        set<Vertex>& processedVertices,
                        Graph& g);
  private:
    Udm::Object         focusObject_;
    set<Udm::Object>    selectedObjects_;
    RootFolder          rootFolder_;
    String              stringType_;
    Boolean             booleanType_;
    LongInteger         longType_;
    ShortInteger        shortType_;
    DeploymentPlan      asmPlan_;
    CollocationGroup    asmCg_;
    CliqueSets          cliqueSets_;
    struct AsmInfo
    {
      Component         asmComp;
      ComponentFactory  asmHome;
      Package           asmPackage;
    };
    typedef map<string, AsmInfo> AsmInfoMap;
    AsmInfoMap          createdAsms_;
    typedef map<Component, Component> CliqueMap;
    CliqueMap           cliqueMap_;
    string              asmName_;
    Component           asmComp_;
    Component           asmInstance_;
    size_t              asmInstanceCounter_;
    ComponentFactory    asmHome_;
    Package             asmPackage_;
  };
}

#endif /* PAM_VISITOR_H */
