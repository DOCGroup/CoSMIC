#ifndef _RULE_HPP_
#define _RULE_HPP_

#include <memory>
#include <list>
#include <iostream>
#include "OCML_Engine_Export.h"

namespace OCML
{

  /**
   * Base class for all the rules.
   * class Rule defines test() and apply() abstract methods.
   */

  class OCML_Engine_Export Rule
  {
  public:
    Rule(Rule* root);

    /// Tests if the option values can be validated with this rule.
    virtual bool test() const = 0;
    /// Tests if the option values can be validated with this rule.
    /// If not tries to validate them by assigning values to options,
    /// If there is a collision then returns false.
    virtual bool apply(bool negate) = 0;

    /// Checks the validation of the all rules by calling the root rule's apply
    /// method.
    bool check_validity();

    virtual Rule* duplicate() const = 0;

  protected:
    /// Root rule is stored for validity check in check_validity function.
    Rule* root_rule_;
  };

  /**
   * The derived rule itself should be provided as a template parameter.
   */
  template <typename RULE>
  class Basic_Rule: public Rule
  {
  public:
    Basic_Rule(Rule* root)
      : Rule(root)
    {
    }

    virtual Rule* duplicate() const
    {
      return new RULE(*(RULE*)(this));
    }
  };

  class OCML_Engine_Export Root_Rule: public Basic_Rule<Root_Rule>
  {
  public:
    typedef std::list<Rule*> rule_container;
    typedef rule_container::iterator rule_index;

  public:
    Root_Rule()
      : Basic_Rule<Root_Rule>(0)
    {
    }
    virtual ~Root_Rule();

    virtual bool test() const;
    virtual bool apply(bool negate);
    bool apply() { return apply(false); }

    rule_index add_rule(Rule* rule);
    void delete_rule(rule_index index);

    Rule* get_rule(rule_index index);

  private:
    rule_container rules_;
  };

}; // namespace OCML

#include "rule.ipp"

#endif // _RULE_HPP_
