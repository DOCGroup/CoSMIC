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
 * Utility class for diagram <code>WSML</code>.
 */ 
public class Utils
{
	/**
	 * Generates a domain specific object from the object specified by the parameter.
	 * @param  obj The generic udm object
	 * @param  diagram The diagram of the data network that contains <code>obj</code>
	 * @return  The domain specific object
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public static UdmPseudoObject wrapWithSubclass(UdmPseudoObject obj, Diagram diagram)
		 throws UdmException
	{
		String type = obj.getType();
		if (Element.META_TYPE.equals(type))
		{
			return new Element(obj, diagram);
		}
		else
		if (SchemaReference.META_TYPE.equals(type))
		{
			return new SchemaReference(obj, diagram);
		}
		else
		if (SchemaImport.META_TYPE.equals(type))
		{
			return new SchemaImport(obj, diagram);
		}
		else
		if (Schema.META_TYPE.equals(type))
		{
			return new Schema(obj, diagram);
		}
		else
		if (Attribute.META_TYPE.equals(type))
		{
			return new Attribute(obj, diagram);
		}
		else
		if (XsNmTokens.META_TYPE.equals(type))
		{
			return new XsNmTokens(obj, diagram);
		}
		else
		if (XsNcName.META_TYPE.equals(type))
		{
			return new XsNcName(obj, diagram);
		}
		else
		if (XsToken.META_TYPE.equals(type))
		{
			return new XsToken(obj, diagram);
		}
		else
		if (XsId.META_TYPE.equals(type))
		{
			return new XsId(obj, diagram);
		}
		else
		if (XsNegativeInteger.META_TYPE.equals(type))
		{
			return new XsNegativeInteger(obj, diagram);
		}
		else
		if (XsNonNegativeInteger.META_TYPE.equals(type))
		{
			return new XsNonNegativeInteger(obj, diagram);
		}
		else
		if (XsPositiveInteger.META_TYPE.equals(type))
		{
			return new XsPositiveInteger(obj, diagram);
		}
		else
		if (XsName.META_TYPE.equals(type))
		{
			return new XsName(obj, diagram);
		}
		else
		if (XsIdRefs.META_TYPE.equals(type))
		{
			return new XsIdRefs(obj, diagram);
		}
		else
		if (XsInteger.META_TYPE.equals(type))
		{
			return new XsInteger(obj, diagram);
		}
		else
		if (XsNormalizedString.META_TYPE.equals(type))
		{
			return new XsNormalizedString(obj, diagram);
		}
		else
		if (XsEntity.META_TYPE.equals(type))
		{
			return new XsEntity(obj, diagram);
		}
		else
		if (XsNonPositiveInteger.META_TYPE.equals(type))
		{
			return new XsNonPositiveInteger(obj, diagram);
		}
		else
		if (XsShort.META_TYPE.equals(type))
		{
			return new XsShort(obj, diagram);
		}
		else
		if (XsUnsignedInt.META_TYPE.equals(type))
		{
			return new XsUnsignedInt(obj, diagram);
		}
		else
		if (XsIdRef.META_TYPE.equals(type))
		{
			return new XsIdRef(obj, diagram);
		}
		else
		if (XsLanguage.META_TYPE.equals(type))
		{
			return new XsLanguage(obj, diagram);
		}
		else
		if (XsUnsignedByte.META_TYPE.equals(type))
		{
			return new XsUnsignedByte(obj, diagram);
		}
		else
		if (XsInt.META_TYPE.equals(type))
		{
			return new XsInt(obj, diagram);
		}
		else
		if (XsNmToken.META_TYPE.equals(type))
		{
			return new XsNmToken(obj, diagram);
		}
		else
		if (XsLong.META_TYPE.equals(type))
		{
			return new XsLong(obj, diagram);
		}
		else
		if (XsEntities.META_TYPE.equals(type))
		{
			return new XsEntities(obj, diagram);
		}
		else
		if (XsByte.META_TYPE.equals(type))
		{
			return new XsByte(obj, diagram);
		}
		else
		if (XsUnsignedLong.META_TYPE.equals(type))
		{
			return new XsUnsignedLong(obj, diagram);
		}
		else
		if (XsUnsignedShort.META_TYPE.equals(type))
		{
			return new XsUnsignedShort(obj, diagram);
		}
		else
		if (BodyParts.META_TYPE.equals(type))
		{
			return new BodyParts(obj, diagram);
		}
		else
		if (SOAPFaultExtension.META_TYPE.equals(type))
		{
			return new SOAPFaultExtension(obj, diagram);
		}
		else
		if (HeaderBinding.META_TYPE.equals(type))
		{
			return new HeaderBinding(obj, diagram);
		}
		else
		if (HeaderPart.META_TYPE.equals(type))
		{
			return new HeaderPart(obj, diagram);
		}
		else
		if (BodyBinding.META_TYPE.equals(type))
		{
			return new BodyBinding(obj, diagram);
		}
		else
		if (HeaderMessage.META_TYPE.equals(type))
		{
			return new HeaderMessage(obj, diagram);
		}
		else
		if (XsString.META_TYPE.equals(type))
		{
			return new XsString(obj, diagram);
		}
		else
		if (XsQName.META_TYPE.equals(type))
		{
			return new XsQName(obj, diagram);
		}
		else
		if (XsGYearMonth.META_TYPE.equals(type))
		{
			return new XsGYearMonth(obj, diagram);
		}
		else
		if (XsDate.META_TYPE.equals(type))
		{
			return new XsDate(obj, diagram);
		}
		else
		if (XsGMonthDay.META_TYPE.equals(type))
		{
			return new XsGMonthDay(obj, diagram);
		}
		else
		if (XsFloat.META_TYPE.equals(type))
		{
			return new XsFloat(obj, diagram);
		}
		else
		if (XsTime.META_TYPE.equals(type))
		{
			return new XsTime(obj, diagram);
		}
		else
		if (XsBase64Binary.META_TYPE.equals(type))
		{
			return new XsBase64Binary(obj, diagram);
		}
		else
		if (XsDouble.META_TYPE.equals(type))
		{
			return new XsDouble(obj, diagram);
		}
		else
		if (XsBoolean.META_TYPE.equals(type))
		{
			return new XsBoolean(obj, diagram);
		}
		else
		if (XsGMonth.META_TYPE.equals(type))
		{
			return new XsGMonth(obj, diagram);
		}
		else
		if (XsHexBinary.META_TYPE.equals(type))
		{
			return new XsHexBinary(obj, diagram);
		}
		else
		if (XsDuration.META_TYPE.equals(type))
		{
			return new XsDuration(obj, diagram);
		}
		else
		if (XsNotation.META_TYPE.equals(type))
		{
			return new XsNotation(obj, diagram);
		}
		else
		if (XsGDay.META_TYPE.equals(type))
		{
			return new XsGDay(obj, diagram);
		}
		else
		if (SchemaBuiltins.META_TYPE.equals(type))
		{
			return new SchemaBuiltins(obj, diagram);
		}
		else
		if (XsDecimal.META_TYPE.equals(type))
		{
			return new XsDecimal(obj, diagram);
		}
		else
		if (XsDateTime.META_TYPE.equals(type))
		{
			return new XsDateTime(obj, diagram);
		}
		else
		if (XsAnyUri.META_TYPE.equals(type))
		{
			return new XsAnyUri(obj, diagram);
		}
		else
		if (XsGYear.META_TYPE.equals(type))
		{
			return new XsGYear(obj, diagram);
		}
		else
		if (SOAPFault.META_TYPE.equals(type))
		{
			return new SOAPFault(obj, diagram);
		}
		else
		if (SOAPOperation.META_TYPE.equals(type))
		{
			return new SOAPOperation(obj, diagram);
		}
		else
		if (SOAPBinding.META_TYPE.equals(type))
		{
			return new SOAPBinding(obj, diagram);
		}
		else
		if (SOAPAddress.META_TYPE.equals(type))
		{
			return new SOAPAddress(obj, diagram);
		}
		else
		if (SOAPHeader.META_TYPE.equals(type))
		{
			return new SOAPHeader(obj, diagram);
		}
		else
		if (SOAPHeaderFault.META_TYPE.equals(type))
		{
			return new SOAPHeaderFault(obj, diagram);
		}
		else
		if (SOAPBody.META_TYPE.equals(type))
		{
			return new SOAPBody(obj, diagram);
		}
		else
		if (InputRef.META_TYPE.equals(type))
		{
			return new InputRef(obj, diagram);
		}
		else
		if (OutputMessage.META_TYPE.equals(type))
		{
			return new OutputMessage(obj, diagram);
		}
		else
		if (RequestResponseOperation.META_TYPE.equals(type))
		{
			return new RequestResponseOperation(obj, diagram);
		}
		else
		if (SolicitResponseOperation.META_TYPE.equals(type))
		{
			return new SolicitResponseOperation(obj, diagram);
		}
		else
		if (Fault.META_TYPE.equals(type))
		{
			return new Fault(obj, diagram);
		}
		else
		if (OutputRef.META_TYPE.equals(type))
		{
			return new OutputRef(obj, diagram);
		}
		else
		if (NotificationOperation.META_TYPE.equals(type))
		{
			return new NotificationOperation(obj, diagram);
		}
		else
		if (FaultRef.META_TYPE.equals(type))
		{
			return new FaultRef(obj, diagram);
		}
		else
		if (InputMessage.META_TYPE.equals(type))
		{
			return new InputMessage(obj, diagram);
		}
		else
		if (FaultMessage.META_TYPE.equals(type))
		{
			return new FaultMessage(obj, diagram);
		}
		else
		if (OneWayOperation.META_TYPE.equals(type))
		{
			return new OneWayOperation(obj, diagram);
		}
		else
		if (MessageRef.META_TYPE.equals(type))
		{
			return new MessageRef(obj, diagram);
		}
		else
		if (Output.META_TYPE.equals(type))
		{
			return new Output(obj, diagram);
		}
		else
		if (Input.META_TYPE.equals(type))
		{
			return new Input(obj, diagram);
		}
		else
		if (Messages.META_TYPE.equals(type))
		{
			return new Messages(obj, diagram);
		}
		else
		if (Definitions.META_TYPE.equals(type))
		{
			return new Definitions(obj, diagram);
		}
		else
		if (Types.META_TYPE.equals(type))
		{
			return new Types(obj, diagram);
		}
		else
		if (Message.META_TYPE.equals(type))
		{
			return new Message(obj, diagram);
		}
		else
		if (PortType.META_TYPE.equals(type))
		{
			return new PortType(obj, diagram);
		}
		else
		if (Part.META_TYPE.equals(type))
		{
			return new Part(obj, diagram);
		}
		else
		if (Binding.META_TYPE.equals(type))
		{
			return new Binding(obj, diagram);
		}
		else
		if (Documentation.META_TYPE.equals(type))
		{
			return new Documentation(obj, diagram);
		}
		else
		if (BindingPortType.META_TYPE.equals(type))
		{
			return new BindingPortType(obj, diagram);
		}
		else
		if (Port.META_TYPE.equals(type))
		{
			return new Port(obj, diagram);
		}
		else
		if (Service.META_TYPE.equals(type))
		{
			return new Service(obj, diagram);
		}
		else
		if (PortBinding.META_TYPE.equals(type))
		{
			return new PortBinding(obj, diagram);
		}
		else
		if (BindingOperation.META_TYPE.equals(type))
		{
			return new BindingOperation(obj, diagram);
		}
		else
		if (PartRef.META_TYPE.equals(type))
		{
			return new PartRef(obj, diagram);
		}
		else
		if (OperationRef.META_TYPE.equals(type))
		{
			return new OperationRef(obj, diagram);
		}
		else
		if (Import.META_TYPE.equals(type))
		{
			return new Import(obj, diagram);
		}
		else
		if (BindingRef.META_TYPE.equals(type))
		{
			return new BindingRef(obj, diagram);
		}
		else
		if (BindsOperation.META_TYPE.equals(type))
		{
			return new BindsOperation(obj, diagram);
		}
		else
		if (RootFolder.META_TYPE.equals(type))
		{
			return new RootFolder(obj, diagram);
		}
		else
		{
			throw new UdmException("Unexpected type: '" + type + "'", true);
		}
	}

	/**
	 * Generates an array of domain specific objects from the objects specified by the parameter.
	 * @param  objs The generic udm objects
	 * @param  arrayClass The type of the array class
	 * @param  diagram The diagram of the data network that contains <code>obj</code>
	 * @return  The array of domain specific objects
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public static UdmPseudoObject[] wrapWithSubclass(UdmPseudoObjectContainer objs, Class arrayClass, Diagram diagram) 
		 throws UdmException 
	{
		if (!UdmPseudoObject.class.isAssignableFrom(arrayClass)) 
		{
			throw new IllegalArgumentException("" + arrayClass + " is not a subtype of "+ UdmPseudoObject.class.getName());
		}
		UdmPseudoObject[] res = (UdmPseudoObject[]) java.lang.reflect.Array.newInstance(arrayClass, objs.getLength());
		for (int i = 0; i < res.length; i++) 
		{
			UdmPseudoObject obj = objs.getAt(i);
			if (obj != null) 
			{
				res[i] = wrapWithSubclass(obj, diagram);
			}
		}
		return res;
	}
}
