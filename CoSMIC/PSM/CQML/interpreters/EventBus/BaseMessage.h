////////////////////////////////////////////////////////////////////////////////
// The Loki Library
// Copyright (c) 2001 by Andrei Alexandrescu
// This code accompanies the book:
// Alexandrescu, Andrei. "Modern C++ Design: Generic Programming and Design 
//     Patterns Applied". Copyright (c) 2001. Addison-Wesley.
// Permission to use, copy, modify, distribute and sell this software for any 
//     purpose is hereby granted without fee, provided that the above copyright 
//     notice appear in all copies and that both that copyright notice and this 
//     permission notice appear in supporting documentation.
// The author or Addison-Wesley Longman make no representations about the 
//     suitability of this software for any purpose. It is provided "as is" 
//     without express or implied warranty.
////////////////////////////////////////////////////////////////////////////////

// $Header: /cvsroot/loki-lib/loki/include/loki/MessageHandler.h,v 1.7 2006/01/16 19:05:09 rich_sposato Exp $

///  \defgroup MessageHandlerGroup MessageHandler

#ifndef LOKI_MESSAGEHANDLER_INC_
#define LOKI_MESSAGEHANDLER_INC_

//#include "Typelist.h"
//#include "HierarchyGenerators.h"

namespace CQML
{

////////////////////////////////////////////////////////////////////////////////
/// \class BaseMessageHandler
///  
/// \ingroup MessageHandlerGroup
/// The base class of any Acyclic MessageHandler
////////////////////////////////////////////////////////////////////////////////

    class BaseMessageHandler
    {
    public:
        virtual ~BaseMessageHandler() {}
    };
    
////////////////////////////////////////////////////////////////////////////////
/// \class MessageHandler
///
/// \ingroup MessageHandlerGroup
/// The building block of Acyclic MessageHandler
///
/// \par Usage
///
/// Defining the visitable class:
/// 
/// \code
/// class RasterBitmap : public BaseMessage<>
/// {
/// public:
///     LOKI_DEFINE_MESSAGE()
/// };
/// \endcode
///
/// Way 1 to define a visitor:
/// \code
/// class SomeMessageHandler : 
///     public BaseMessageHandler // required
///     public MessageHandler<RasterBitmap>,
///     public MessageHandler<Paragraph>
/// {
/// public:
///     void Visit(RasterBitmap&); // visit a RasterBitmap
///     void Visit(Paragraph &);   // visit a Paragraph
/// };
/// \endcode
///
/// Way 2 to define the visitor:
/// \code
/// class SomeMessageHandler : 
///     public BaseMessageHandler // required
///     public MessageHandler<LOKI_TYPELIST_2(RasterBitmap, Paragraph)>
/// {
/// public:
///     void Visit(RasterBitmap&); // visit a RasterBitmap
///     void Visit(Paragraph &);   // visit a Paragraph
/// };
/// \endcode
///
/// Way 3 to define the visitor:
/// \code
/// class SomeMessageHandler : 
///     public BaseMessageHandler // required
///     public MessageHandler<Seq<RasterBitmap, Paragraph>::Type>
/// {
/// public:
///     void Visit(RasterBitmap&); // visit a RasterBitmap
///     void Visit(Paragraph &);   // visit a Paragraph
/// };
/// \endcode
///
/// \par Using const visit functions:
///
/// Defining the visitable class (true for const):
/// 
/// \code
/// class RasterBitmap : public BaseMessage<void, DefaultCatchAll, true>
/// {
/// public:
///     LOKI_DEFINE_CONST_MESSAGE()
/// };
/// \endcode
///
/// Defining the visitor which only calls const member functions:
/// \code
/// class SomeMessageHandler : 
///     public BaseMessageHandler // required
///     public MessageHandler<RasterBitmap, void, true>,
/// {
/// public:
///     void Visit(const RasterBitmap&); // visit a RasterBitmap by a const member function
/// };
/// \endcode
///
/// \par Example:
///
/// test/MessageHandler/main.cpp 
////////////////////////////////////////////////////////////////////////////////

    template <class T, typename R = void, bool ConstVisit = false>
    class MessageHandler;

    template <class T, typename R>
    class MessageHandler<T, R, false>
    {
    public:
        typedef R ReturnType;
        typedef T ParamType;
        virtual ~MessageHandler() {}
        virtual ReturnType Visit(ParamType&) = 0;
    };

    template <class T, typename R>
    class MessageHandler<T, R, true>
    {
    public:
        typedef R ReturnType;
        typedef const T ParamType;
        virtual ~MessageHandler() {}
        virtual ReturnType Visit(ParamType&) = 0;
    };

////////////////////////////////////////////////////////////////////////////////
// class template MessageHandler (specialization)
// This specialization is not present in the book. It makes it easier to define
// MessageHandlers for multiple types in a shot by using a typelist. Example:
//
// class SomeMessageHandler : 
//     public BaseMessageHandler // required
//     public MessageHandler<LOKI_TYPELIST_2(RasterBitmap, Paragraph)>
// {
// public:
//     void Visit(RasterBitmap&); // visit a RasterBitmap
//     void Visit(Paragraph &);   // visit a Paragraph
// };
////////////////////////////////////////////////////////////////////////////////
/*
    template <class Head, class Tail, typename R>
    class MessageHandler<Typelist<Head, Tail>, R, false>
        : public MessageHandler<Head, R, false>, public MessageHandler<Tail, R, false>
    {
    public:
        typedef R ReturnType;
       // using MessageHandler<Head, R>::Visit;
       // using MessageHandler<Tail, R>::Visit;
    };
    
    template <class Head, typename R>
    class MessageHandler<Typelist<Head, NullType>, R, false> : public MessageHandler<Head, R, false>
    {
    public:
        typedef R ReturnType;
        using MessageHandler<Head, R, false>::Visit;
    };

    template <class Head, class Tail, typename R>
    class MessageHandler<Typelist<Head, Tail>, R, true>
        : public MessageHandler<Head, R, true>, public MessageHandler<Tail, R, true>
    {
    public:
        typedef R ReturnType;
       // using MessageHandler<Head, R>::Visit;
       // using MessageHandler<Tail, R>::Visit;
    };
    
    template <class Head, typename R>
    class MessageHandler<Typelist<Head, NullType>, R, true> : public MessageHandler<Head, R, true>
    {
    public:
        typedef R ReturnType;
        using MessageHandler<Head, R, true>::Visit;
    };


////////////////////////////////////////////////////////////////////////////////
// class template BaseMessageHandlerImpl
// Implements non-strict visitation (you can implement only part of the Visit
//     functions)
////////////////////////////////////////////////////////////////////////////////

    template <class TList, typename R = void> class BaseMessageHandlerImpl;

    template <class Head, class Tail, typename R>
    class BaseMessageHandlerImpl<Typelist<Head, Tail>, R>
        : public MessageHandler<Head, R>
        , public BaseMessageHandlerImpl<Tail, R>
    {
    public:
       // using BaseMessageHandlerImpl<Tail, R>::Visit;

        virtual R Visit(Head&)
        { return R(); }
    };
    
    template <class Head, typename R>
    class BaseMessageHandlerImpl<Typelist<Head, NullType>, R>
        : public MessageHandler<Head, R>
    {
    public:
        virtual R Visit(Head&)
        { return R(); }
    };
*/
////////////////////////////////////////////////////////////////////////////////
// class template BaseMessage
////////////////////////////////////////////////////////////////////////////////

template <typename R, typename Visited>
struct DefaultCatchAll
{
    static R OnUnknownMessageHandler(Visited&, BaseMessageHandler&)
    { return R(); }
};

////////////////////////////////////////////////////////////////////////////////
// class template BaseMessage
////////////////////////////////////////////////////////////////////////////////

    template 
    <
        typename R = void, 
        template <typename, class> class CatchAll = DefaultCatchAll,
        bool ConstMessage = false
    >
    class BaseMessage;

    template<typename R,template <typename, class> class CatchAll>
    class BaseMessage<R, CatchAll, false>
    {
    public:
        typedef R ReturnType;
        virtual ~BaseMessage() {}
        virtual ReturnType Accept(BaseMessageHandler&) = 0;
        
    protected: // give access only to the hierarchy
        template <class T>
        static ReturnType AcceptImpl(T& visited, BaseMessageHandler& guest)
        {
            // Apply the Acyclic MessageHandler
            if (MessageHandler<T,R>* p = dynamic_cast<MessageHandler<T,R>*>(&guest))
            {
                return p->Visit(visited);
            }
            return CatchAll<R, T>::OnUnknownMessageHandler(visited, guest);
        }
    };

    template<typename R,template <typename, class> class CatchAll>
    class BaseMessage<R, CatchAll, true>
    {
    public:
        typedef R ReturnType;
        virtual ~BaseMessage() {}
        virtual ReturnType Accept(BaseMessageHandler&) const = 0;
        
    protected: // give access only to the hierarchy
        template <class T>
        static ReturnType AcceptImpl(const T& visited, BaseMessageHandler& guest)
        {
            // Apply the Acyclic MessageHandler
            if (MessageHandler<T,R,true>* p = dynamic_cast<MessageHandler<T,R,true>*>(&guest))
            {
                return p->Visit(visited);
            }
            return CatchAll<R, T>::OnUnknownMessageHandler(const_cast<T&>(visited), guest);
        }
    };


////////////////////////////////////////////////////////////////////////////////
/// \def LOKI_DEFINE_MESSAGE()
/// \ingroup MessageHandlerGroup
/// Put it in every class that you want to make visitable 
/// (in addition to deriving it from BaseMessage<R>)
////////////////////////////////////////////////////////////////////////////////

#define LOKI_DEFINE_MESSAGE() \
    virtual ReturnType Accept(::Loki::BaseMessageHandler& guest) \
    { return AcceptImpl(*this, guest); }

////////////////////////////////////////////////////////////////////////////////
/// \def LOKI_DEFINE_CONST_MESSAGE()
/// \ingroup MessageHandlerGroup
/// Put it in every class that you want to make visitable by const member 
/// functions (in addition to deriving it from BaseMessage<R>)
////////////////////////////////////////////////////////////////////////////////

#define LOKI_DEFINE_CONST_MESSAGE() \
    virtual ReturnType Accept(::Loki::BaseMessageHandler& guest) const \
    { return AcceptImpl(*this, guest); }

////////////////////////////////////////////////////////////////////////////////
/// \class CyclicMessageHandler
///
/// \ingroup MessageHandlerGroup
/// Put it in every class that you want to make visitable (in addition to 
/// deriving it from BaseMessage<R>
////////////////////////////////////////////////////////////////////////////////
/*
    template <typename R, class TList>
    class CyclicMessageHandler : public MessageHandler<TList, R>
    {
    public:
        typedef R ReturnType;
        // using MessageHandler<TList, R>::Visit;
        
        template <class Visited>
        ReturnType GenericVisit(Visited& host)
        {
            MessageHandler<Visited, ReturnType>& subObj = *this;
            return subObj.Visit(host);
        }
    };
    
////////////////////////////////////////////////////////////////////////////////
/// \def LOKI_DEFINE_CYCLIC_MESSAGE(SomeMessageHandler)
/// \ingroup MessageHandlerGroup
/// Put it in every class that you want to make visitable by a cyclic visitor
////////////////////////////////////////////////////////////////////////////////

#define LOKI_DEFINE_CYCLIC_MESSAGE(SomeMessageHandler) \
    virtual SomeMessageHandler::ReturnType Accept(SomeMessageHandler& guest) \
    { return guest.GenericVisit(*this); }
*/
} // namespace EventBus

////////////////////////////////////////////////////////////////////////////////
// Change log:
// March     20, ????: add default argument DefaultCatchAll to BaseMessage
// June      20, 2001: ported by Nick Thurn to gcc 2.95.3. Kudos, Nick!!!
// September 28, 2004: replaced Loki:: with ::Loki:: in DEFINE_MESSAGE
// January    2, 2006: add support for visiting constant member functions, Peter Kümmel
////////////////////////////////////////////////////////////////////////////////

#endif // MESSAGEHANDLER_INC_

// $Log: MessageHandler.h,v $
// Revision 1.7  2006/01/16 19:05:09  rich_sposato
// Added cvs keywords.
//
