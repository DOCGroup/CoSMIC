#ifndef ASPNETVISITOR_H
#define ASPNETVISITOR_H

#include <BON.h>
#include <BONImpl.h>
#include <Extensions.h>
#include <GatewayGenerator/SIMLVisitor.h>
#include <string>
#include <exception>
#include <map>
#include <fstream>

using namespace PICML;
using namespace WSML;
using namespace SIML;
using std::string;
using std::ofstream;
using std::map;
using std::multimap;
using std::set;

class AspNetException
  : public std::exception
{};

class AspNetVisitor : public SIMLVisitor
{
public:
  AspNetVisitor (BON::Project& project, string outputFolder);
  virtual ~AspNetVisitor();
  virtual bool visitService (const Service& object );
  virtual bool visitPort (const WSML::Port& object);
  virtual bool visitPortProxy (const PortProxy& object );
private:
  string transform_name (const char* name);
  string idl_scoped_name (const BON::FCO& object);
  string wsdl_scoped_name (const BON::FCO& object, bool append = true);
  string basic_name (const PredefinedType& pdt);
  string asp_net_basic_name (const PredefinedType& pdt);
  void generate_operation_signature(const TwowayOperation& object,
                                    const string& prefix,
                                    ofstream& os);
  void generate_function_body (const TwowayOperation& oper,
                               ofstream& os);
  string get_file_name (const BON::FCO& object);
  void generate_header();
  void generate_source();
  void corba_struct_to_soap_struct (const Aggregate& agg,
                                    const string& soapName,
                                    const string& corbaName,
                                    ofstream& os);
  void soap_seq_to_corba_seq (const Collection& seq,
                              const string& soapName,
                              const string& corbaName,
                              ofstream& os);
  void soap_struct_to_corba_struct (const Aggregate& agg,
                                    const string& soapName,
                                    const string& corbaName,
                                    ofstream& os);
private:
  BON::Project& project_;
  string outputFolder_;
  ofstream header_;
  ofstream source_;
  // Used to generate the base interface names the service implements
  set<Binding> bindings_;
  set<Component> comps_;
  multimap<Component, ProvidedRequestPort> ports_;
  map<string, Object> interfaces_;
  map<Object, Component> parentComp_;
  map<TwowayOperation, string> port_;
  set<TwowayOperation> operations_;
  string targetNamespace_;
  string defName_;
  string serviceName_;
  bool gsoap_;
};

#endif // ASPNETVISITOR_H
