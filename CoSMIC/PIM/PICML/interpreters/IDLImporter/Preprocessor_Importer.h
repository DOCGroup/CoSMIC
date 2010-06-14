// -*- C++ -*-

//=============================================================================
/**
 * @class Prepreocessor_Importer.h
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _PREPROCESSOR_IMPORTER_H_
#define _PREPROCESSOR_IMPORTER_H_

namespace GAME
{
namespace XME
{
class Model;
}
}

/**
 * @class Preprocessor_Importer
 *
 * Class for importing preprocessor directives into a PICML model. 
 * This only handle the known preprocessor directives to the DOC 
 * middlware.
 */
class Preprocessor_Importer
{
public:
  /// Default constructor.
  Preprocessor_Importer (void);

  /// Destructor.
  ~Preprocessor_Importer (void);

  /// Parse the specified filename.
  bool parse (const char * filename, GAME::XME::Model & model);
};

#endif  // !defined _PREPROCESSOR_IMPORTER_H_
