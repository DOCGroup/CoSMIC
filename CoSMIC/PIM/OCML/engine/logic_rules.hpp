// $Id$

#ifndef _LOGIC_RULES_HPP_
#define _LOGIC_RULES_HPP_

#include <list>
#include <memory>

#include "rule.hpp"

namespace OCML
{

  class OCML_Engine_Export Not_Rule: public Basic_Rule<Not_Rule>
  {
  public:
    Not_Rule(const Not_Rule& rule);

    Not_Rule(Rule* root, Rule* rule);

    virtual ~Not_Rule() { };

    virtual bool test() const;

    virtual bool apply(bool negate);

  private:
    std::auto_ptr<Rule> rule_;
  };

  class OCML_Engine_Export And_Rule: public Basic_Rule<And_Rule>
  {
  public:
    And_Rule(const And_Rule& rule);

    template <typename InputIterator>
    And_Rule(Rule* root, InputIterator first, InputIterator last);

    virtual ~And_Rule();

    virtual bool test() const;

    virtual bool apply(bool negate);

  private:
    std::list<Rule*> rules_;
  };

  class OCML_Engine_Export Or_Rule: public Basic_Rule<Or_Rule>
  {
  public:
    Or_Rule(const Or_Rule& rule);

    template <typename InputIterator>
    Or_Rule(Rule* root, InputIterator first, InputIterator last);

    virtual ~Or_Rule();

    virtual bool test() const;

    virtual bool apply(bool negate);

  private:
    std::list<Rule*> rules_;
  };

  class OCML_Engine_Export If_Rule: public Basic_Rule<If_Rule>
  {
  public:
    If_Rule(const If_Rule& rule);

    If_Rule(Rule* root, Rule* condition, Rule* action);

    virtual ~If_Rule() { };

    virtual bool test() const;

    virtual bool apply(bool negate);

  private:
    std::auto_ptr<Rule> condition_;
    std::auto_ptr<Rule> action_;
  };

  class OCML_Engine_Export Iff_Rule: public Basic_Rule<Iff_Rule>
  {
  public:
    Iff_Rule(const Iff_Rule& rule);

    Iff_Rule(Rule* root, Rule* rule1, Rule* rule2);

    virtual ~Iff_Rule() { };

    virtual bool test() const;

    virtual bool apply(bool negate);

  private:
    std::pair< std::auto_ptr<Rule>, std::auto_ptr<Rule> > rules_;
  };

} // namespace OCML

#include "logic_rules.ipp"
#include "logic_rules.tpp"

#endif // _LOGIC_RULES_HPP_
