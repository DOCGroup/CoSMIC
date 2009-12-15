<?xml version="1.0" encoding="UTF-8"?>

<!--
===============================================================================

  @author  James H. Hill

  $Id: PeriodicAction_to_PeriodicEvent.xsl 906 2006-11-09 22:52:04Z hillj $

  @file    InputAction_to_MultiInputAction.xsl

===============================================================================
-->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="xml"
              omit-xml-declaration="no"
              doctype-system="mga.dtd"
              indent="yes"/>

  <!--
        apply all templates starting from the root
    -->
  <xsl:template match="/">
    <xsl:apply-templates />
  </xsl:template>

  <!--
        Purpose:
          Convert InputAction to MultiInputAction elememts, which involves the
          following:

          1. Locating all the connections where the input action is the 'dst'
             of a MulitInput connection.
          2. Changing its role to 'MulitInputAction' if there are any occurrences
             of this in the model (i.e., number of 'dst' connections > 0).
    -->
  <xsl:template match="attribute[@kind='AutoRouterPref' or @kind='GradientFillColor' or @kind='GradientFillDirection' or @kind='HelpURL' or @kind='IsGradientFillEnabled' or @kind='IsModelAutoRouted']" />

  <xsl:template match="attribute[@kind='IsAutoRouted']" />
  <xsl:template match="attribute[@kind='IsResizable']" />
  <xsl:template match="attribute[@kind='IsRoundRectangleEnabled']" />
  <xsl:template match="attribute[@kind='IsShadowCastEnabled']" />
  <xsl:template match="attribute[@kind='LabelFormatStr']" />
  <xsl:template match="attribute[@kind='RoundRectangleRadius']" />
  <xsl:template match="attribute[@kind='ShadowColor']" />
  <xsl:template match="attribute[@kind='ShadowDirection']" />
  <xsl:template match="attribute[@kind='ShadowThickness']" />

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
