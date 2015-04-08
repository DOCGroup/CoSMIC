// -*- Java -*-

//=============================================================================
/**
 * @file        MgaEntityResolver.java
 *
 * @author      James H. Hill
 */
//=============================================================================

package edu.vanderbilt.dre;
import org.xml.sax.EntityResolver;
import org.xml.sax.InputSource;
import java.io.File;

/**
 * @class GmeEntityResolver
 *
 * Implementation of an EntityResolver for migrating GME models. The
 * resolver is hardcoded to locate mga.dtd in the following location:
 *
 *    $COSMIC_ROOT/includes/GME/mga.dtd
 */
public class MgaEntityResolver implements EntityResolver
{
  /**
   * Callback method for resolving the entity
   *
   * @param[in]       publicId        not used
   * @param[in]       systemId        System id to resolve
   * @return          The entity resolver as an input source.
   */
  public InputSource resolveEntity (String publicId, String systemId)
  {
    try
    {
      // We only care about the mga.dtd systemId.
      if (!systemId.endsWith ("mga.dtd"))
        return null;
 
      // Get the COSMIC_ROOT environment variable. Use it to
      // construct the location of mga.dtd.
      final String COSMIC_ROOT = System.getenv ("COSMIC_ROOT");
      final String mgaPath = "file:///" + COSMIC_ROOT + "/includes/GME/mga.dtd";
     
      return new InputSource (mgaPath);
    }
    catch (Exception ex)
    {
      ex.printStackTrace ();
      return null;
    }
  }
}
