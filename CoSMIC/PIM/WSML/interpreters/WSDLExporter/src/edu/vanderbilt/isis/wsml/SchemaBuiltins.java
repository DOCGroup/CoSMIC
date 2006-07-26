/* Generated on Tue Jul 25 22:52:12 2006 */

/* This is a generalt file, do not modify its content.
 * Copyright (c) Vanderbilt University, 2000-2005
 * ALL RIGHTS RESERVED
 * Vanderbilt University disclaims all warranties with regard to this 
 * software, including all implied warranties of merchantability and 
 * fitness.  In no event shall Vanderbilt University be liable for any 
 * special, indirect or consequential damages or any damages whatsoever
 * resulting from loss of use, data or profits, whether in an action of
 * contract, negligence or other tortious action, arising out of or in 
 * connection with the use or performance of this software.	
 */

package edu.vanderbilt.isis.wsml;

import edu.vanderbilt.isis.udm.*;

/**
 * Domain specific class of <code>SchemaBuiltins</code>.
 */ 
public class SchemaBuiltins extends MgaObject
{
	// meta information
	public static final String META_TYPE = "SchemaBuiltins";
	public static final String META_TYPE_NS = "";
	private static UdmPseudoObject metaClass;

	/**
	 * Constructor.
	 * @param  upo The object that helps the initialization of the instance 
	 * @param  metaDiagram The diagram of the data network
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	protected SchemaBuiltins(UdmPseudoObject upo, Diagram metaDiagram) 
		throws UdmException
	{
		super(upo, metaDiagram);
	}

	/**
	 * Returns the meta class.
	 * @return  The meta class
	 */ 
	UdmPseudoObject getMetaClass()
	{
		return metaClass;
	}

	/* Construction */

	/**
	 * Creates an instance of the class in the container specified by the parameter. 
	 * @param  parent The parent container
	 * @return  An instance of the class <code>SchemaBuiltins</code>
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public static SchemaBuiltins create(RootFolder parent) 
		throws UdmException 
	{
		Diagram metaDiagram = parent.getDiagram();
		return new SchemaBuiltins(parent.createObject(META_TYPE, META_TYPE_NS), metaDiagram);
	}

	/* Accessing children */

	/**
	 * Returns all the children of type <code>XsNmTokens<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsNmTokens[] getXsNmTokensChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsNmTokens.META_TYPE, XsNmTokens.META_TYPE_NS);
		XsNmTokens[] res = new XsNmTokens[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsNmTokens)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsNcName<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsNcName[] getXsNcNameChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsNcName.META_TYPE, XsNcName.META_TYPE_NS);
		XsNcName[] res = new XsNcName[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsNcName)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsToken<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsToken[] getXsTokenChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsToken.META_TYPE, XsToken.META_TYPE_NS);
		XsToken[] res = new XsToken[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsToken)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsId<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsId[] getXsIdChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsId.META_TYPE, XsId.META_TYPE_NS);
		XsId[] res = new XsId[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsId)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsNegativeInteger<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsNegativeInteger[] getXsNegativeIntegerChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsNegativeInteger.META_TYPE, XsNegativeInteger.META_TYPE_NS);
		XsNegativeInteger[] res = new XsNegativeInteger[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsNegativeInteger)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsNonNegativeInteger<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsNonNegativeInteger[] getXsNonNegativeIntegerChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsNonNegativeInteger.META_TYPE, XsNonNegativeInteger.META_TYPE_NS);
		XsNonNegativeInteger[] res = new XsNonNegativeInteger[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsNonNegativeInteger)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsPositiveInteger<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsPositiveInteger[] getXsPositiveIntegerChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsPositiveInteger.META_TYPE, XsPositiveInteger.META_TYPE_NS);
		XsPositiveInteger[] res = new XsPositiveInteger[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsPositiveInteger)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsName<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsName[] getXsNameChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsName.META_TYPE, XsName.META_TYPE_NS);
		XsName[] res = new XsName[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsName)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsIdRefs<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsIdRefs[] getXsIdRefsChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsIdRefs.META_TYPE, XsIdRefs.META_TYPE_NS);
		XsIdRefs[] res = new XsIdRefs[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsIdRefs)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsInteger<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsInteger[] getXsIntegerChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsInteger.META_TYPE, XsInteger.META_TYPE_NS);
		XsInteger[] res = new XsInteger[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsInteger)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsNormalizedString<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsNormalizedString[] getXsNormalizedStringChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsNormalizedString.META_TYPE, XsNormalizedString.META_TYPE_NS);
		XsNormalizedString[] res = new XsNormalizedString[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsNormalizedString)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsEntity<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsEntity[] getXsEntityChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsEntity.META_TYPE, XsEntity.META_TYPE_NS);
		XsEntity[] res = new XsEntity[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsEntity)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsNonPositiveInteger<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsNonPositiveInteger[] getXsNonPositiveIntegerChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsNonPositiveInteger.META_TYPE, XsNonPositiveInteger.META_TYPE_NS);
		XsNonPositiveInteger[] res = new XsNonPositiveInteger[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsNonPositiveInteger)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsShort<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsShort[] getXsShortChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsShort.META_TYPE, XsShort.META_TYPE_NS);
		XsShort[] res = new XsShort[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsShort)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsUnsignedInt<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsUnsignedInt[] getXsUnsignedIntChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsUnsignedInt.META_TYPE, XsUnsignedInt.META_TYPE_NS);
		XsUnsignedInt[] res = new XsUnsignedInt[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsUnsignedInt)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsIdRef<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsIdRef[] getXsIdRefChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsIdRef.META_TYPE, XsIdRef.META_TYPE_NS);
		XsIdRef[] res = new XsIdRef[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsIdRef)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsLanguage<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsLanguage[] getXsLanguageChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsLanguage.META_TYPE, XsLanguage.META_TYPE_NS);
		XsLanguage[] res = new XsLanguage[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsLanguage)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsUnsignedByte<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsUnsignedByte[] getXsUnsignedByteChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsUnsignedByte.META_TYPE, XsUnsignedByte.META_TYPE_NS);
		XsUnsignedByte[] res = new XsUnsignedByte[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsUnsignedByte)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsInt<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsInt[] getXsIntChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsInt.META_TYPE, XsInt.META_TYPE_NS);
		XsInt[] res = new XsInt[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsInt)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsNmToken<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsNmToken[] getXsNmTokenChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsNmToken.META_TYPE, XsNmToken.META_TYPE_NS);
		XsNmToken[] res = new XsNmToken[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsNmToken)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsLong<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsLong[] getXsLongChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsLong.META_TYPE, XsLong.META_TYPE_NS);
		XsLong[] res = new XsLong[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsLong)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsEntities<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsEntities[] getXsEntitiesChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsEntities.META_TYPE, XsEntities.META_TYPE_NS);
		XsEntities[] res = new XsEntities[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsEntities)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsByte<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsByte[] getXsByteChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsByte.META_TYPE, XsByte.META_TYPE_NS);
		XsByte[] res = new XsByte[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsByte)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsUnsignedLong<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsUnsignedLong[] getXsUnsignedLongChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsUnsignedLong.META_TYPE, XsUnsignedLong.META_TYPE_NS);
		XsUnsignedLong[] res = new XsUnsignedLong[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsUnsignedLong)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsUnsignedShort<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsUnsignedShort[] getXsUnsignedShortChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsUnsignedShort.META_TYPE, XsUnsignedShort.META_TYPE_NS);
		XsUnsignedShort[] res = new XsUnsignedShort[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsUnsignedShort)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsString<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsString[] getXsStringChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsString.META_TYPE, XsString.META_TYPE_NS);
		XsString[] res = new XsString[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsString)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsQName<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsQName[] getXsQNameChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsQName.META_TYPE, XsQName.META_TYPE_NS);
		XsQName[] res = new XsQName[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsQName)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsGYearMonth<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsGYearMonth[] getXsGYearMonthChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsGYearMonth.META_TYPE, XsGYearMonth.META_TYPE_NS);
		XsGYearMonth[] res = new XsGYearMonth[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsGYearMonth)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsDate<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsDate[] getXsDateChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsDate.META_TYPE, XsDate.META_TYPE_NS);
		XsDate[] res = new XsDate[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsDate)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsGMonthDay<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsGMonthDay[] getXsGMonthDayChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsGMonthDay.META_TYPE, XsGMonthDay.META_TYPE_NS);
		XsGMonthDay[] res = new XsGMonthDay[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsGMonthDay)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsFloat<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsFloat[] getXsFloatChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsFloat.META_TYPE, XsFloat.META_TYPE_NS);
		XsFloat[] res = new XsFloat[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsFloat)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsTime<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsTime[] getXsTimeChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsTime.META_TYPE, XsTime.META_TYPE_NS);
		XsTime[] res = new XsTime[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsTime)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsBase64Binary<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsBase64Binary[] getXsBase64BinaryChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsBase64Binary.META_TYPE, XsBase64Binary.META_TYPE_NS);
		XsBase64Binary[] res = new XsBase64Binary[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsBase64Binary)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsDouble<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsDouble[] getXsDoubleChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsDouble.META_TYPE, XsDouble.META_TYPE_NS);
		XsDouble[] res = new XsDouble[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsDouble)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsBoolean<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsBoolean[] getXsBooleanChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsBoolean.META_TYPE, XsBoolean.META_TYPE_NS);
		XsBoolean[] res = new XsBoolean[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsBoolean)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsGMonth<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsGMonth[] getXsGMonthChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsGMonth.META_TYPE, XsGMonth.META_TYPE_NS);
		XsGMonth[] res = new XsGMonth[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsGMonth)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsHexBinary<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsHexBinary[] getXsHexBinaryChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsHexBinary.META_TYPE, XsHexBinary.META_TYPE_NS);
		XsHexBinary[] res = new XsHexBinary[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsHexBinary)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsDuration<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsDuration[] getXsDurationChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsDuration.META_TYPE, XsDuration.META_TYPE_NS);
		XsDuration[] res = new XsDuration[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsDuration)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsNotation<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsNotation[] getXsNotationChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsNotation.META_TYPE, XsNotation.META_TYPE_NS);
		XsNotation[] res = new XsNotation[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsNotation)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsGDay<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsGDay[] getXsGDayChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsGDay.META_TYPE, XsGDay.META_TYPE_NS);
		XsGDay[] res = new XsGDay[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsGDay)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsDecimal<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsDecimal[] getXsDecimalChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsDecimal.META_TYPE, XsDecimal.META_TYPE_NS);
		XsDecimal[] res = new XsDecimal[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsDecimal)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsDateTime<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsDateTime[] getXsDateTimeChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsDateTime.META_TYPE, XsDateTime.META_TYPE_NS);
		XsDateTime[] res = new XsDateTime[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsDateTime)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsAnyUri<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsAnyUri[] getXsAnyUriChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsAnyUri.META_TYPE, XsAnyUri.META_TYPE_NS);
		XsAnyUri[] res = new XsAnyUri[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsAnyUri)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>XsGYear<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public XsGYear[] getXsGYearChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, XsGYear.META_TYPE, XsGYear.META_TYPE_NS);
		XsGYear[] res = new XsGYear[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (XsGYear)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/* Attribute setters, getters */

	/* Associations */

}
