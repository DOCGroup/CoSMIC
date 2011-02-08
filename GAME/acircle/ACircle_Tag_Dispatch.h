//=============================================================================
/**
 *  @file       ACircle_Tag_Dispatch.h
 *
 *  File contains the ACircle Tag Dispatcher.
 *
 *  $Id:$
 *
 *  @author     Harold Owens II <owensh@cs.iupui.edu>
 */
//=============================================================================

#include "ACircle_Traits.h"

#ifndef _ACIRCLE_TAG_DISPATCH_
#define _ACIRCLE_TAG_DISPATCH_

namespace ACircle_Tag_Dispatch {

  /// type tag for the backends
  struct udm_tag {};  // Udm
  struct bon_tag {};  // Bon2
  struct game_tag {}; // GAME

  /**
  * @warning impl namespace contains the implementation of the functions
  *          required by each backend to integrate A-Circle.
  *
  */
  namespace impl {
  
      /// get children Udm
      template <typename T, typename S>
      vector <S> get_children (const T& o, udm_tag)
      {
        return Udm::ChildrenAttr <S> (o.__impl (), Udm::NULLCHILDROLE);
      }
      
      /// get reference object Udm
      template <typename T>
      T get_referenced_object (const T& o, udm_tag)
      {
        return o.getReferencedObject ();
      }
      
      /// is not prefined type Udm
      template <typename T>
      bool is_not_prefined_type (const T& o, udm_tag)
      {
        return (Udm::IsDerivedFrom (o.getReferencedObject ().type (), 
                PICML::PredefinedType::meta) == false);
      }
      
      /// is null Udm
      template <typename T>
      bool is_null (const T& o, udm_tag)
      {
        return o == Udm::null;
      }
      
      /// is subtype Udm
      template <typename T>
      bool is_subtype (const T& o, udm_tag)
      {
        return o.isSubtype ();
      }
      
      /// get parent Udm
      template <typename T>
      T get_parent (const T& o, udm_tag)
      {
        return o.GetParent ();
      }

      /// type Udm
      template <typename T, typename BM>
      BM type (const T& o, udm_tag)
      {
        return o.type ();
      }

      /// uniqueId Udm
      template <typename T>
      long uniqueId (const T& o, udm_tag)
      {
        return o.uniqueId ();
      }
      
      /// meta Udm T, U = Uml::Class
      template<typename U, typename BM>
      BM meta (udm_tag)
      {
        return U::meta;
      }

      /// source manages component end Udm only
      template<typename BASE, typename MC, typename CF>
      CF srcManagesComponent_end (const BASE& o, udm_tag)
      {
        return MC::Cast (o).srcManagesComponent_end ();
      }

      /// destination manages component end Udm only
      template<typename BASE, typename MC, typename M>
      M dstManagesComponent_end (const BASE& o, udm_tag)
      {
        return MC::Cast (o).dstManagesComponent_end ();
      }
      
      /// visit all Udm
      template<typename T, typename Visitor>
      void visit_all (const T& o, Visitor & v, udm_tag);
    } // impl namespace
  
  /// get children
  template <typename Trait, typename T, typename S>
  vector <S> get_children (const T& o) {
    typename ACircle_Traits<Trait>::model_method method;
    return impl::get_children <T, S> (o, method);
  }
  
  /// get reference object
  template <typename Trait, typename T>
  T get_referenced_object (const T& o) {
    typename ACircle_Traits<Trait>::model_method method;
    return impl::get_referenced_object (o, method);
  }
  
  /// is not prefined type
  template <typename Trait, typename T>
  bool is_not_prefined_type (const T& o)
  {
    typename ACircle_Traits<Trait>::model_method method;
    return impl::is_not_prefined_type (o, method);
  }

  /// is null
  template <typename Trait, typename T>
  bool is_null (const T& o)
  {
    typename ACircle_Traits<Trait>::model_method method;
    return impl::is_null (o, method);
  }
  
  /// is subtype
  template <typename Trait, typename T>
  bool is_subtype (const T& o)
  {
    typename ACircle_Traits<Trait>::model_method method;
    return impl::is_subtype (o, method);
  }
  
  /// get parent
  template <typename Trait, typename T>
  T get_parent (const T& o)
  {
    typename ACircle_Traits<Trait>::model_method method;
    return impl::get_parent (o, method);
  }
  
  /// type
  template <typename Trait, typename BM, typename T>
  BM type (const T& o)
  {
    typename ACircle_Traits<Trait>::model_method method;
    return impl::type <T, BM> (o, method);
  }
  
  /// uniqueId
  template <typename Trait, typename T>
  long uniqueId (const T& o)
  {
    typename ACircle_Traits<Trait>::model_method method;
    return impl::uniqueId (o, method);
  }
  
  /// meta
  template<typename Trait, typename T, typename U, typename BM>
  BM meta ()
  {
    typename ACircle_Traits<Trait>::model_method method;
    return impl::meta <U, BM> (method);
  }

  /// src manages component end
  template<typename Trait, typename BASE, typename MC, typename CF>
  CF srcManagesComponent_end (const BASE& o)
  {
    typename ACircle_Traits<Trait>::model_method method;
    return impl::srcManagesComponent_end <BASE, MC, CF>(o, method);
  }

  /// dest manages component end
  template<typename Trait, typename BASE, typename MC, typename M>
  M dstManagesComponent_end (const BASE& o)
  {
    typename ACircle_Traits<Trait>::model_method method;
    return impl::dstManagesComponent_end <BASE, MC, M> (o, method);
  }
  
  /// visit all
  template<typename Trait, typename T, typename Visitor>
  void visit_all (const T& o, Visitor & v)
  {
    typename ACircle_Traits<Trait>::model_method method;
    return impl::visit_all (o, v, method);
  }

} // ACircle_Tag_Dispatch namespace

#include "ACircle_Tag_Dispatch.inl"

#endif // _ACIRCLE_TAG_DISPATCH_