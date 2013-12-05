#ifndef FAULTTOLERANCE_VISITOR_H
#define FAULTTOLERANCE_VISITOR_H

#include <memory>
#include <map>
#include "CQML/CQML.h"

#include "FaultTolerance/FaultTolerance_Export.h"
#include "DeploymentPlanFramework/DeploymentPlanFrameworkVisitor.h"
#include "FaultTolerance/FTInjector.h"
#include "FaultTolerance/FTAdders.h"

namespace CQML
{
      class FaultTolerance_Export FaultToleranceVisitor: public Visitor
      {
        public:
          FaultToleranceVisitor (const std::string& outputPath);
          ~FaultToleranceVisitor();
          virtual void Visit_RootFolder(const RootFolder &);
   	      virtual void Visit_DeploymentPlans (const DeploymentPlans& dp_folder);
          virtual void Visit_DeploymentPlan (const DeploymentPlan& plan);

		protected:
		  void parse_ft_requirements (const RootFolder &);

        private:
          std::auto_ptr<FTInjector> ft_injector_;
		  FTRequirementsVisitor *ft_req_visitor_;
		  ComponentAdder *comp_addr_;
          std::string output_path_;
          //std::map <std::string, Injector *> plan_injector_map_;
/***************************************************************************/	  
	  // The const auto_ptr idiom by Hurb Sutter.
	  // The const auto_ptr is the only owner of the singleton framework pointer
	  // See Tom Cargill's ownership patterns in PLoPD2.
	  // that will be deleted at the end. As a side effect of making this member
	  // a const member, compiler can not generate a copy-constructor for 
	  // the FaultToleranceVisitor class because std::auto_ptr uses move semantics. Therefore,
	  // a protected copy-constructor is declared to supress automatic generation
	  // of the copy-constructor.
	  const std::auto_ptr <DeploymentPlanFrameworkVisitor> dp_framework_owner;

  protected:
	  FaultToleranceVisitor (const FaultToleranceVisitor &);
/***************************************************************************/

      };


} // namespace CQML

/*
  class Composite 
    {
      public:
        virtual ~Composite() {};
        virtual bool is_leaf(void) const { return true; }
        virtual Composite *add_composite (Composite *) = 0;
        virtual Composite *set_parent (Composite *);
      private:
        const Composite *parent_; 
    };

  class SRG : public Composite
    {
      public:
        virtual ~SRG();
        virtual bool is_leaf(void) const ;
        virtual Composite *add_composite (Composite *);
      private:
        std::vector <Composite *> composites_;
    };

  class SRGNode : public Composite
    {
      public:
        virtual ~SRGNode();
        virtual bool is_leaf () const ;
        virtual Composite *add_composite (Composite *);
    };
*/



#endif /* FAULTTOLERANCE_VISITOR_H */
