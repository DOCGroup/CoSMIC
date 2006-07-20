//
// This file was generated by the JavaTM Architecture for XML Binding(JAXB) Reference Implementation, v2.0-b26-ea3 
// See <a href="http://java.sun.com/xml/jaxb">http://java.sun.com/xml/jaxb</a> 
// Any modifications to this file will be lost upon recompilation of the source schema. 
// Generated on: 2006.07.18 at 07:56:31 PM CDT 
//


package edu.vanderbilt.isis.gme.xme;

import java.util.ArrayList;
import java.util.List;
import javax.xml.bind.annotation.AccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlAttribute;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElements;
import javax.xml.bind.annotation.XmlID;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlType;
import javax.xml.bind.annotation.adapters.CollapsedStringAdapter;
import javax.xml.bind.annotation.adapters.XmlJavaTypeAdapter;
import edu.vanderbilt.isis.gme.xme.Atom;
import edu.vanderbilt.isis.gme.xme.Connection;
import edu.vanderbilt.isis.gme.xme.Constraint;
import edu.vanderbilt.isis.gme.xme.Folder;
import edu.vanderbilt.isis.gme.xme.Model;
import edu.vanderbilt.isis.gme.xme.Name;
import edu.vanderbilt.isis.gme.xme.Reference;
import edu.vanderbilt.isis.gme.xme.Regnode;
import edu.vanderbilt.isis.gme.xme.Set;


/**
 * <p>Java class for folder element declaration.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;element name="folder">
 *   &lt;complexType>
 *     &lt;complexContent>
 *       &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *         &lt;sequence>
 *           &lt;element ref="{}name"/>
 *           &lt;choice maxOccurs="unbounded" minOccurs="0">
 *             &lt;element ref="{}regnode"/>
 *             &lt;element ref="{}constraint"/>
 *             &lt;element ref="{}folder"/>
 *             &lt;element ref="{}model"/>
 *             &lt;element ref="{}atom"/>
 *             &lt;element ref="{}reference"/>
 *             &lt;element ref="{}set"/>
 *             &lt;element ref="{}connection"/>
 *           &lt;/choice>
 *         &lt;/sequence>
 *         &lt;attribute name="childrelidcntr" type="{http://www.w3.org/2001/XMLSchema}string" />
 *         &lt;attribute name="id" type="{http://www.w3.org/2001/XMLSchema}ID" />
 *         &lt;attribute name="kind" use="required" type="{http://www.w3.org/2001/XMLSchema}NMTOKEN" />
 *         &lt;attribute name="libref" type="{http://www.w3.org/2001/XMLSchema}string" />
 *         &lt;attribute name="perm" type="{http://www.w3.org/2001/XMLSchema}string" />
 *         &lt;attribute name="relid" type="{http://www.w3.org/2001/XMLSchema}string" />
 *       &lt;/restriction>
 *     &lt;/complexContent>
 *   &lt;/complexType>
 * &lt;/element>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(AccessType.FIELD)
@XmlType(name = "", propOrder = {
    "name",
    "regnodeOrConstraintOrFolder"
})
@XmlRootElement(name = "folder")
public class Folder {

    protected Name name;
    @XmlElements({
        @XmlElement(name = "set", type = Set.class),
        @XmlElement(name = "folder", type = Folder.class),
        @XmlElement(name = "regnode", type = Regnode.class),
        @XmlElement(name = "atom", type = Atom.class),
        @XmlElement(name = "reference", type = Reference.class),
        @XmlElement(name = "connection", type = Connection.class),
        @XmlElement(name = "model", type = Model.class),
        @XmlElement(name = "constraint", type = Constraint.class)
    })
    protected List<Object> regnodeOrConstraintOrFolder;
    @XmlAttribute
    protected String childrelidcntr;
    @XmlAttribute
    @XmlJavaTypeAdapter(CollapsedStringAdapter.class)
    @XmlID
    protected String id;
    @XmlAttribute(required = true)
    @XmlJavaTypeAdapter(CollapsedStringAdapter.class)
    protected String kind;
    @XmlAttribute
    protected String libref;
    @XmlAttribute
    protected String perm;
    @XmlAttribute
    protected String relid;

    /**
     * Gets the value of the name property.
     * 
     * @return
     *     possible object is
     *     {@link Name }
     *     
     */
    public Name getName() {
        return name;
    }

    /**
     * Sets the value of the name property.
     * 
     * @param value
     *     allowed object is
     *     {@link Name }
     *     
     */
    public void setName(Name value) {
        this.name = value;
    }

    /**
     * Gets the value of the regnodeOrConstraintOrFolder property.
     * 
     * <p>
     * This accessor method returns a reference to the live list,
     * not a snapshot. Therefore any modification you make to the
     * returned list will be present inside the JAXB object.
     * This is why there is not a <CODE>set</CODE> method for the regnodeOrConstraintOrFolder property.
     * 
     * <p>
     * For example, to add a new item, do as follows:
     * <pre>
     *    getRegnodeOrConstraintOrFolder().add(newItem);
     * </pre>
     * 
     * 
     * <p>
     * Objects of the following type(s) are allowed in the list
     * {@link Set }
     * {@link Folder }
     * {@link Regnode }
     * {@link Atom }
     * {@link Reference }
     * {@link Connection }
     * {@link Model }
     * {@link Constraint }
     * 
     * 
     */
    public List<Object> getRegnodeOrConstraintOrFolder() {
        if (regnodeOrConstraintOrFolder == null) {
            regnodeOrConstraintOrFolder = new ArrayList<Object>();
        }
        return this.regnodeOrConstraintOrFolder;
    }

    /**
     * Gets the value of the childrelidcntr property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getChildrelidcntr() {
        return childrelidcntr;
    }

    /**
     * Sets the value of the childrelidcntr property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setChildrelidcntr(String value) {
        this.childrelidcntr = value;
    }

    /**
     * Gets the value of the id property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getId() {
        return id;
    }

    /**
     * Sets the value of the id property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setId(String value) {
        this.id = value;
    }

    /**
     * Gets the value of the kind property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getKind() {
        return kind;
    }

    /**
     * Sets the value of the kind property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setKind(String value) {
        this.kind = value;
    }

    /**
     * Gets the value of the libref property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getLibref() {
        return libref;
    }

    /**
     * Sets the value of the libref property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setLibref(String value) {
        this.libref = value;
    }

    /**
     * Gets the value of the perm property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getPerm() {
        return perm;
    }

    /**
     * Sets the value of the perm property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setPerm(String value) {
        this.perm = value;
    }

    /**
     * Gets the value of the relid property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getRelid() {
        return relid;
    }

    /**
     * Sets the value of the relid property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setRelid(String value) {
        this.relid = value;
    }

}
