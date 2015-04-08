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
  using std::max;

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
  using std::remove;
  using std::copy;
  using std::transform;
  using std::find;
  using std::find_if;
  using std::set_intersection;
  using std::set_union;
  using std::set_difference;
  using std::binary_function;
  using std::exception;

  template<class T>
  struct VertexInfo
  {
    T component;
    string name;
  };

  typedef adjacency_list<listS, listS, undirectedS, VertexInfo<Component> > ComponentGraph;

//  typedef adjacency_list<listS, listS, undirectedS, VertexInfo<RealTimeConfiguration> > RTConfigGraph;

  typedef set<set<Component> > CompCliques;
//   typedef set<set<RealTimeConfiguration> > RTConfigCliques;

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

  template <class Graph, class Vertex>
  void
  MaximalClique (set<Vertex>& clique,
                 set<Vertex>& unprocessedVertices,
                 set<Vertex>& processedVertices,
                 Graph& g)
  {
    typedef graph_traits<Graph>::vertex_descriptor Vertex;
    typedef graph_traits<Graph>::vertex_iterator VertexIter;
    typedef graph_traits<Graph>::edge_iterator EdgeIter;
    typedef graph_traits<Graph>::adjacency_iterator AdjIter;
    if (unprocessedVertices.empty() && processedVertices.empty())
      {
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

  template <class T, class Graph, class Pred>
  void EnumerateCliques (set<T>& candidateInstances,
                         set<set<T> >& cliqueSets,
                         Pred pred, Graph& g)
  {
    typedef graph_traits<Graph>::vertex_descriptor Vertex;
    typedef graph_traits<Graph>::vertex_iterator VertexIter;
    typedef graph_traits<Graph>::edge_iterator EdgeIter;
    typedef graph_traits<Graph>::adjacency_iterator AdjIter;

    if (candidateInstances.size() == 1)
      {
        cliqueSets.insert (candidateInstances);
        return;
      }
    typedef set<T>::iterator CompIter;
    CompIter outerBegin, outerEnd;
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
            set<T> cliqueComps;
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

  template <class T>
  struct AssemblyParent
    : public unary_function<T, ComponentAssembly>
  {
    ComponentAssembly operator() (const T& comp)
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

//   struct BandSorter
//     : public binary_function<PriorityBands, PriorityBands, bool>
//   {
//     bool operator() (const PriorityBands& lhs, const PriorityBands& rhs) const
//     {
//       short llow = static_cast<short>(lhs.low());
//       short rlow = static_cast<short>(rhs.low());
//       return llow < rlow;
//     }
//   };

//   struct LaneSorter
//     : public binary_function<Lane, Lane, bool>
//   {
//     bool operator() (const Lane& lhs, const Lane& rhs) const
//     {
//       short lpriority = static_cast<short>(lhs.lane_priority());
//       short rpriority = static_cast<short>(rhs.lane_priority());
//       return lpriority < rpriority;
//     }
//   };
//
//   RealTimeConfiguration GetRTConfig (const Component& comp)
//   {
//     RealTimeConfiguration rtConfig;
//     set<ComponentQoS> qosConns = comp.dstComponentQoS();
//     set<ComponentQoS>::iterator qBegin, qEnd;
//     for (boost::tie (qBegin, qEnd)
//            = make_pair (qosConns.begin(),
//                         qosConns.end());
//          qBegin != qEnd;
//          ++qBegin)
//       {
//         ComponentQoS cQos = *qBegin;
//         ComponentQoSCharacteristic qosChar = cQos.dstComponentQoS_end();
//         if (Udm::IsDerivedFrom (qosChar.type(), RealTimeConfiguration::meta))
//           {
//             // We assume that each component has only one RealTimeConfiguration
//             rtConfig = RealTimeConfiguration::Cast (qosChar);
//             break;
//           }
//       }
//     return rtConfig;
//   }

//   bool LanePredicate (const Lane& lhs, const Lane& rhs)
//   {
//     // default_priority of thread pools without lanes should match.
//     short lvalue = static_cast<short>(lhs.lane_priority());;
//     short rvalue = static_cast<short>(rhs.lane_priority());
//     return lvalue == rvalue;
//   }

//   struct ThreadPoolPredicate
//     : public binary_function<ThreadPool, ThreadPool, bool>
//   {
//     bool operator() (const ThreadPool& lhs, const ThreadPool& rhs)
//     {
//       bool lallowReqBuff = lhs.allow_request_buffering();
//       bool rallowReqBuff = rhs.allow_request_buffering();
//       unsigned long lmaxReq
//         = static_cast<unsigned long>(lhs.max_buffered_requests());
//       unsigned long rmaxReq
//         = static_cast<unsigned long>(rhs.max_buffered_requests());
//       unsigned long lstackSize
//         = static_cast<unsigned long>(lhs.stacksize());
//       unsigned long rstackSize
//         = static_cast<unsigned long>(rhs.stacksize());
//       unsigned long lmaxBuff
//         = static_cast<unsigned long>(lhs.max_buffer_size());
//       unsigned long rmaxBuff
//         = static_cast<unsigned long>(rhs.max_buffer_size());
//       bool lallowBorrowing = lhs.allow_borrowing();
//       bool rallowBorrowing = rhs.allow_borrowing();
//       if (lallowReqBuff != rallowReqBuff
//           || lmaxReq != rmaxReq
//           || lstackSize != rstackSize
//           || lmaxBuff != rmaxBuff
//           || lallowBorrowing != rallowBorrowing)
//         {
//           return false;
//         }
//       set<LanePerThreadPool> llaneConns = lhs.srcLanePerThreadPool();
//       set<LanePerThreadPool> rlaneConns = rhs.srcLanePerThreadPool();
//       // We cannot merge thread pool without lanes and thread pool with lanes.
//       if (llaneConns.size() == 1 && rlaneConns.size() > 1
//           || rlaneConns.size() == 1 && llaneConns.size() > 1)
//         {
//           return false;
//         }
//       if (llaneConns.size() == 1 && rlaneConns.size() == 1)
//         {
//           // XXX: Assume that this is a thread pool without lanes; note
//           // that we cannot differentiate between thread pool without a
//           // lane from a thread pool with a single lane due to the current
//           // metamodel.
//           LanePerThreadPool llaneConn = *llaneConns.begin();
//           Lane llane = llaneConn.srcLanePerThreadPool_end();
//           LanePerThreadPool rlaneConn = *rlaneConns.begin();
//           Lane rlane = rlaneConn.srcLanePerThreadPool_end();
//           return LanePredicate (llane, rlane);
//         }
//       // We have two thread pools each with different number of lanes that
//       // can be merged.
//       return true;
//     }
//   };

//   struct PriorityModelPolicyPredicate
//     : public binary_function<PriorityModelPolicy, PriorityModelPolicy, bool>
//   {
//     bool operator() (const PriorityModelPolicy& lhs,
//                      const PriorityModelPolicy& rhs)
//     {
//       string left (lhs.priority_model());
//       string right (rhs.priority_model());
//       short lvalue = static_cast<short>(lhs.priority_value());
//       short rvalue = static_cast<short>(rhs.priority_value());
//       return (left == right && lvalue == rvalue);
//     }
//   };


//   struct RTConfigPredicate
//     : public binary_function<RealTimeConfiguration, RealTimeConfiguration, bool>
//   {
//     bool operator() (const RealTimeConfiguration& lhs,
//                      const RealTimeConfiguration& rhs)
//     {
//       vector<PriorityModelPolicy>
//         lpriorityModels = lhs.PriorityModelPolicy_kind_children();
//       vector<PriorityModelPolicy>
//         rpriorityModels = rhs.PriorityModelPolicy_kind_children();
//       // If PriorityModelPolicies don't match, we cannot merge.
//       if (!equal (lpriorityModels.begin(), lpriorityModels.end(),
//                   rpriorityModels.begin(), PriorityModelPolicyPredicate()))
//         {
//           return false;
//         }
//       vector<ThreadPool> lthreadPool = lhs.ThreadPool_kind_children();
//       vector<ThreadPool> rthreadPool = rhs.ThreadPool_kind_children();
//       // If one has a thread pool and the other doesn't, we can always merge.
//       if (lthreadPool.size() == 1 && rthreadPool.size() == 0
//           || lthreadPool.size() == 0 && rthreadPool.size() == 1)
//         {
//           return true;
//         }
//       // If ThreadPools don't match, we cannot merge.
//       if (!equal (lthreadPool.begin(), lthreadPool.end(),
//                   rthreadPool.begin(), ThreadPoolPredicate()))
//         {
//           return false;
//         }
//       return true;
//     }
//   };

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
        PortType port = PortType::Cast ((conn.*portEnd)());
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
    Comp comp;
    for (boost::tie (iBegin, iEnd) = make_pair (connections.begin(),
                                                connections.end());
         iBegin != iEnd;
         ++iBegin)
      {
        Conn conn = *iBegin;
        Udm::Object end = (conn.*compEnd)();
        if (Udm::IsDerivedFrom (end.type(), Comp::meta))
          {
            Comp temp = Comp::Cast(end);
            if (comp == temp)
              continue;
            else
              comp = temp;
          }
        set<Comp>::const_iterator compIter;
        compIter = find (clique.begin(), clique.end(), comp);
        if (compIter != clique.end())
          {
            (conn.*compEnd)() = instance;
          }
      }
  }


  struct PAMPredicate
    : public binary_function<Component, Component, bool>
  {
    typedef vector<ProvidedRequestPort> FacetSet;
    typedef vector<RequiredRequestPort> ReceptacleSet;
    typedef vector<OutEventPort> PublisherSet;
    typedef vector<InEventPort> ConsumerSet;

    typedef map<Component, FacetSet> FacetMap;
    typedef map<Component, ReceptacleSet> ReceptacleMap;
    typedef map<Component, PublisherSet> PublisherMap;
    typedef map<Component, ConsumerSet> ConsumerMap;

    PAMPredicate (const set<Component>& components)
    {
      for (set<Component>::const_iterator iter = components.begin();
           iter != components.end();
           ++iter)
        {
          Component comp (*iter);
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

    bool operator() (const Component& lhs, const Component& rhs)
    {
//       // Check for compatible RT Policies
//       RealTimeConfiguration lconfig = GetRTConfig (lhs);
//       RealTimeConfiguration rconfig = GetRTConfig (rhs);
//       if (lconfig != rconfig)
//         {
//           return false;
//         }

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
    template <class T>
    string CreateCliqueString (const set<T>& clique);
    void CreatePhysicalAssemblies (set<Component>& candidateTypes,
                                   set<Component>& candidateInstances);
    void UpdateComponentConnections (const ComponentAssembly& container,
                                     const Component& asmInstance,
                                     const set<Component>& clique);
    void UpdateAttributes (const ComponentAssembly& container,
                           const Component& asmInstance,
                           const set<Component>& clique);
    void CreateAsmAttributes (const Component& comp,
                              const Component& asmComp);
    bool CreateInterfaceDefinitions (const set<Component>& clique);
    void CreateImplementationArtifacts (const set<Component>& clique);
    void UpdateAssembly (const set<Component>& clique);
//     void UpdateAssembly (const set<RealTimeConfiguration>& clique);
    void UpdateDeploymentPlans (const set<DeploymentPlan>& plans);
    void MergeDeploymentPlans (const set<DeploymentPlan>& plans);
    void CloneDeploymentPlanElements(const DeploymentPlan& plan);
    void ConnectCgNodeRef(const CollocationGroup& cg);
    void CollectCgs (const set<DeploymentPlan>& plans,
                     set<Node>& nodes,
                     multimap<Node, CollocationGroup>& nodeCgMap);
    void CollectNodeComponents(Node& node,
                               multimap<Node, CollocationGroup>& nodeCgMap,
                               set<Component>& candidateTypes,
                               set<Component>& candidateInstances);
    void CreateGlobalPhysicalAssemblies  (const set<DeploymentPlan>& plans);
    NodeReference CreateNodeReference (const DeploymentPlan& parent,
                                       const Node& node);

    void CleanUpAssemblies ();
    void CollectDeploymentPlanComponents (set<DeploymentPlan>& plans);
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
    void CreateCandidateComponents (set<CollocationGroupMember>& cgmembers,
                                    set<Component>& candidateTypes,
                                    set<Component>& candidateInstances);

    void GenerateCliqueSets (set<Component>& candidateTypes,
                             set<Component>& candidateInstances,
                             CompCliques& cliqueSets);
//     RealTimeConfiguration CreateMergedRealTimeConfiguration (const ComponentAssembly& cliqueAsm,
//                                                              const set<RealTimeConfiguration>& clique);
//     void MergePriorityBands (vector<PriorityBands>& bands,
//                              RealTimeConfiguration rtConfigAsm);
//     void MergeThreadPoolLanes (vector<Lane>& lanes,
//                                RealTimeConfiguration rtConfigAsm);
//     void CollectRTConfigs (set<Component>& candidateInstances,
//                            set<RealTimeConfiguration>& rtconfigs);
//     void MergeRTConfigurations (set<Component>& candidateInstances);

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

    CompCliques         compCliques_;

//     RTConfigCliques     rtConfigCliques_;

    struct AsmInfo
    {
      Component         asmComp;
      ComponentFactory  asmHome;
      Package           asmPackage;
    };

    typedef map<string, AsmInfo> AsmInfoMap;
    AsmInfoMap          createdAsms_;

    typedef multimap<Component, Component> CandidateMap;
    CandidateMap        candidateMap_;

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
