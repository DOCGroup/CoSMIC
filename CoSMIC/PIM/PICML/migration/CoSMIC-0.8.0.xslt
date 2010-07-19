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
    @template UpdateToDataValue

    Update the old DataType to a DataValue element. This will also move
    the DataValue attribute to the DataValue element.
    -->
  <xsl:template name="UpdateToDataValue" match="model[@kind='Property']/reference[@kind='DataType']">
    <!-- copy all the children elements -->
    <xsl:element name="{name()}">

      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind'">
            <xsl:attribute name="kind">DataValue</xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='role'">
            <xsl:attribute name="kind">DataValue</xsl:attribute>
          </xsl:when>
          <xsl:otherwise>
            <xsl:copy />
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>

      <!-- perform the default behavior for the remainder of this node -->
      <xsl:element name="name">
        <xsl:value-of select="../name" />
      </xsl:element>

      <!-- copy over the DataValue in the DataType element -->
      <xsl:variable name="value" select="../attribute[@kind='DataValue']/value" />
      <xsl:element name="attribute">
        <xsl:attribute name="kind">Value</xsl:attribute>

        <xsl:element name="value">
          <xsl:value-of select="$value" />
        </xsl:element>
      </xsl:element>

    </xsl:element>
  </xsl:template>

  <!--
    @template RemoveDataValueAttribute

    Update the old DataType to a DataValue element. This will also move
    the DataValue attribute to the DataValue element.
    -->
  <xsl:template name="RemoveDataValueAttribute" match="attribute[@kind='DataValue']" />

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
