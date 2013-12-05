<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="xml" omit-xml-declaration="no" doctype-system="mga.dtd" indent="yes"/>

  <!--
        apply all templates starting from the root
    -->
  <xsl:template match="/">
    <xsl:apply-templates />
  </xsl:template>

  <!--
    @template SwapFacetDelegateRole

    Update the ComponentRef in a deployment plan to a ComponentInstanceRef.
    -->
  <xsl:template name="SwapFacetDelegateRole" match="connection[@kind='FacetDelegate']">
    <xsl:variable name="src" select="connpoint[@role='src']/@target" />
    <xsl:variable name="dst" select="connpoint[@role='dst']/@target" />

    <xsl:element name="{name ()}">
      <xsl:for-each select="@*">
        <xsl:copy />
      </xsl:for-each>

      <xsl:apply-templates select="name" />

      <xsl:element name="connpoint">
        <xsl:attribute name="role">src</xsl:attribute>
        <xsl:attribute name="target"><xsl:value-of select="$dst"/></xsl:attribute>
      </xsl:element>
      <xsl:element name="connpoint">
        <xsl:attribute name="role">dst</xsl:attribute>
        <xsl:attribute name="target">
          <xsl:value-of select="$src"/>
        </xsl:attribute>
      </xsl:element>
    </xsl:element>
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
