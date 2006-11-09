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
  <xsl:template match="*[@kind='Component']" priority="1">
    <xsl:variable name="periodics" select="./*[@kind='PeriodicEvent']" />

    <!-- copy the name of the Component element and its attributes -->
    <xsl:element name="{name()}">
      <xsl:apply-templates select="@*" />

      <xsl:choose>
        <!-- we need to handle the components with PeriodicAction elements differently -->
        <xsl:when test="count($periodics) > 0">
          <xsl:for-each select="*">
            <xsl:choose>
              <!-- copy all the Finish connections that aren't connected to a PeriodicAction -->
              <xsl:when test="name()='connection' and (@kind='Finish' or @kind='Effect')">
                <xsl:variable name="targets" select=".//@target" />

                <xsl:if test="count(../*[(@id=$targets[1] or @id=$targets[2]) and not(@kind='PeriodicEvent')]) = 2">
                  <xsl:element name="{name()}">
                    <xsl:for-each select="@*">
                      <xsl:copy />
                    </xsl:for-each>

                    <xsl:apply-templates />
                  </xsl:element>
                </xsl:if>
              </xsl:when>

              <xsl:otherwise>
                <xsl:element name="{name()}">
                  <xsl:for-each select="@*">
                    <xsl:copy />
                  </xsl:for-each>

                  <xsl:apply-templates />
                </xsl:element>
              </xsl:otherwise>
            </xsl:choose>

          </xsl:for-each>
        </xsl:when>

        <xsl:otherwise>
          <!-- just apply the regular templates to the child elements -->
          <xsl:apply-templates />
        </xsl:otherwise>
      </xsl:choose>
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
