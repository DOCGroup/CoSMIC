// -*- C++ -*-

//=============================================================================
/**
 * @file        Connection.h
 *
 * Defines the GAME::Connection object.
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_CONNECTION_H_
#define _GME_CONNECTION_H_

#include "FCO.h"
#include "stlace.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"

namespace GAME
{
  //===========================================================================
  /**
   * @class ConnectionPoint
   *
   * Wrapper class for the IMgaConnection COM interface.
   */
  //===========================================================================

  class GAME_Export ConnectionPoint
  {
  public:
    /// Type definition of the interface type.
    typedef IMgaConnPoint interface_type;

    /// Default constructor.
    ConnectionPoint (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       point       Pointer to the interface.
     */
    ConnectionPoint (IMgaConnPoint * point);

    /**
     * Copy constructor.
     *
     * @param[in]       point       The source connection point.
     */
    ConnectionPoint (const ConnectionPoint & point);

    /// Destructor.
    virtual ~ConnectionPoint (void);

    /**
     * Assignment operator.
     *
     * @param[in]       point       The source object.
     * @return          Reference to self.
     */
    const ConnectionPoint & operator = (const ConnectionPoint & point);

    /**
     * Get a pointer to the underlying interface.
     *
     * @return          Pointer to the interface.
     */
    IMgaConnPoint * impl (void) const;

    /**
     * Attach the object to the specified interface.
     *
     * @param[in]       point       Pointer to the target object.
     */
    void attach (IMgaConnPoint * point);

    /**
     * Get the owner of this connection point, which is Connection.
     *
     * @return          Owner of the connection.
     */
    Connection owner (void) const;

    /**
     * Set the role of the connection point.
     *
     * @param[in]       name          The name of the role
     */
    void role (const std::string & name);

    /**
     * Get the role name of the connection point.
     *
     * @return          Role name of the connection point.
     */
    std::string role (void) const;

    /// Remove the connection.
    void remove (void);

    /**
     * Get the target object for the connection point.
     *
     * @return          The target FCO object.
     */
    FCO target (void) const;

  private:
    /// Pointer to the connection point.
    mutable CComPtr <IMgaConnPoint> point_;
  };

  //===========================================================================
  /**
   * @class ConnectionPoints
   *
   * Container class for a collection of connection points. This
   * simplifies accessing individual connection points over the
   * traditional vector approach.
   */
  //===========================================================================

  class GAME_Export ConnectionPoints
  {
  public:
    /// Type definition of the connection point manager.
    typedef ACE_Hash_Map_Manager <std::string,
                                  GAME::ConnectionPoint,
                                  ACE_Null_Mutex> ConnectionPoint_Mgr;

    /// Type definition of the iterator.
    typedef ConnectionPoint_Mgr::ITERATOR iterator;

    /// Type definition of the const iterator.
    typedef ConnectionPoint_Mgr::CONST_ITERATOR const_iterator;

    /// Type definition for the value type.
    typedef ConnectionPoint_Mgr::value_type value_type;

    /// Default constructor.
    ConnectionPoints (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       points        The source connection points.
     */
    ConnectionPoints (IMgaConnPoints * points);

    /**
     * Locate a connection point in the container.
     *
     * @param[in]       role        Connection point's role (e.g., 'dst')
     * @retval          true        Connection point for \a role found.
     * @retval          false       Connection point for \a role not found.
     */
    bool find (const std::string & role);

    /**
     * @overload
     *
     * @param[in]       role        Connection point's role (e.g., 'dst')
     * @param[out]      point       The connnection point.
     * @retval          true        Connection point for \a role found.
     * @retval          false       Connection point for \a role not found.
     */
    bool find (const std::string & role, ConnectionPoint & point);

    /**
     * Get a connection point in the model. This method assumes the
     * connection point does exist. The caller is responsible for
     * checking the validity of the returned collection points.
     *
     * @param[in]       role        Connection point's role (e.g., 'dst')
     * @return          The target collection point.
     */
    ConnectionPoint operator [] (const std::string & role) const;

    /**
     * Attach to an existing COM interface.
     *
     * @param[in]       points        The connection points interface.
     */
    void attach (IMgaConnPoints * points);

    /**
     * Get the number of connection points.
     *
     * @return          Number of connection points.
     */
    size_t size (void) const;


    /**
     * Get an iterator to the beginning of the list.
     *
     * @return      Iterator object.
     */
    iterator begin (void);

    /**
     * @overload
     */
    const_iterator begin (void) const;

    /**
     * Get an iterator to the end of the list.
     *
     * @return      Iterator object.
     */
    iterator end (void);

    /**
     * @overload
     *
     * @return      Const iterator object.
     */
    const_iterator end (void) const;

  private:
    /// Populate the container.
    void populate (void);

    /// Collection of connection points.
    ConnectionPoint_Mgr points_mgr_;

    CComPtr <IMgaConnPoints> points_;

    // prevent the following operations (too expensive)
    ConnectionPoints (const ConnectionPoints &);
    const ConnectionPoints & operator = (const ConnectionPoints &);
  };

  //===========================================================================
  /**
   * @class Connection
   *
   * Wrapper class for the IMgaConnection COM interface.
   */
  //===========================================================================

  class GAME_Export Connection : public FCO
  {
  public:
    /// Type definition of the interface type.
    typedef IMgaConnection interface_type;

    /**
     * Create a new connection in an existing model.
     *
     * @param[in]       role        Meta name of the connection.
     * @param[in]       parent      Parent model of the connection.
     * @param[in]       src         Source FCO of the connection.
     * @param[in]       dst         Destination FCO of the connection.
     * @return          Newly created connection object.
     */
    static Connection _create (const Model & parent,
                               const std::string & role,
                               const FCO & src,
                               const FCO & dst);

    /**
     * Extract a Connection object from an Object.
     *
     * @param[in]       obj         The source object.
     * @return          The extracted connection.
     */
    static Connection _narrow (const Object & obj);

    /// Default constructor.
    Connection (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       conn        Pointer to the connection object.
     */
    Connection (IMgaConnection * conn);

    /**
     * Copy constructor.
     *
     * @param[in]       conn        The source connection object.
     */
    Connection (const Connection & conn);

    /// Destructor.
    virtual ~Connection (void);

    /**
     * Assignment operator.
     *
     * @param[in]       conn        The source connection object.
     * @return          Reference to self.
     */
    const Connection & operator = (const Connection & conn);

    /**
     * Get a pointer to the raw COM implementation.
     *
     * @return          Pointer to the COM object.
     */
    IMgaConnection * impl (void) const;

    /**
     * Get the connection points for this connection.*
     *
     * @param[out]      points      Collection of connection points.
     * @return          Number of connection points in \a points.
     */
    size_t connection_points (ConnectionPoints & points);

    /**
     * Get the connection point by its role.
     *
     * @param[in]       role        Role of the connection point.
     * @return          The connection point
     */
    GAME::ConnectionPoint operator [] (const std::string & role);

  private:
    /// Pointer to the connection object.
    mutable CComPtr <IMgaConnection> conn_;
  };
}

#if defined (__GAME_INLINE__)
#include "Connection.inl"
#endif

#endif
