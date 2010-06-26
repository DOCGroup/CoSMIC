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
    @template UpdateFilePath
    
    Rename the path atttribute on the File model element.
    -->
  <xsl:template name="UpdateFilePath" match="model[@kind='File']/attribute[@kind='path']">
    <!-- copy all the children elements -->
    <xsl:element name="{name()}">

      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind'">
            <!-- Update the kind value to 'Path' -->
            <xsl:attribute name="kind">Path</xsl:attribute>
          </xsl:when>
          <xsl:otherwise>
            <xsl:copy />
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>

      <!-- perform the default behavior for the remainder of this node -->
      <xsl:apply-templates />
    </xsl:element>
  </xsl:template>

  <!--
    @template ReplaceRealNumber
    
    Replaces the RealNumber model element with DoubleNumber.
    -->
  <xsl:template name="ReplaceRealNumber" match="atom[@kind='RealNumber']">
    <!-- copy all the children elements -->
    <xsl:element name="{name ()}">

      <!--
           copy all the attributes, but we need to change the
           value of "role" and "kind" attributes
        -->
      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind'">
            <!-- Change the kind to DoubleNumber -->
            <xsl:attribute name="kind">DoubleNumber</xsl:attribute>
          </xsl:when>
          <xsl:otherwise>
            <xsl:copy />
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>

      <!-- perform the default behavior for the remainder of this node -->
      <xsl:apply-templates />
    </xsl:element>
  </xsl:template>

  <!--
    @template UpdateLocalInterface
    
    Update the local attribute to an InterfaceSemantics attribute.
    -->
  <xsl:template name="UpdateLocalInterface" match="model[@kind='Object']/attribute[@kind='local']">
    <!-- There is only one <value> element, but we are still going
         to wrap this in a for-each loop. We need to convert it to 
         the correct enumeration type. -->
    <xsl:for-each select="value">
      <xsl:choose>
        <xsl:when test="text()='true' or text()='TRUE' or text()='True'">
          <xsl:element name="attribute">
            <xsl:attribute name="kind">InterfaceSemantics</xsl:attribute>
            <xsl:element name="value">
              <xsl:text>local</xsl:text>
            </xsl:element>
          </xsl:element>
        </xsl:when>
      </xsl:choose>
    </xsl:for-each>
  </xsl:template>

  <!--
    @template UpdateAbstractInterface
    
    Update the local attribute to an InterfaceSemantics attribute.
    -->
  <xsl:template name="UpdateAbstractInterface" match="model[@kind='Object']/attribute[@kind='abstract']">
    <!-- There is only one <value> element, but we are still going
         to wrap this in a for-each loop. We need to convert it to 
         the correct enumeration type. -->
    <xsl:for-each select="value">
      <xsl:choose>
        <xsl:when test="text()='true' or text()='TRUE' or text()='True'">
          <xsl:element name="attribute">
            <xsl:attribute name="kind">InterfaceSemantics</xsl:attribute>
            <xsl:element name="value">
              <xsl:text>abstract</xsl:text>
            </xsl:element>
          </xsl:element>
        </xsl:when>
      </xsl:choose>
    </xsl:for-each>
  </xsl:template>

  <!--
    @template UpdateDeployedComponent
    
    Update the ComponentRef in a deployment plan to a ComponentInstanceRef.
    -->
  <xsl:template name="UpdateDeployedComponent" match="model[@kind='DeploymentPlan']/reference[@kind='ComponentRef']">
    <!-- create the same type of element -->
    <xsl:element name="{name ()}">

      <!--
           Copy all the attributes, but make sure to change the value of
           the 'kind' attribute to InterfaceSemantics.
        -->
      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind' or name()='role'">
            <xsl:attribute name="{name()}">ComponentInstanceRef</xsl:attribute>
          </xsl:when>
          <xsl:otherwise>
            <xsl:copy />
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>

      <!-- perform the default behavior for the remainder of this node -->
      <xsl:apply-templates />
    </xsl:element>
  </xsl:template>

  <!--
    @template UpdateInvoke
    
    Update the invoke connection element to Invoke.
    -->
  <xsl:template name="UpdateInvoke" match="connection[@kind='invoke']">
    <!-- create the same type of element -->
    <xsl:element name="{name ()}">

      <!--
           Copy all the attributes, but make sure to change the value of
           the 'kind' attribute to InterfaceSemantics.
        -->
      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind' or name()='role'">
            <xsl:attribute name="{name()}">Invoke</xsl:attribute>
          </xsl:when>
          <xsl:otherwise>
            <xsl:copy />
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>

      <!-- perform the default behavior for the remainder of this node -->
      <xsl:apply-templates />
    </xsl:element>
  </xsl:template>

  <!--
    @template UpdateFacetDelegate
    
    Update the invoke connection element to Invoke.
    -->
  <xsl:template name="UpdateFacetDelegate" match="model[@kind='ComponentAssembly']/reference[@kind='ProvidedRequestPort']">
    <!-- create the same type of element -->
    <xsl:element name="atom">

      <!--
           Copy all the attributes, but make sure to change the value of
           the 'kind' attribute to InterfaceSemantics.
        -->
      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind' or name()='role'">
            <xsl:attribute name="{name()}">ProvidedRequestPortDelegate</xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='id' or name()='guid'">
            <xsl:copy />
          </xsl:when>
          <xsl:otherwise />
        </xsl:choose>
      </xsl:for-each>

      <!-- perform the default behavior for the remainder of this node -->
      <xsl:apply-templates select="name" />
    </xsl:element>
  </xsl:template>

  <!--
    @template UpdateReceptacleDelegate
    
    Update the invoke connection element to Invoke.
    -->
  <xsl:template name="UpdateReceptacleDelegate" match="model[@kind='ComponentAssembly']/reference[@kind='RequiredRequestPort']">
    <!-- create the same type of element -->
    <xsl:element name="atom">

      <!--
           Copy all the attributes, but make sure to change the value of
           the 'kind' attribute to InterfaceSemantics.
        -->
      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind' or name()='role'">
            <xsl:attribute name="{name()}">RequiredRequestPortDelegate</xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='id' or name()='guid'">
            <xsl:copy />
          </xsl:when>
          <xsl:otherwise />
        </xsl:choose>
      </xsl:for-each>

      <!-- perform the default behavior for the remainder of this node -->
      <xsl:apply-templates select="name" />
    </xsl:element>
  </xsl:template>

  <!--
    @template RemovePredefinedTypeReference
    -->
  <xsl:template name="RemovePredefinedTypeReference" match="folder[@kind='PredefinedTypes']/reference" />

  <!--
    @template UpdateFacetDelegateConnection
    
    Update the invoke connection element to Invoke.
    -->
  <xsl:template name="UpdateFacetDelegateConnectin" match="model[@kind='ComponentAssembly']/connection[@kind='FacetDelegate']">
    <!-- create the same type of element -->
    <xsl:element name="{name()}">
      <!-- perform the default behavior for the remainder of this node -->
      <xsl:apply-templates select="@*" />
      <xsl:apply-templates select="name" />

        
      <xsl:for-each select="connpoint">
        <!-- update each connection point -->
        <xsl:variable name="current_cp" select="self::node ()" />
        
        <xsl:element name="connpoint">
          <!-- switch the targets of the connection points -->
          <xsl:for-each select="@*">    
            <xsl:choose>
              <xsl:when test="self::node()='src'">
                <xsl:attribute name="role">src</xsl:attribute>
                <xsl:attribute name="target">
                  <xsl:value-of select="$current_cp/../connpoint[@role='dst']/@target" />
                </xsl:attribute>
              </xsl:when>
              
              <xsl:when test="self::node()='dst'">
                <xsl:attribute name="role">dst</xsl:attribute>
                <xsl:attribute name="target">
                  <xsl:value-of select="$current_cp/../connpoint[@role='src']/@target" />
                </xsl:attribute>
              </xsl:when>
              <xsl:otherwise />
            </xsl:choose>
          </xsl:for-each>
        </xsl:element>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>

  <!--
    @template RemoveDeliverTo
    
    Removes the deliverTo connection from the model.
    -->
  <xsl:template name="RemoveDeliverTo" match="connection[@kind='deliverTo']" />

  <!--
    @template RemoveDeliverTo
    
    Removes the deliverTo connection from the model.
    -->
  <xsl:template name="RemovePublishConnector" match="atom[@kind='PublishConnector']" />

  <!--
    @template CreateSendsToConnection
    
    Update the invoke connection element to Invoke.
    -->
  <xsl:template name="CreateSendsToConnection" match="connection[@kind='publish']">
    <!--
         Copy all the attributes, but make sure to change the value of
         the 'kind' attribute to InterfaceSemantics.
      -->

    <!-- perform the default behavior for the remainder of this node -->
    <xsl:variable name="src_id" select="connpoint[@role='src']/@target" />
    
    <!-- get the destination node id -->
    <xsl:variable name="dst" select="connpoint[@role='dst']" />
    <xsl:variable name="target" select="$dst/@target" />
    
    <!-- The destination id is that of a PublishConnector. Try and
         locate the correct PublishConnector object in this model. 
         -->
    <xsl:variable name="connector" select="../atom[@id=$target]" />
    <xsl:variable name="connector_id" select="$connector/@id" />
    
    <!-- Next, we need to locate all the deliverTo connections where
         this PublishConnector is the source. -->
    <xsl:variable name="inputs" select="../connection[@kind='deliverTo']/connpoint[@role='src' and @target=$connector_id]" />

    <xsl:for-each select="$inputs">
      <xsl:variable name="id" select="../@id" />
      <xsl:variable name="dst_id" select="../connpoint[@role='dst']/@target" />
      <xsl:variable name="guid" select="../@guid" />

      <xsl:element name="connection">
        <xsl:attribute name="id"><xsl:value-of select="$id" /></xsl:attribute>
        <xsl:attribute name="role">SendsTo</xsl:attribute>
        <xsl:attribute name="kind">SendsTo</xsl:attribute>
        <xsl:attribute name="guid"><xsl:value-of select="$guid" /></xsl:attribute>

        <xsl:element name="name" />
        <xsl:element name="connpoint">
          <xsl:attribute name="role">src</xsl:attribute>
          <xsl:attribute name="target"><xsl:value-of select="$src_id" /></xsl:attribute>
        </xsl:element>
        <xsl:element name="connpoint">
          <xsl:attribute name="role">dst</xsl:attribute>
          <xsl:attribute name="target"><xsl:value-of select="$dst_id" />
          </xsl:attribute>
        </xsl:element>
      </xsl:element>
    </xsl:for-each>
  </xsl:template>

  <!--
    @template UpdateToComponentInstance
    
    Update the ComponentRef in a deployment plan to a ComponentInstanceRef.
    -->
  <xsl:template name="UpdateToComponentInstance" match="model[@kind='ComponentAssembly']/model[@kind='Component' and @isinstance='yes']">
    <!-- create the same type of element -->
    <xsl:element name="{name ()}">

      <!--
           Copy all the attributes, but make sure to change the value of
           the 'kind' attribute to InterfaceSemantics.
        -->
      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind' or name()='role'">
            <!-- convert the current element to a ComponentInstance element -->
            <xsl:attribute name="{name()}">ComponentInstance</xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='derivedfrom' or name()='isinstance'">
            <!-- do nothing -->
          </xsl:when>
          <xsl:otherwise>
            <xsl:copy />
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>

      <!-- perform the default behavior for the remainder of this node -->
      <xsl:apply-templates select="name" />
      <xsl:apply-templates select="attribute[@kind='UUID']" />
      
      <!-- copy over the ports -->
      <xsl:apply-templates select="reference" />
      
      <!-- copy over the attributes -->
      <xsl:apply-templates select="model[@kind='Attribute' or @kind='ReadonlyAttribute']" />
      
      <!-- finally set the ComponentInstanceType -->
      <xsl:variable name="derivedfrom" select="@derivedfrom" />
      <xsl:variable name="component_ref" select="//model[@kind='ComponentImplementationContainer']/reference[@kind='ComponentRef' and @referred=$derivedfrom]" />
      <xsl:variable name="dst" select="$component_ref/@id" />
      <xsl:variable name="implements" select="//../model[@kind='ComponentImplementationContainer']/connection/connpoint[@target=$dst]" />
      <xsl:variable name="src" select="$implements/../connpoint[@role='src']/@target" />
      
      <xsl:element name="reference">
        <xsl:attribute name="kind">ComponentInstanceType</xsl:attribute>
        <xsl:attribute name="role">ComponentInstanceType</xsl:attribute>
        <xsl:attribute name="referred"><xsl:value-of select="$src" /></xsl:attribute>
        <xsl:element name="name" />
      </xsl:element>
    </xsl:element>
  </xsl:template>

  <!--
    @template UpdateToRequiredRequestPortInstance
    
    Update the ComponentRef in a deployment plan to a ComponentInstanceRef.
    -->
  <xsl:template name="UpdateToRequiredRequestPortInstance" match="model[@kind='Component' and @isinstance='yes']/reference[@kind='RequiredRequestPort']">
    <xsl:element name="reference">

      <!--
           Copy all the attributes, but make sure to change the value of
           the 'kind' attribute to InterfaceSemantics.
        -->
      <xsl:variable name="target" select="@derivedfrom" />

      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind' or name()='role'">
            <!-- convert the current element to a ComponentInstance element -->
            <xsl:attribute name="{name()}">RequiredRequestPortInstance</xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='derivedfrom'">
            <!-- the element we need to reference is the element we are derived from -->
            <xsl:attribute name="referred">
              <xsl:value-of select="$target" />
            </xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='referred' or name()='isinstance' or name()='isprimary' or name()='isbound'" />
          <xsl:otherwise>
            <xsl:copy />
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>

      <!-- perform the default behavior for the remainder of this node -->
      <xsl:apply-templates select="name" />
    </xsl:element>
  </xsl:template>

  <!--
    @template UpdateToAttributeInstance
    -->
  <xsl:template name="UpdateToAttributeInstance" match="model[@kind='Component' and @isinstance='yes']/model[@kind='Attribute' or @kind='ReadonlyAttribute']">
    <xsl:element name="reference">

      <!--
           Copy all the attributes, but make sure to change the value of
           the 'kind' attribute to InterfaceSemantics.
        -->
      <xsl:variable name="target" select="@derivedfrom" />

      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind' or name()='role'">
            <!-- convert the current element to a ComponentInstance element -->
            <xsl:attribute name="{name()}">AttributeInstance</xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='derivedfrom'">
            <!-- the element we need to reference is the element we are derived from -->
            <xsl:attribute name="referred">
              <xsl:value-of select="$target" />
            </xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='referred' or name()='isinstance' or name()='isprimary' or name()='isbound' or name()='childrelidcntr'" />
          <xsl:otherwise>
            <xsl:copy />
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>

      <!-- perform the default behavior for the remainder of this node -->
      <xsl:apply-templates select="name" />
    </xsl:element>
  </xsl:template>

  <!--
    @template UpdateToProvidedRequestPortInstance
    -->
  <xsl:template name="UpdateToProvidedRequestPortInstance" match="model[@kind='Component' and @isinstance='yes']/reference[@kind='ProvidedRequestPort']">
    <xsl:element name="reference">

      <!--
           Copy all the attributes, but make sure to change the value of
           the 'kind' attribute to InterfaceSemantics.
        -->
      <xsl:variable name="target" select="@derivedfrom" />

      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind' or name()='role'">
            <!-- convert the current element to a ComponentInstance element -->
            <xsl:attribute name="{name()}">ProvidedRequestPortInstance</xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='derivedfrom'">
            <!-- the element we need to reference is the element we are derived from -->
            <xsl:attribute name="referred">
              <xsl:value-of select="$target" />
            </xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='referred' or name()='isinstance' or name()='isprimary' or name()='isbound'" />
          <xsl:otherwise>
            <xsl:copy />
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>

      <!-- perform the default behavior for the remainder of this node -->
      <xsl:apply-templates select="name" />
    </xsl:element>
  </xsl:template>

  <!--
    @template UpdateInEventPortInstance
    -->
  <xsl:template name="UpdateInEventPortInstance" match="model[@kind='Component' and @isinstance='yes']/reference[@kind='InEventPort']">
    <xsl:element name="reference">

      <!--
           Copy all the attributes, but make sure to change the value of
           the 'kind' attribute to InterfaceSemantics.
        -->
      <xsl:variable name="target" select="@derivedfrom" />

      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind' or name()='role'">
            <!-- convert the current element to a ComponentInstance element -->
            <xsl:attribute name="{name()}">InEventPortInstance</xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='derivedfrom'">
            <!-- the element we need to reference is the element we are derived from -->
            <xsl:attribute name="referred">
              <xsl:value-of select="$target" />
            </xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='referred' or name()='isinstance' or name()='isprimary' or name()='isbound'" />
          <xsl:otherwise>
            <xsl:copy />
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>

      <!-- perform the default behavior for the remainder of this node -->
      <xsl:apply-templates select="name" />
    </xsl:element>
  </xsl:template>

  <!--
    @template UpdateOutEventPortInstance
    -->
  <xsl:template name="UpdateOutEventPortInstance" match="model[@kind='Component' and @isinstance='yes']/reference[@kind='OutEventPort']">
    <xsl:element name="reference">

      <!--
           Copy all the attributes, but make sure to change the value of
           the 'kind' attribute to InterfaceSemantics.
        -->
      <xsl:variable name="target" select="@derivedfrom" />

      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind' or name()='role'">
            <!-- convert the current element to a ComponentInstance element -->
            <xsl:attribute name="{name()}">OutEventPortInstance</xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='derivedfrom'">
            <!-- the element we need to reference is the element we are derived from -->
            <xsl:attribute name="referred">
              <xsl:value-of select="$target" />
            </xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='referred' or name()='isinstance' or name()='isprimary' or name()='isbound'" />
          <xsl:otherwise>
            <xsl:copy />
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>

      <!-- perform the default behavior for the remainder of this node -->
      <xsl:apply-templates select="name" />
    </xsl:element>
  </xsl:template>

  <!--
    @template UpdateSupportsInstance
    -->
  <xsl:template name="UpdateSupportsInstance" match="model[@kind='Component' and @isinstance='yes']/reference[@kind='Supports']">
    <xsl:element name="reference">

      <!--
           Copy all the attributes, but make sure to change the value of
           the 'kind' attribute to InterfaceSemantics.
        -->
      <xsl:variable name="target" select="@derivedfrom" />

      <xsl:for-each select="@*">
        <xsl:choose>
          <xsl:when test="name()='kind' or name()='role'">
            <!-- convert the current element to a ComponentInstance element -->
            <xsl:attribute name="{name()}">SupportsInstance</xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='derivedfrom'">
            <!-- the element we need to reference is the element we are derived from -->
            <xsl:attribute name="referred">
              <xsl:value-of select="$target" />
            </xsl:attribute>
          </xsl:when>
          <xsl:when test="name()='referred' or name()='isinstance' or name()='isprimary' or name()='isbound'" />
          <xsl:otherwise>
            <xsl:copy />
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>

      <!-- perform the default behavior for the remainder of this node -->
      <xsl:apply-templates select="name" />
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
