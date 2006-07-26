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
 * Domain specific class of <code>IORef</code>.
 */ 
public abstract class IORef extends MgaObject
{
	// meta information
	/**
	 * Constructor.
	 * @param  upo The object that helps the initialization of the instance 
	 * @param  metaDiagram The diagram of the data network
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	protected IORef(UdmPseudoObject upo, Diagram metaDiagram) 
		throws UdmException
	{
		super(upo, metaDiagram);
	}

	/* Accessing children */

	/* Attribute setters, getters */

	/* Associations */

	/*
	 * Asoociation with role name <code>dstBodyBinding</code>.
	 */

	/**
	 * Sets the other end of the association with role name <code>dstBodyBinding</code>.
	 * @param a The other end of the association
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public void setdstBodyBinding(BodyBinding a)
		throws UdmException
	{
		setAssociation("dstBodyBinding", a, UdmHelper.CLASS_FROM_TARGET);
	}

	/**
	 * Returns the other end of the association with role name <code>dstBodyBinding</code>.
	 * @return The other end of the association
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public BodyBinding getdstBodyBinding()
		throws UdmException
	{
		UdmPseudoObject result = getSingleAssociatedObject("dstBodyBinding", UdmHelper.CLASS_FROM_TARGET);
		return (result == null) ? null : new BodyBinding(result, getDiagram());
	}

	/*
	 * Asoociation with role name <code>dstHeaderBinding</code>.
	 */

	/**
	 * Sets the other end of the association with role name <code>dstHeaderBinding</code>.
	 * @param a The other end of the association
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public void setdstHeaderBinding(HeaderBinding a)
		throws UdmException
	{
		setAssociation("dstHeaderBinding", a, UdmHelper.CLASS_FROM_TARGET);
	}

	/**
	 * Returns the other end of the association with role name <code>dstHeaderBinding</code>.
	 * @return The other end of the association
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public HeaderBinding getdstHeaderBinding()
		throws UdmException
	{
		UdmPseudoObject result = getSingleAssociatedObject("dstHeaderBinding", UdmHelper.CLASS_FROM_TARGET);
		return (result == null) ? null : new HeaderBinding(result, getDiagram());
	}

}
