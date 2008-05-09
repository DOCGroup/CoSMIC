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
  <xsl:template name="InputAction.MultiInputAction" 
                match="*[@kind='InputAction']">
    
    <!-- get all the XML tags where this action is listed as a 
         destination object -->
         
    <xsl:variable name="myid" select="@id" />
    <xsl:variable name="dsts" select="//connection[@role='MultiInput']/connpoint[@role='dst' and @target=$myid]" />

    <!-- copy all the children elements -->
    <xsl:element name="{name()}">

      <!-- 
           copy all the attributes, but we need to change the 
           value of "role" and "kind" attributes 
        -->
      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind'">
            <xsl:choose>
              <xsl:when test="count($dsts) > 0">
                <xsl:attribute name="kind">MultiInputAction</xsl:attribute>
              </xsl:when>
              <xsl:otherwise>
                <xsl:attribute name="kind">InputAction</xsl:attribute>
              </xsl:otherwise>              
            </xsl:choose>
          </xsl:when>

          <xsl:when test="name()='role'">
            <!-- treat its kind attribute specially -->
            <xsl:choose>
              <xsl:when test="count($dsts) > 0">
                <xsl:attribute name="role">MultiInputAction</xsl:attribute>
              </xsl:when>
              <xsl:otherwise>
                <xsl:attribute name="role">InputAction</xsl:attribute>
              </xsl:otherwise>
            </xsl:choose>
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

  <xsl:template name="InputAction.MultiInputAction.instance"
                match="*[@kind='InputAction' and @isinstance='yes']">

    <!-- get all the XML tags where this action is listed as a 
         destination object -->

    <xsl:variable name="typeid" select="@derivedfrom" />
    <xsl:variable name="type" select="//model[@id=$typeid and kind='MultiInputAction']" />

    <!-- copy all the children elements -->
    <xsl:element name="{name()}">

      <!-- 
           copy all the attributes, but we need to change the 
           value of "role" and "kind" attributes 
        -->
      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind'">
            <xsl:choose>
              <xsl:when test="count($type) = 1">
                <xsl:attribute name="kind">MultiInputAction</xsl:attribute>
              </xsl:when>
              <xsl:otherwise>
                <xsl:attribute name="kind">InputAction</xsl:attribute>
              </xsl:otherwise>
            </xsl:choose>
          </xsl:when>

          <xsl:when test="name()='role'">
            <!-- treat its kind attribute specially -->
            <xsl:choose>
              <xsl:when test="count($type) = 1">
                <xsl:attribute name="role">MultiInputAction</xsl:attribute>
              </xsl:when>
              <xsl:otherwise>
                <xsl:attribute name="role">InputAction</xsl:attribute>
              </xsl:otherwise>
            </xsl:choose>
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
