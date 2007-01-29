#ifndef _GME_MODEL_H_
#define _GME_MODEL_H_

#include "GME_fwd.h"
#include "FCO.h"

namespace GME
{
  class GME_Export Model : public FCO
  {
  public:
    typedef IMgaModel _type;

    Model (void);
    Model (IMgaModel * model);
    Model (const Model & model);
    virtual ~Model (void);

    const Model & operator = (const Model & model);
    void attach (IMgaModel * model);

    std::vector <FCO> fcos (const std::string & type) const;
    std::vector <Atom> atoms (const std::string & type) const;
    std::vector <Model> models (const std::string & type) const;
    std::vector <Set> sets (const std::string & type) const;
    std::vector <Reference> references (const std::string & type) const;

  protected:
    /// Helper method that gets the children of a specified \a type
    /// and returns them as the specified GME type (i.e., Model, FCO,
    /// Atom, and etc). This function can only be used by folders and
    /// models. All other will not compile since they do not define
    /// the appropriate methods.
    template <typename T>
    std::vector <T> get_children (const std::string & type) const;

    IMgaModel * impl (void) const;

    mutable CComPtr <IMgaModel> model_;
  };
}

#endif // !defined _GME_MODEL_H_
