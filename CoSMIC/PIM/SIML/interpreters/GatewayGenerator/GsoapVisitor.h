#ifndef GSOAPVISITOR_H
#define GSOAPVISITOR_H

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
using std::set;

class GsoapException
  : public std::exception
{};

class GsoapVisitor : public SIMLVisitor
{
public:
  GsoapVisitor (BON::Project& project, string outputFolder);
  virtual ~GsoapVisitor();
  virtual bool visitService( const Service& object );
  virtual bool visitSystem( const System& object);
  virtual bool visitPortProxy( const PortProxy& object );
  virtual bool visitTwowayOperation(const TwowayOperation& object);

private:
  string transform_name (const char* name);
  const char* utf8(char* t, const char* s);
  string idl_scoped_name (const BON::FCO& object);
  string wsdl_scoped_name (const BON::FCO& object);
  string basic_name (const PredefinedType& pdt);
  string get_file_name (const BON::FCO& object);
  void generate_header();
  void generate_driver();
  void generate_source();
  void corba_struct_to_soap_struct (const Aggregate& agg,
                                    const string& soapName,
                                    const string& corbaName,
                                    ofstream& os);
  void soap_seq_to_corba_seq (const Collection& seq,
                              const string& soapName,
                              const string& corbaName,
                              ofstream& os);
  void corba_seq_to_soap_seq (const Collection& seq,
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
  ofstream driver_;
  map<string, Object> interfaces_;
  set<TwowayOperation> operations_;
  map<TwowayOperation, string> port_;
  string targetNamespace_;
  string defName_;
  string serviceName_;
  Component comp_;
  bool gsoap_;
};

#endif /* GSOAPVISITOR_H */
