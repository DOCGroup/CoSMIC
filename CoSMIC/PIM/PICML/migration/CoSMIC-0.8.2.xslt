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
    @template UpdateToSimpleOrComplexProperty

    Updates the old Property element to either a SimpleProperty
    or ComplexProperty element.
    -->
  <xsl:template name="UpdateToSimpleOrComplexProperty" match="model[@kind='Property']">
    <xsl:variable name="count" select="count(reference[@kind='ComplexTypeReference'])" />

    <xsl:choose>
      <xsl:when test="$count=1">
        <!-- this is a complex type -->
        <xsl:element name="model">
          <xsl:for-each select="@*" >
            <xsl:choose>
              <xsl:when test="name()='kind' or name()='role'">
                <xsl:attribute name="{name()}">ComplexProperty</xsl:attribute>
              </xsl:when>
              <xsl:otherwise><xsl:copy /></xsl:otherwise>
            </xsl:choose>
          </xsl:for-each>

          <xsl:apply-templates />
        </xsl:element>
      </xsl:when>

      <xsl:otherwise>
        <!-- this is a simple type -->
        <xsl:variable name="referred" select="reference[@kind='DataValue']/@referred" />

        <xsl:element name="reference">
          <xsl:for-each select="@*" >
            <xsl:choose>
              <xsl:when test="name()='id'">
                <xsl:copy />
              </xsl:when>

              <xsl:when test="name()='kind' or name()='role'">
                <xsl:attribute name="{name()}">SimpleProperty</xsl:attribute>
              </xsl:when>

              <xsl:when test="name()='childrelidcntr'" />
            </xsl:choose>
          </xsl:for-each>

          <xsl:if test="$referred or $referred != ''">
            <xsl:attribute name="referred"><xsl:value-of select="$referred" /></xsl:attribute>
          </xsl:if>

          <xsl:apply-templates select="name" />
          <xsl:apply-templates select="reference[@kind='DataValue']/attribute[@kind='Value']" />
        </xsl:element>
      </xsl:otherwise>
    </xsl:choose>

  </xsl:template>

  <!--
    @template RemovePostPreprocessorDirectives

    Removes the post preprocess directive attribute from the model.
    -->
  <xsl:template name="RemovePostPreprocessorDirectives" match="attribute[@kind='PostPreprocessorDirectives']"/>

  <!--
    @template RemovePrePreprocessorDirectives

    Removes the post preprocess directive attribute from the model.
    -->
  <xsl:template name="RemovePrePreprocessorDirectives" match="attribute[@kind='PrePreprocessorDirectives']"/>

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
