/* Generated on Tue Jul 17 20:35:06 2007 */

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
 * Domain specific class of <code>Service</code>.
 */ 
public class Service extends MgaObject
{
	// meta information
	public static final String META_TYPE = "Service";
	public static final String META_TYPE_NS = "";
	private static UdmPseudoObject metaClass;

	/**
	 * Constructor.
	 * @param  upo The object that helps the initialization of the instance 
	 * @param  metaDiagram The diagram of the data network
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	protected Service(UdmPseudoObject upo, Diagram metaDiagram) 
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
	 * @return  An instance of the class <code>Service</code>
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public static Service create(Definitions parent) 
		throws UdmException 
	{
		Diagram metaDiagram = parent.getDiagram();
		return new Service(parent.createObject(META_TYPE, META_TYPE_NS), metaDiagram);
	}

	/* Accessing children */

	/**
	 * Returns all the children of type <code>Port<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public Port[] getPortChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, Port.META_TYPE, Port.META_TYPE_NS);
		Port[] res = new Port[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (Port)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>BindingRef<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public BindingRef[] getBindingRefChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, BindingRef.META_TYPE, BindingRef.META_TYPE_NS);
		BindingRef[] res = new BindingRef[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (BindingRef)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/**
	 * Returns all the children of type <code>PortBinding<code> of this container. 
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public PortBinding[] getPortBindingChildren()
		throws UdmException 
	{
		UdmPseudoObjectContainer container = getChildren(null, PortBinding.META_TYPE, PortBinding.META_TYPE_NS);
		PortBinding[] res = new PortBinding[container.getLength()];
		for (int i=0; i < container.getLength(); i++) 
		{
			res[i] = (PortBinding)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/* Attribute setters, getters */

	/* Associations */

	/*
	 * Asoociation with role name <code>referedbyServiceRef</code>.
	 */

	/**
	 * Sets the other end of the association with role name <code>referedbyServiceRef</code>.
	 * @param a The other end of the association
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public void setreferedbyServiceRef(ServiceRef a)
		throws UdmException
	{
		setAssociation("referedbyServiceRef", a, UdmHelper.TARGET_FROM_PEER);
	}

	/**
	 * Returns the other end of the association with role name <code>referedbyServiceRef</code>.
	 * @return The other end of the association
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public ServiceRef getreferedbyServiceRef()
		throws UdmException
	{
		UdmPseudoObject result = getSingleAssociatedObject("referedbyServiceRef", UdmHelper.TARGET_FROM_PEER);
		return (result == null) ? null : new ServiceRef(result, getDiagram());
	}

}
