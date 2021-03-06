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
 * Domain specific class of <code>SOAPAddress</code>.
 */
public class SOAPAddress extends ExtensiblePort
{
	// meta information
	public static final String META_TYPE = "SOAPAddress";
	public static final String META_TYPE_NS = "";
	private static UdmPseudoObject metaClass;

	/**
	 * Constructor.
	 * @param  upo The object that helps the initialization of the instance
	 * @param  metaDiagram The diagram of the data network
	 * @throws  UdmException If any Udm related exception occured
	 */
	protected SOAPAddress(UdmPseudoObject upo, Diagram metaDiagram)
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
	 * @return  An instance of the class <code>SOAPAddress</code>
	 * @throws  UdmException If any Udm related exception occured
	 */
	public static SOAPAddress create(Port parent)
		throws UdmException
	{
		Diagram metaDiagram = parent.getDiagram();
		return new SOAPAddress(parent.createObject(META_TYPE, META_TYPE_NS), metaDiagram);
	}

	/* Accessing children */

	/* Attribute setters, getters */

	/**
	 * Attribute for <code>location</code>.
	 */
	public static final String location = "location";

	/**
	 * Sets the value of the attribute <code>location</code> to a value specified by the parameter.
	 * @param _v The new value of the attribute
	 * @throws  UdmException If any Udm related exception occured
	 */
	public void setlocation(String _v)
		throws UdmException
	{
		setStringVal(location, _v);
	}

	/**
	 * Returns the value of the attribute <code>location</code>.
	 * @return  The value
	 * @throws  UdmException If any Udm related exception occured
	 */
	public String getlocation()
		throws UdmException
	{
		return getStringVal(location);
	}

	/* Associations */

}
