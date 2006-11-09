<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="xml" omit-xml-declaration="no" doctype-system="mga.dtd" indent="yes"/>

  <!--
        apply all templates starting from the root
    -->
  <xsl:template match="/">
    <xsl:apply-templates />
  </xsl:template>

  <!--
        Purpose:
        
        Check for Component elements that have PeriodicAction element
        before modifying them. We need to remove all connections that
        have connpoints of the         
    -->
  <xsl:template match="connection[@kind='Effect']">
    <xsl:variable name="targets" select=".//@target"/>

    <!-- copy the name of the element -->
    <xsl:element name="{name()}">

      <xsl:choose>
        <xsl:when test="//*[(@id=$targets[1] or @id=$targets[2]) and @kind='InputAction']">
          <!-- change the connection from Effect to InputEffect -->

          <xsl:for-each select="@*">
            <xsl:choose>
              <xsl:when test="name()='kind'">
                <!-- treat its kind attribute specially -->
                <xsl:attribute name="kind">InputEffect</xsl:attribute>
              </xsl:when>

              <xsl:when test="name()='role'">
                <!-- treat its kind attribute specially -->
                <xsl:attribute name="role">InputEffect</xsl:attribute>
              </xsl:when>

              <xsl:otherwise>
                <xsl:copy />
              </xsl:otherwise>
            </xsl:choose>
          </xsl:for-each>
        </xsl:when>

        <xsl:otherwise>
          <!-- copy all the attributes for the connection -->
          <xsl:for-each select="@*">
            <xsl:copy />
          </xsl:for-each>
        </xsl:otherwise>

      </xsl:choose>

      <!-- copy the remaining nodes -->
      <xsl:apply-templates />

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
