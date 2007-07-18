#include <stdafx.h>
#include <GatewayGenerator/AspNetVisitor.h>
#include <GatewayGenerator/GatewayGeneratorUtils.h>
#include <CCF/CodeGenerationKit/IndentationImplanter.hpp>
#include <CCF/CodeGenerationKit/IndentationCxx.hpp>
#include <set>
#include <vector>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <functional>

using std::binary_function;
using std::set;
using std::vector;
using std::string;
using std::endl;
using std::ofstream;
using std::stringstream;
using std::toupper;
using std::tolower;
using std::isalnum;
using std::sort;
using std::copy;
using std::transform;
using std::for_each;
using boost::bind;
using boost::ref;


template <class T>
struct ParamSorter
  : public binary_function<T,T,bool>
{
  bool operator()(const T& x, const T& y)
  {
    BON::FCOExRegistryNode& lnode (x->getRegistry());
    BON::FCOExRegistryNode& rnode (y->getRegistry());
    BON::Point lhs = lnode->getLocation();
    BON::Point rhs = rnode->getLocation();
    return (lhs.first < rhs.first && lhs.second < rhs.second);
  }
};

AspNetVisitor::AspNetVisitor (BON::Project& project, string outputFolder)
  : project_ (project),
    outputFolder_ (outputFolder)
{
}

AspNetVisitor::~AspNetVisitor()
{}

string AspNetVisitor::idl_scoped_name (const BON::FCO& object)
{
  PredefinedType pdt (object);
  if (pdt) return this->basic_name (pdt);

  BON::Model parent (object->getParentModel ());

  // If we are a file, return an empty string.
  if (!parent) return "";

  string local_name (object->getName ());

  // If our parent is a file, don't tack on its name.
  if (!File (parent))
    {
      return this->idl_scoped_name (parent) + "::" + local_name;
    }

  return local_name;
}

string AspNetVisitor::wsdl_scoped_name (const BON::FCO& object,
                                        bool append)
{
  PredefinedType pdt (object);
  if (pdt) return this->asp_net_basic_name (pdt);

  BON::Model parent (object->getParentModel ());

  // If we are a file, return an empty string.
  if (!parent) return "";

  string local_name (object->getName ());

  // If our parent is a file, don't tack on its name.
  if (!File (parent))
    {
      if (Collection (object))
        {
			Collection sequence (object);

          local_name = sequence->getReferred()->getName();
        }
      string name  = this->wsdl_scoped_name (parent, append)
                     + local_name;
      if (append)
        name += "^";
      if (Collection (object))
        {
          string prefix ("cli::array<");
          string suffix (">^");
          name = prefix + name + suffix;
        }
      return name;
    }
  return local_name;
}

string AspNetVisitor::asp_net_basic_name (const PredefinedType& pdt)
{
  if (String (pdt))             return "System::String";
  if (LongInteger (pdt))        return "System::Int32";
  if (RealNumber (pdt))         return "System::Double";
  if (ShortInteger (pdt))       return "System::UInt16";
  if (Boolean (pdt))            return "System::Boolean";
  else                          return "";
}

string AspNetVisitor::basic_name (const PredefinedType& pdt)
{
  if (String (pdt))             return "string";
  if (LongInteger (pdt))        return "int";
  if (RealNumber (pdt))         return "double";
  if (ShortInteger (pdt))       return "short";
  if (Boolean (pdt))            return "boolean";
  if (Byte (pdt))               return "octet";
  if (GenericValue (pdt))       return "any";
  if (GenericObject (pdt))      return "Object";
  if (GenericValueObject (pdt)) return "ValueBase";
  if (TypeEncoding (pdt))       return "CORBA::TypeCode";
  if (TypeKind (pdt))           return "CORBA::TCKind";
  else                          return "";
}

string AspNetVisitor::get_file_name (const BON::FCO& object)
{
  BON::Model parent (object->getParentModel ());
  if (!parent) return object->getName();
  else
    return this->get_file_name (parent);
}

string
AspNetVisitor::transform_name (const char* name)
{
  string result;
  if (name && *name)
    {
      for (; *name; name++)
        {
          if (isalnum (*name) || *name == '_')
            result += *name;
        }
    }
  return result;
}

bool
AspNetVisitor::visitPortProxy(const PortProxy& object)
{
  BON::ReferencePort facetPort = object->getDst();
  BON::ReferencePort servicePort = object->getSrc();
  WSML::Port port = servicePort->getFCO();
  set<PortBinding> portBindings = port->getOutPortBindingLinks();
  for (set<PortBinding>::iterator bindIter = portBindings.begin();
       bindIter != portBindings.end();
       ++bindIter)
    {
      PortBinding portBinding (*bindIter);
      BindingRef bindingRef = portBinding->getDst();
      Binding binding = bindingRef->getBinding();
      // Collect the names of the bindings
      this->bindings_.insert (binding);
    }

  ProvidedRequestPort facet = facetPort->getFCO();
  Object iface = facet->getReferred();
  // Collect the interfaces corresponding to the port
  this->interfaces_[facet->getName()] = iface;
  // Collect the operations defined on the interface corresponding to the port
  set<TwowayOperation> operations = iface->getTwowayOperation();
  this->operations_.insert (operations.begin(), operations.end());

  for (set<TwowayOperation>::iterator op = operations.begin();
       op != operations.end();
       ++op)
    {
      TwowayOperation oper (*op);
      this->port_[oper] = facet->getName();
    }
  set<FacetDelegate> fdels = facet->getFacetDelegateLinks();
  for (set<FacetDelegate>::iterator iter = fdels.begin();
       iter != fdels.end();
       ++iter)
    {
      FacetDelegate del (*iter);
      ProvidedRequestPort compFacet (del->getSrc());
      Component comp (compFacet->getParentModel("PICML::Component"));
      if (!comp)
        {
          compFacet = del->getDst();
          comp = compFacet->getParentModel ("PICML::Component");
        }
      Component type = comp->getTypeInhObject()->getType()->getFCO();
      // Collect the component whose port this proxy is connected to
      this->comps_.insert (type);
      // Update the map linking components to ports
      std::pair<Component, ProvidedRequestPort> compPort (type, facet);
      this->ports_.insert (compPort);
      // Update the map linking intefaces to components
      this->parentComp_[iface] = type;
      return true;
    }
  return false;
}

bool
AspNetVisitor::visitPort (const WSML::Port& object)
{
  set<PortProxy> proxies = object->getOutPortProxyLinks();
  for_each (proxies.begin(), proxies.end(),
            bind (&PortProxyImpl::accept, _1, ref (this)));
  return true;
}

bool
AspNetVisitor::visitService(const Service& object)
{
  string moduleName (this->transform_name (object->getName().c_str()));
  Definitions def = object->getParentModel("WSML::Definitions");
  this->targetNamespace_ = def->gettargetNamespace();
  this->defName_ = def->getName();
  this->serviceName_ = moduleName;
  set<WSML::Port> ports = object->getPort();
  for_each (ports.begin(), ports.end(),
            bind (&WSML::PortImpl::accept, _1, ref (this)));

  string upperModuleName;
  transform (moduleName.begin(), moduleName.end(),
             back_inserter(upperModuleName), toupper);
  string path (this->outputFolder_);
  path += "\\";
  path += moduleName.c_str();
  string fileName (path + "_Impl.h");
  this->header_.open (fileName.c_str());
  if (!this->header_.is_open())
    {
      stringstream msg;
      msg << "Error in opening file " << fileName << endl;
      this->project_->consoleMsg (msg.str(), MSG_ERROR);
      throw AspNetException();
    }
  Indentation::Implanter <Indentation::Cxx> header (this->header_);
  this->header_ << "#ifndef " << upperModuleName << "_IMPL_H\n";
  this->header_ << "#define " << upperModuleName << "_IMPL_H\n\n";

  this->generate_header();

  this->header_ << "#endif /* " << upperModuleName << "_IMPL_H" << " */\n";

  fileName = path + "_Impl.cpp";
  this->source_.open (fileName.c_str());
  if (!this->source_.is_open())
    {
      stringstream msg;
      msg << "Error in opening file " << fileName << endl;
      this->project_->consoleMsg (msg.str(), MSG_ERROR);
      throw AspNetException();
    }
  Indentation::Implanter <Indentation::Cxx> source (this->source_);
  this->source_ << "#include <" << moduleName << "_Impl.h>\n\n";

  this->generate_source();
  return true;
}


void
AspNetVisitor::generate_operation_signature(const TwowayOperation& object,
                                            const string& prefix,
                                            ofstream& os)
{
  string operationName = this->transform_name (object->getName().c_str());
  set<ReturnType> retTypes = object->getReturnType();
  if (retTypes.size() == 0)
    {
      os << "System::Void ";
    }
  else
    {
      for (set<ReturnType>::iterator iter = retTypes.begin();
           iter != retTypes.end();
           ++iter)
        {
          ReturnType retType (*iter);
          MemberType returnType = retType->getMemberType();
          string retTypeName = this->wsdl_scoped_name (returnType);
          os << retTypeName;
          os << " ";
        }
    }
  if (!prefix.empty())
    os << prefix;
  os << operationName << "(";
  set<InParameter> inputParams = object->getInParameter();
  vector<InParameter> sortedParams;
  copy (inputParams.begin(), inputParams.end(), back_inserter (sortedParams));
  sort(sortedParams.begin(), sortedParams.end(), ParamSorter<InParameter>());
  size_t count = sortedParams.size() - 1;
  for (vector<InParameter>::iterator iter = sortedParams.begin();
       iter != sortedParams.end();
       ++iter, --count)
    {
      InParameter inputParam (*iter);
      MemberType paramType = inputParam->getMemberType();
      string paramTypeName = this->wsdl_scoped_name (paramType);
      os << paramTypeName;
      os << " ";
      os << inputParam->getName();
      if (count > 0)
        os << ", \n";
    }
  os << ")";
}

void
AspNetVisitor::generate_header()
{
  // Generate the #includes
  this->header_ << "#include <exception>\n"
                << "#include <orbsvcs/orbsvcs/CosNamingC.h>\n"
                << "#include <string>\n"
                << "#include <ace/Auto_Functor.h>\n";

  // Generate the #includes for every interface corresponding to every port
  // of the component(s) that this service delegates the implementation to.
  for (map<string, Object>::iterator iter = this->interfaces_.begin();
       iter != this->interfaces_.end();
       ++iter)
    {
      Object object (iter->second);
      string idlFile = this->get_file_name (object);
      string stubFile (idlFile + "C.h");
      this->header_ << "#include <" << stubFile << ">\n";
    }
  // Generate the #includes for every component that this service delegates
  // the implementation to.
  for (set<Component>::iterator iter = this->comps_.begin();
       iter != this->comps_.end();
       ++iter)
    {
      Component object (*iter);
      string idlFile = this->get_file_name (object);
      string stubFile (idlFile + "C.h");
      this->header_ << "#include <" << stubFile << ">\n";
    }
  // Generate the ASP.NET Header include
  this->header_ << "#include <" << this->serviceName_ << ".h>\n\n";

  // Generate the namespace where the code should reside
  this->header_ << "namespace " << this->defName_ << "\n";
  this->header_ << "{\n";
  // Generate the WebService namespace attribute
  this->header_ << "[WebService(Namespace=\"" << this->targetNamespace_
                << "\")]\n\n";

  // Generate the class declaration
  this->header_ << "public ref class " << this->serviceName_ << "\n"
                << "\t: public System::Web::Services::WebService,\n";
  size_t count = this->bindings_.size() - 1;
  // Generate the base class derivations using the bindings
  for (set<Binding>::iterator iter = this->bindings_.begin();
       iter != this->bindings_.end();
       ++iter, --count)
    {
      Binding binding (*iter);
      this->header_ << "\t  public " << this->defName_ << "::I"
                    << this->transform_name (binding->getName().c_str());
      if (count > 0)
        this->header_ << ",\n";
    }
  this->header_ << "\n";
  this->header_ << "{\n";
  this->header_ << "public:\n\n";

  // Generate the constructor and destructor
  this->header_ << this->serviceName_ << "();\n";
  this->header_ << "~" << this->serviceName_ << "();\n";

  // Generate the member functions
  for (set<TwowayOperation>::iterator iter  = this->operations_.begin();
       iter != this->operations_.end();
       ++iter)
    {
      TwowayOperation oper (*iter);
      string empty;
      // All methods are virtual
      this->header_ << "virtual ";
      this->generate_operation_signature (oper, empty, this->header_);
      this->header_ << ";" << endl;
    }
  // Generate _ptrs to hold all the interfaces
  this->header_ << "private:\n\n"
                << "CORBA::ORB_ptr orb_;\n";

  for (map<string, Object>::iterator iter = this->interfaces_.begin();
       iter != this->interfaces_.end();
       ++iter)
    {
      Object object (iter->second);
      this->header_ << this->idl_scoped_name (object) + "_ptr "
                    << iter->first << "_;" << endl;
    }
  // Generate _ptr for all components that this service delegates the
  // implementation to.
  for (set<Component>::iterator iter = this->comps_.begin();
       iter != this->comps_.end();
       ++iter)
    {
      Component object (*iter);
      string compName = object->getName();
      string lowerCompName;
      transform (compName.begin(), compName.end(),
                 back_inserter(lowerCompName), tolower);
      this->header_ << this->idl_scoped_name (object) + "_ptr "
                    << lowerCompName << "_;" << endl;
    }
  this->header_ << "};\n"
                << "}" << endl;
}


void
AspNetVisitor::generate_source()
{
  // Generate the top-level namespace
  this->source_ << "namespace " << this->defName_ << "\n"
                << "{\n\n";
  this->source_ << "using namespace System::Runtime::InteropServices;\n"
                << "struct MarshalFunctor\n"
                << "{\n"
                << "void operator() (char* ptr)\n"
                << "{\n"
                << "Marshal::FreeHGlobal (static_cast<System::IntPtr> (ptr));\n"
                << "}\n"
                << "};\n";
  this->source_ << "std::string CliStrToStdStr (System::String ^clistring)\n"
                << "{\n"
                << "char* str = static_cast<char*>\n"
                << "(static_cast<void*> (Marshal::StringToHGlobalAnsi(clistring)));\n"
                << "ACE_Utils::Auto_Functor<char,MarshalFunctor> cleanup (str);\n"
                << "return std::string(str);\n"
                << "}\n";
  // Generate constructor
  this->source_ << this->serviceName_ << "::" << this->serviceName_ << "()\n"
                << "{\n"
                << "try\n"
                << "{\n"
                << "int argc = 1;\n"
                << "CORBA::StringSeq argv (argc);\n"
                << "argv.length(argc);\n"
                << "argv[argc-1] = \"dummy\";\n"
                << "this->orb_ = CORBA::ORB_init (argc, argv.get_buffer(), \"\");\n"
                << "if (CORBA::is_nil (this->orb_))\n"
                << "{\n"
                << "throw std::exception(\"Unable to initialize ORB: ORB_init failed\");\n"
                << "}\n"
                << "CORBA::Object_var obj = this->orb_->resolve_initial_references (\"NameService\");\n"
                << "if (CORBA::is_nil(obj))\n"
                << "{\n"
                << "throw std::exception (\"Unable to obtain reference to NameService\");\n"
                << "}\n"
                << "CosNaming::NamingContext_var ctx = CosNaming::NamingContext::_narrow (obj);\n"
                << "if (CORBA::is_nil(ctx))\n"
                << "{\n"
                << "throw std::exception (\"Unable to narrow reference to initial Naming Context\");"
                << "}\n";
  // Obtain the object references of each component
  this->source_ << "CosNaming::Name name;\n"
                << "name.length (1);\n";
  for (set<Component>::iterator iter = this->comps_.begin();
       iter != this->comps_.end();
       ++iter)
    {
      Component object (*iter);
      string compName = object->getName();
      string lowerCompName;
      transform (compName.begin(), compName.end(),
                 back_inserter(lowerCompName), tolower);
      this->source_ << "name[0].id = CORBA::string_dup (\""
                    << object->getName() << "\");\n"
                    << "obj = ctx->resolve (name);\n"
                    << "if (CORBA::is_nil (obj))\n"
                    << "{"
                    << "throw std::exception (\"Unable to acquire "
                    << object->getName() << " objref\");\n"
                    << "}\n";
      this->source_ << "this->" << lowerCompName << "_ = "
                    << this->idl_scoped_name (object) << "::_narrow (obj.in());\n"
                    << "if (CORBA::is_nil ("
                    << "this->" << lowerCompName << "_))\n"
                    << "{"
                    << "throw std::exception (\"Unable to narrow reference to "
                    << object->getName() << "\");\n"
                    << "}";
    }
  // Obtain the references to all the ports
  for (map<string, Object>::iterator iter = this->interfaces_.begin();
       iter != this->interfaces_.end();
       ++iter)
    {
      string compName = this->parentComp_[iter->second]->getName();
      string lowerCompName;
      transform (compName.begin(), compName.end(),
                 back_inserter(lowerCompName), tolower);
      this->source_ << "this->" << iter->first << "_ = "
                    << "this->" << lowerCompName
                    << "_->provide_" << iter->first << "();\n";
      this->source_ << "if (CORBA::is_nil (this->" << iter->first << "_))\n"
                    << "{"
                    << "throw std::exception (\"Unable to acquire "
                    << iter->first << " objref\");"
                    << "}";
    }
  this->source_ << "}\n"
                << "catch (CORBA::Exception& ex)\n"
                << "{"
                << "ACE_PRINT_EXCEPTION (ex, \"CORBA::Exception\");\n"
                << "throw std::exception (ex._info().c_str());\n"
                << "}"
                << "}\n";

  // Generate the destructor
  this->source_ << this->serviceName_ << "::~" << this->serviceName_ << "()\n"
                << "{";
  // Generate _vars to hold all the interfaces
  for (map<string, Object>::iterator iter = this->interfaces_.begin();
       iter != this->interfaces_.end();
       ++iter)
    {
      Object object (iter->second);
      this->source_ << this->idl_scoped_name (object) + "_var "
                    << iter->first << "(this->" << iter->first << "_);\n";
    }
  // Generate _var for all components that this service delegates the
  // implementation to.
  for (set<Component>::iterator iter = this->comps_.begin();
       iter != this->comps_.end();
       ++iter)
    {
      Component object (*iter);
      string compName = object->getName();
      string lowerCompName;
      transform (compName.begin(), compName.end(),
                 back_inserter(lowerCompName), tolower);
      this->source_ << this->idl_scoped_name (object) + "_var "
                    << lowerCompName << "(this->" << lowerCompName << "_);\n";
    }
  this->source_ << "CORBA::ORB_var orb (this->orb_);\n";
  this->source_ << "}";

  // Generate the actual skeleton implementations...
  // Generate the member functions
  for (set<TwowayOperation>::iterator iter  = this->operations_.begin();
       iter != this->operations_.end();
       ++iter)
    {
      TwowayOperation oper (*iter);
      string prefix (this->serviceName_);
      prefix += "::";
      this->generate_operation_signature (oper, prefix, this->source_);
      this->source_ << "{";
      this->generate_function_body(oper, this->source_);
    }
  // Close the namespace
  this->source_ << "}\n";
}

void
AspNetVisitor::generate_function_body (const TwowayOperation& oper, ofstream& os)
{
  // Generate the function body
  this->source_ << "try" << endl;
  this->source_ << "{";
  set<InParameter> inputParams = oper->getInParameter();
  vector<InParameter> sortedParams;
  copy (inputParams.begin(), inputParams.end(), back_inserter (sortedParams));
  sort(sortedParams.begin(), sortedParams.end(), ParamSorter<InParameter>());
  vector<string> arguments;
  string retval;
  MemberType returnType;
  for (vector<InParameter>::iterator iter = sortedParams.begin();
       iter != sortedParams.end();
       ++iter)
    {
      InParameter inputParam (*iter);
      string soapName = inputParam->getName();
      string corbaName = soapName;
      MemberType paramType = inputParam->getMemberType();
      if (Collection (paramType))
        {
          Collection sequence = Collection (paramType);
          corbaName +=  "Seq";
          this->soap_seq_to_corba_seq (sequence,
                                       soapName,
                                       corbaName,
                                       this->source_);
        }
      arguments.push_back (corbaName);
    }
  set<ReturnType> retTypes = oper->getReturnType();
  for (set<ReturnType>::iterator iter = retTypes.begin();
       iter != retTypes.end();
       ++iter)
    {
      ReturnType retType (*iter);
      returnType = retType->getMemberType();
      string retTypeName = this->wsdl_scoped_name (returnType);
      if (PredefinedType (returnType))
        {
          this->source_ << retTypeName << " retval = ";
        }
      else if (Aggregate (returnType))
        {
          Aggregate agg = Aggregate (returnType);
          retval = this->idl_scoped_name (agg) + " _return = ";
        }
    }
  if (!retval.empty())
    {
      this->source_ << retval;
    }
  string portName = this->port_[oper] + "_";
  this->source_ << "this->" << portName << "->"
                << oper->getName() << " (";
  size_t count = arguments.size() - 1;
  for (vector<string>::iterator argIter = arguments.begin();
       argIter != arguments.end();
       ++argIter, --count)
    {
      this->source_ << (*argIter).c_str();
      if (count > 0)
        this->source_ << ", ";
    }
  this->source_ << ");";
  if (returnType)
    {
      if (Aggregate (returnType))
        {
          Aggregate agg = Aggregate (returnType);
          this->corba_struct_to_soap_struct (agg,
                                             "retval",
                                             "_return",
                                             this->source_, false);
        }
      this->source_ << "return retval;\n";
    }
  this->source_ << "}";
  set<ExceptionRef> exceptions = oper->getExceptionRef();
  for (set<ExceptionRef>::iterator exIter = exceptions.begin();
       exIter != exceptions.end();
       ++exIter)
    {
      ExceptionRef exceptionRef (*exIter);
      Exception exception (exceptionRef->getException());
      string exceptioName = this->idl_scoped_name (exception);
      this->source_ << "catch (" << exceptioName << "& ex)\n"
                    << "{"
                    << "ACE_PRINT_EXCEPTION (ex, "
                    << "\"" << oper->getName() << "\");\n"
                    << "throw std::exception (ex._info().c_str());\n"
                    << "}";
    }
  this->source_ << "catch (CORBA::Exception& ex)\n"
                << "{"
                << "ACE_PRINT_EXCEPTION (ex, "
                << "\"" << oper->getName() << "\"" << ");\n"
                << "throw std::exception (ex._info().c_str());\n"
                << "}"
                << "}\n";
}


void
AspNetVisitor::corba_struct_to_soap_struct (const Aggregate& agg,
                                            const string& soapName,
                                            const string& corbaName,
                                            ofstream& os,
                                            bool child)
{
  string aggName = this->wsdl_scoped_name (agg, false);
  if (!child)
    os << this->wsdl_scoped_name (agg) << " ";
  os << soapName << " = gcnew " <<  aggName << "();\n";
  set<Member> members = agg->getMember();
  for (set<Member>::iterator iter = members.begin();
       iter != members.end();
       ++iter)
    {
      Member member (*iter);
      MemberType memberType = member->getMemberType();
      string lhs = soapName + "->" + member->getName();
      string rhs = corbaName + "." + member->getName();
      if (PredefinedType (memberType))
        {
          os << lhs << " = " << rhs << ";\n";
        }
      else if (Aggregate (memberType))
        {
          Aggregate child (memberType);
          this->corba_struct_to_soap_struct (child, lhs, rhs, os, true);
        }
      else if (Alias (memberType))
        {
          Alias typeDef (memberType);
          MemberType memberType = typeDef->getMemberType();
          if (PredefinedType (memberType))
            {
              os << lhs << " = " << rhs << ";\n";
            }
        }
      else
        {
          stringstream msg;
          msg << "Unhandled CORBA type " << memberType->getName()
              << " in struct " << agg->getName() << endl;
          this->project_->consoleMsg (msg.str(), MSG_ERROR);
          throw AspNetException();
        }
    }
}

void
AspNetVisitor::soap_seq_to_corba_seq (const Collection& seq,
                                      const string& soapName,
                                      const string& corbaName,
                                      ofstream& os)
{
  MemberType seqType = seq->getMemberType();
  string scopedName = this->wsdl_scoped_name (seqType);
  os << this->idl_scoped_name (seq) << " " << corbaName << ";\n";
  os << "for (int i = 0; i < " << soapName << "->Length; ++i)\n";
  os << "{";
  os << scopedName << " element = " << soapName << "[i];\n";
  os << this->idl_scoped_name (seqType) << " " << corbaName << "Element;\n";
  Aggregate agg = Aggregate (seqType);
  if (!agg)
    {
      stringstream msg;
      msg << "Unhandled CORBA type " << seqType->getName() << "in sequence "
          << seq->getName() << endl;
      this->project_->consoleMsg (msg.str(), MSG_ERROR);
      throw AspNetException();
    }
  this->soap_struct_to_corba_struct (agg, "element", corbaName + "Element",
                                     os);
  os << "CORBA::ULong len = " << corbaName << ".length();\n";
  os << corbaName << ".length(len + 1);\n";
  os << corbaName << "[len] = " << corbaName << "Element;\n";
  os << "}";
}

void
AspNetVisitor::soap_struct_to_corba_struct (const Aggregate& agg,
                                            const string& soapName,
                                            const string& corbaName,
                                            ofstream& os)
{
  set<Member> members = agg->getMember();
  for (set<Member>::iterator iter = members.begin();
       iter != members.end();
       ++iter)
    {
      Member member (*iter);
      MemberType memberType = member->getMemberType();
      string lhs = corbaName + "." + member->getName();
      string rhs ("CliStrToStdStr (");
      rhs += soapName + "->" + member->getName();
      rhs += ").c_str()";
      if (PredefinedType (memberType))
        {
          if (String (memberType))
            {
              os << lhs << " = " << "CORBA::string_dup (" << rhs << ");\n";
            }
          else
            {
              os << lhs << " = " << rhs << ";\n";
            }
        }
      else
        {
          stringstream msg;
          msg << "Unhandled CORBA type " << memberType->getName() << "in struct "
              << agg->getName() << endl;
          this->project_->consoleMsg (msg.str(), MSG_ERROR);
          throw AspNetException();
        }
    }
}
