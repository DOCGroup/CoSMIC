<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="xml" omit-xml-declaration="no" doctype-system="mga.dtd" indent="yes"/>

  <!--
        apply all templates starting from the root
    -->
  <xsl:template match="/">
    <xsl:apply-templates />
  </xsl:template>

  <!-- remove derived types with unknown base types -->
  <xsl:template name="derived-type" match="*[@derivedfrom]">
    <xsl:variable name="derived" select="@derivedfrom" />

    <xsl:if test="//@id=$derived" >
      <xsl:copy>
        <xsl:apply-templates select="@*" />
        <xsl:apply-templates />
      </xsl:copy>
    </xsl:if>
  </xsl:template>

  <!--
  ===========================================================================
  * Purpose:
  *    
  * Remove null references from the model.
  ===========================================================================
  -->
  <xsl:template name="remove-null-reference" match="*[@referred]">
    <xsl:variable name="ref-target" select="@referred" />

    <xsl:if test="//@id=$ref-target" >
      <xsl:copy>
        <xsl:apply-templates select="@*" />
        <xsl:apply-templates />
      </xsl:copy>
    </xsl:if>
  </xsl:template>

  <!-- 
  ===========================================================================
  * Purpose:
  *    
  * Remove all connection elements that do not have a @target in 
  * the project.
  ===========================================================================
  -->
  <xsl:template name="remove-connection" match="connection">
    <xsl:choose>
      <xsl:when test="@derivedfrom">
        <xsl:call-template name="derived-type" />
      </xsl:when>
      <xsl:otherwise>
        <xsl:variable name="targets" select=".//@target" />

        <!-- we must have two connection points and we must the target
             of both connections must be present somewhere in the model -->
        <xsl:if test="count($targets)=2 and //@id=$targets[1] and //@id=$targets[2]">
          <xsl:copy>
            <xsl:apply-templates select="@*" />
            <xsl:apply-templates />
          </xsl:copy>
        </xsl:if>
      </xsl:otherwise>
    </xsl:choose>
    <xsl:variable name="ref-target" select="@referred" />

    <xsl:if test="//@id=$ref-target" >
      <xsl:copy>
        <xsl:apply-templates select="@*" />
        <xsl:apply-templates />
      </xsl:copy>
    </xsl:if>
  </xsl:template>

  <!--
        Default transformation for all nodes
    -->
  <xsl:template match="*|@*">
    <xsl:copy>
      <xsl:apply-templates select="@*"/>
      <xsl:apply-templates />
    </xsl:copy>
  </xsl:template>

</xsl:stylesheet>
