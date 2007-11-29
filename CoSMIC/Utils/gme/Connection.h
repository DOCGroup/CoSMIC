// -*- C++ -*-

//=============================================================================
/**
 * @file        Connection.h
 *
 * Defines the GME::Connection object.
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_CONNECTION_H_
#define _GME_CONNECTION_H_

#include "FCO.h"

namespace GME
{
  //===========================================================================
  /**
   * @class ConnectionPoint
   *
   * Wrapper class for the IMgaConnection COM interface.
   */
  //===========================================================================

  class GME_Export ConnectionPoint
  {
  public:
    /// Type definition of the interface type.
    typedef IMgaConnPoint _type;

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
   * @class Connection
   *
   * Wrapper class for the IMgaConnection COM interface.
   */
  //===========================================================================

  class GME_Export Connection : public FCO
  {
  public:
    /// Type definition of the interface type.
    typedef IMgaConnection _type;

    /**
     * Create a new connection in an existing model.
     *
     * @param[in]       role        Meta name of the connection.
     * @param[in]       parent      Parent model of the connection.
     * @param[in]       src         Source FCO of the connection.
     * @param[in]       dst         Destination FCO of the connection.
     * @return          Newly created connection object.
     */
    static Connection _create (const std::string & role,
                               const Model & parent,
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
    size_t connection_points (Collection_T <ConnectionPoint> & points);

  private:
    /// Pointer to the connection object.
    mutable CComPtr <IMgaConnection> conn_;
  };
}

#if defined (__GME_INLINE__)
#include "Connection.inl"
#endif

#endif
