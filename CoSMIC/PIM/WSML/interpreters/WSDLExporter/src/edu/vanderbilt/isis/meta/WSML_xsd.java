package edu.vanderbilt.isis.meta;


import edu.vanderbilt.isis.meta.WSML_xsd_0;
import edu.vanderbilt.isis.meta.WSML_xsd_1;

public class WSML_xsd {
	private static String str = new String();

	public static String getString()
	{
		if (str.length() == 0)
		{
			str += WSML_xsd_0.getString();
			str += WSML_xsd_1.getString();
		}
		return str;
	}
}
