<?xml version="1.0" encoding="UTF-8"?>

<!--
===============================================================================

  @author  James H. Hill

  $Id: RealNumber_to_DoubleNumber.xsl 906 2006-11-09 22:52:04Z hillj $

  @file    RealNumber_to_DoubleNumber.xsl

===============================================================================
-->

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
          Convert PeriodicAction to PeriodicEvent elememts, which involves the
          following:

          1. Changing the role of the 'PeriodicAction' to 'PeriodicEvent'
          2. Changing the element from a 'model' to an 'atom'.
    -->
  <xsl:template name="RealNumber_to_DoubleNumber" match="*[@kind='RealNumber']">
    <!-- copy all the children elements -->
    <xsl:element name="atom">

      <!--
           copy all the attributes, but we need to change the
           value of "role" and "kind" attributes
        -->
      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='name'">
            <!-- treat its kind attribute specially -->
            <xsl:attribute name="name">{name()}</xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='kind'">
            <!-- treat its kind attribute specially -->
            <xsl:attribute name="kind">DoubleNumber</xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='role'">
            <!-- treat its kind attribute specially -->
            <xsl:attribute name="role">DoubleNumber</xsl:attribute>
          </xsl:when>
          <xsl:otherwise>
            <xsl:copy />
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>

      <!-- copy all the nodes in the PeriodicEvent -->

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
