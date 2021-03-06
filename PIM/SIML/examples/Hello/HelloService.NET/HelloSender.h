﻿#pragma once

#using <mscorlib.dll>
#using <System.dll>
#using <System.Xml.dll>
#using <System.Web.Services.dll>
#using <System.EnterpriseServices.dll>

using namespace System::Security::Permissions;
[assembly:SecurityPermissionAttribute(SecurityAction::RequestMinimum, SkipVerification=false)];
//
// This source code was auto-generated by wsdl, Version=2.0.50727.42.
//
namespace Hello {
    using namespace System::Diagnostics;
    using namespace System::Web::Services;
    using namespace System::ComponentModel;
    using namespace System::Web::Services::Protocols;
    using namespace System;
    using namespace System::Xml::Serialization;
 
    using namespace System;
    interface class IHelloSender_SE_push_message;
    interface class IHello_SE_Sender;
    interface class IHello_SE_Receiver;
 
 
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.42"),
    System::SerializableAttribute,
    System::Xml::Serialization::SoapTypeAttribute(TypeName=L"Hello.COLOR_SELECTION", Namespace=L"urn:Hello")]
    public enum class HelloCOLOR_SELECTION {
     
        /// <remarks/>
        empty,
     
        /// <remarks/>
        white,
     
        /// <remarks/>
        red,
     
        /// <remarks/>
        yellow,
    };
 
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.42"),
    System::Web::Services::WebServiceBindingAttribute(Name=L"Hello.Sender._SE_push_message", Namespace=L"urn:Hello")]
    public interface class IHelloSender_SE_push_message {
     
        /// <remarks/>
        [System::Web::Services::WebMethodAttribute]
        [System::Web::Services::Protocols::SoapRpcMethodAttribute(L"", RequestNamespace=L"urn:Hello", ResponseNamespace=L"urn:Hello")]
        [returnvalue: System::Xml::Serialization::SoapElementAttribute(L"_return")]
        System::String^  get_message() abstract;
    };
 
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.42"),
    System::Web::Services::WebServiceBindingAttribute(Name=L"Hello._SE_Sender", Namespace=L"urn:Hello")]
    public interface class IHello_SE_Sender {
     
        /// <remarks/>
        [System::Web::Services::WebMethodAttribute]
        [System::Web::Services::Protocols::SoapRpcMethodAttribute(L"", RequestNamespace=L"urn:Hello", ResponseNamespace=L"urn:Hello")]
        System::Void start() abstract;
     
        /// <remarks/>
        [System::Web::Services::WebMethodAttribute]
        [System::Web::Services::Protocols::SoapRpcMethodAttribute(L"", RequestNamespace=L"urn:Hello", ResponseNamespace=L"urn:Hello")]
        System::Void _set_color(Hello::HelloCOLOR_SELECTION __identifier(value)) abstract;
     
        /// <remarks/>
        [System::Web::Services::WebMethodAttribute]
        [System::Web::Services::Protocols::SoapRpcMethodAttribute(L"", RequestNamespace=L"urn:Hello", ResponseNamespace=L"urn:Hello")]
        [returnvalue: System::Xml::Serialization::SoapElementAttribute(L"_return")]
        Hello::HelloCOLOR_SELECTION _get_color() abstract;
     
        /// <remarks/>
        [System::Web::Services::WebMethodAttribute]
        [System::Web::Services::Protocols::SoapRpcMethodAttribute(L"", RequestNamespace=L"urn:Hello", ResponseNamespace=L"urn:Hello")]
        [returnvalue: System::Xml::Serialization::SoapElementAttribute(L"_return")]
        System::Int32 _get_hertz() abstract;
     
        /// <remarks/>
        [System::Web::Services::WebMethodAttribute]
        [System::Web::Services::Protocols::SoapRpcMethodAttribute(L"", RequestNamespace=L"urn:Hello", ResponseNamespace=L"urn:Hello")]
        System::Void _set_local_message(System::String^  __identifier(value)) abstract;
     
        /// <remarks/>
        [System::Web::Services::WebMethodAttribute]
        [System::Web::Services::Protocols::SoapRpcMethodAttribute(L"", RequestNamespace=L"urn:Hello", ResponseNamespace=L"urn:Hello")]
        [returnvalue: System::Xml::Serialization::SoapElementAttribute(L"_return")]
        System::String^  _get_local_message() abstract;
    };
 
    /// <remarks/>
    // CODEGEN: No methods were found in the WSDL for this protocol.
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.42"),
    System::Web::Services::WebServiceBindingAttribute(Name=L"Hello._SE_Receiver", Namespace=L"urn:Hello")]
    public interface class IHello_SE_Receiver {
    };
}
namespace Hello {
 
 
 
 
 
 
 
 
 
 
 
}
