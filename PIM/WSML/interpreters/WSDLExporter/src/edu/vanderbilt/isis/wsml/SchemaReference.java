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
 * Domain specific class of <code>SchemaReference</code>.
 */
public class SchemaReference extends MgaObject
{
	// meta information
	public static final String META_TYPE = "SchemaReference";
	public static final String META_TYPE_NS = "";
	private static UdmPseudoObject metaClass;

	/**
	 * Constructor.
	 * @param  upo The object that helps the initialization of the instance
	 * @param  metaDiagram The diagram of the data network
	 * @throws  UdmException If any Udm related exception occured
	 */
	protected SchemaReference(UdmPseudoObject upo, Diagram metaDiagram)
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
	 * @return  An instance of the class <code>SchemaReference</code>
	 * @throws  UdmException If any Udm related exception occured
	 */
	public static SchemaReference create(Schema parent)
		throws UdmException
	{
		Diagram metaDiagram = parent.getDiagram();
		return new SchemaReference(parent.createObject(META_TYPE, META_TYPE_NS), metaDiagram);
	}

	/* Accessing children */

	/**
	 * Return the child of type <code>Schema<code> of this container.
	 * @return  The child
	 * @throws  UdmException If any Udm related exception occured
	 */
	public Schema getSchemaChild()
		throws UdmException
	{
		UdmPseudoObjectContainer container = getChildren(null, Schema.META_TYPE, Schema.META_TYPE_NS);
		if (container.getLength() > 0)

			return (Schema)Utils.wrapWithSubclass(container.getAt(0), metaDiagram);
		return null;

	}

	/* Attribute setters, getters */

	/**
	 * Attribute for <code>schemaLocation</code>.
	 */
	public static final String schemaLocation = "schemaLocation";

	/**
	 * Sets the value of the attribute <code>schemaLocation</code> to a value specified by the parameter.
	 * @param _v The new value of the attribute
	 * @throws  UdmException If any Udm related exception occured
	 */
	public void setschemaLocation(String _v)
		throws UdmException
	{
		setStringVal(schemaLocation, _v);
	}

	/**
	 * Returns the value of the attribute <code>schemaLocation</code>.
	 * @return  The value
	 * @throws  UdmException If any Udm related exception occured
	 */
	public String getschemaLocation()
		throws UdmException
	{
		return getStringVal(schemaLocation);
	}

	/**
	 * Attribute for <code>id</code>.
	 */
	public static final String id = "id";

	/**
	 * Sets the value of the attribute <code>id</code> to a value specified by the parameter.
	 * @param _v The new value of the attribute
	 * @throws  UdmException If any Udm related exception occured
	 */
	public void setid(String _v)
		throws UdmException
	{
		setStringVal(id, _v);
	}

	/**
	 * Returns the value of the attribute <code>id</code>.
	 * @return  The value
	 * @throws  UdmException If any Udm related exception occured
	 */
	public String getid()
		throws UdmException
	{
		return getStringVal(id);
	}

	/* Associations */

}
