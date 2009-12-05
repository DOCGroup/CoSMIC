// -*- C++ -*-

//=============================================================================
/**
 *  @file         DSL_Document.h
 *
 *  $Id$
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _DSL_DOCUMENT_H_
#define _DSL_DOCUMENT_H_

#include <afxrich.h>
#include "BON.h"

// Forward decl.
class DSL_Serializer;

// Forward decl.
class DSL_Deserializer;

/**
 * @class DSL_Document
 *
 * The underlying document for the domain-specific language.
 */
class DSL_Document : public CRichEditDoc
{
public:
  /// Default constructor.
  DSL_Document (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       obj       Source object.
   */
  DSL_Document (const BON::Object & obj);

  /// Destructor.
  virtual ~DSL_Document (void);

  DECLARE_DYNCREATE (DSL_Document);

  virtual CRichEditCntrItem * CreateClientItem (REOBJECT * obj) const;

  /**
   * Handle saving a document. This will serialize the document
   * back to the current model.
   */
  virtual void OnFileSave (void);

  /**
   * Serialize contained object to specified output stream.
   *
   * @param[in]     stream      Target output stream.
   */
  int serialize (std::ostream & stream);

  /**
   * Configure document with DSL serializer and deserializer. These
   * are used with the document is loaded and saved, respectively.
   *
   * @param[in]     serializer    The serializer for the document
   * @param[in]     deserialzer   The deserialzer for the document
   */
  void configure (DSL_Serializer * serializer,
                  DSL_Deserializer * deserializer);

  /// Test if the document is readonly. The document is realonly
  /// if the contained object is marked as readonly, or it is
  /// in a library.
  bool is_readonly (void) const;

protected:
  DECLARE_MESSAGE_MAP ()

  /// Object associated with the document.
  BON::Object obj_;

  /// Serializer for the document.
  DSL_Serializer * serializer_;

  /// Deserializer for the document.
  DSL_Deserializer * deserializer_;
};

#endif  // !defined _DSL_DOCUMENT_H_
