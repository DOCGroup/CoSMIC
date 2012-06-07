// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaConnection.h
 *
 * $Id$
 *
 * @author    Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MGA_META_CONNECTION_H_
#define _GAME_MGA_META_CONNECTION_H_

#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"

#include "MetaFCO.h"
#include "stlace.h"
#include "Refcountable.h"


namespace GAME
{
namespace Mga
{
namespace Meta
{
 
// Forward declaration
class Connection_Impl;

/**
 * @class ConnectionPoint_Impl
 *
 * Wrapper class for the IMgaMetaConnJoint COM interface.
 */

class GAME_MGA_Export ConnectionPoint_Impl : public Refcountable
{
public:
  /// Type definition of the interface pointer.
  typedef IMgaMetaConnJoint interface_type;

  /// Default constructor.
  ConnectionPoint_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       point       Pointer to the interface.
   */
  ConnectionPoint_Impl (IMgaMetaConnJoint * point);

  /// Destructor.
  virtual ~ConnectionPoint_Impl (void);

  /**
   * Get a pointer to the underlying interface.
   *
   * @return          Pointer to the interface.
   */
  IMgaMetaConnJoint * impl (void) const;

   /**
   * Attach the object to the specified interface.
   *
   * @param[in]       point       Pointer to the target object.
   */
  void attach (IMgaMetaConnJoint * point);

  /**
   * Get the parent of this connector, which is Connection_Impl.
   *
   * @return          Parent of the Metaconnection.
   */
  Connection parent (void) const;

  /**
   * Get the role name of the connector.
   *
   * @param[out]      fcos          All roles associated to connector.
   * @return                        size of the vector.
   */
  size_t roles (std::vector <std::string> &rls);

  /**
   * Get the target object for the connector.
   *
   * @param[out]      fcos          Target FCO objects of the connector.
   * @return                        size of the vector.
   */
  size_t targets (std::vector <FCO> & fcos);

  /**
   * Get the source of the connectors.
   *
   * @return                        The source target of the connector
   */
  FCO get_src (void);

  /**
   * Get the destination of this connector.
   *
   * @return                        The destination targets of the connector
   */
  std::vector <std::vector<FCO>> get_dsts (void);

private:
  /// Pointer to the connection point.
  mutable CComPtr <IMgaMetaConnJoint> point_;

};
//==============================================================================
/**
 * @class Connection_Impl
 *
 * Wrapper class for the IMgaMetaConnection interface.
 */
class GAME_MGA_Export Connection_Impl : public FCO_Impl
{
public:
  /// Type definition of the interface pointer.
  typedef IMgaMetaConnection interface_type;

  /// Default constructor.
  Connection_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     meta        Pointer to the meta information.
   */
  Connection_Impl (IMgaMetaConnection * aspect);

  /// Destructor.
  virtual ~Connection_Impl (void);

  /// Helper method to the correct implementation.
  IMgaMetaConnection * impl (void) const;

  /**
   * Get the connection points for this connection.*
   *
   * @param[out]      points      Collection of connection points.
   * @return          Number of connection points in \a points.
   */
  size_t connectors (std::vector <ConnectionPoint> & points) const;

private:
  /// Cached pointer to the implementation.
  mutable ATL::CComPtr <IMgaMetaConnection> conn_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaConnection.inl"
#endif

#endif  // !defined _GAME_MGA_META_CONNECTION_H_
