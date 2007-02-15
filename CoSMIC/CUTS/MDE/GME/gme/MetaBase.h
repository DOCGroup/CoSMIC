// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaBase.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_METABASE_H_
#define _GME_METABASE_H_

#include "Exception.h"
#include "Mga.h"

namespace GME
{
  //===========================================================================
  /**
   * @class MetaBase
   *
   * Wrapper class for the IMgaMetaBase interface.
   */
  //===========================================================================

  class GME_Export MetaBase
  {
  public:
    /// Default constructor.
    MetaBase (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       meta        Pointer to the source interface.
     */
    MetaBase (IMgaMetaBase * meta);

    /**
     * Copy constructor.
     *
     * @param[in]       meta        The source object.
     */
    MetaBase (const MetaBase & meta);

    /// Destructor.
    virtual ~MetaBase (void);

    /**
     * Get the actual meta name.
     *
     * @return          The name of the meta object.
     */
    std::string name (void) const;

    /**
     * Set the actual meta name.
     *
     * @param[in]       name      The name of the meta object.
     */
    void name (const std::string & name);

    /**
     * Get the displayed name for the meta.
     *
     * @return          The displayed name.
     */
    std::string displayed_name (void) const;

    /**
     * Set the displayed meta name.
     *
     * @param[in]       name      The name of the meta object.
     */
    void displayed_name (const std::string & name);

    /**
     * Attach to an existing interface.
     *
     * @param[in]       meta        Pointer to the source object.
     */
    void attach (IMgaMetaBase * meta);

    /**
     * Assignment operator.
     *
     * @param[in]       meta        The source meta.
     * @return          Reference to this object.
     */
    const MetaBase & operator = (const MetaBase & meta);

    /**
     * Convert the object to a IMgaMetaBase pointer.
     *
     * @return          Pointer to a IMgaMetaBase object.
     */
    operator IMgaMetaBase * (void) const;

    /**
     * Determine if the metabase's name is equal to \a name. This
     * compares the name with the real name, not the displayed name
     * of the metabase.
     *
     * @param[in]       name        Name to compare.
     * @retval          true        The object matches \a name.
     * @retval          false       The object does not match \a name.
     */
    bool operator == (const std::string & name) const;

    /**
     * Determine if two MetaBase objects are equal.
     *
     * @param[in]       meta        The source object.
     * @retval          true        The two objects are the same
     * @retval          false       The two objects are not the name.
     */
    bool operator == (const MetaBase & meta) const;

    /**
     * Get the meta reference id.
     *
     * @return          The reference id.
     */
    long refid (void) const;

    /**
     * Set the meta reference id.
     *
     * @param[in]       refid       The reference id.
     */
    void refid (long refid);

    /**
     * Get the object type of the meta information.
     *
     * @return          The object type.
     */
    objtype_enum type (void) const;

    /// Delete the meta object.
    void destroy (void);

    /**
     * Get the specified registry value.
     *
     * @param[in]       path      The target path.
     * @return          The registry value of \a path.
     */
    std::string registry_value (const std::string & path) const;

    /**
     * Set the specified registry value.
     *
     * @param[in]       path      The target path.
     * @param[in]       value     The new value.
     */
    void registry_value (const std::string & path,
                         const std::string & value);

    /**
     * Get a pointer to the implementation.
     *
     * @return          Pointer to the implementation.
     */
    IMgaMetaBase * impl (void) const;

    /**
     * Convert the object to a boolean value. This will test the
     * validity of the object.
     *
     * @retval          true      The object is valid.
     * @retval          false     The object is not valid.
     */
    operator bool (void) const;

  protected:
    /// The underlying interface pointer.
    CComPtr <IMgaMetaBase> metabase_;
  };
}

#endif  // !defined _GME_METABASE_H_
