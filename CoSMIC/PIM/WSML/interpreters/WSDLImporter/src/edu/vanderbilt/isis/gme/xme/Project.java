//
// This file was generated by the JavaTM Architecture for XML Binding(JAXB) Reference Implementation, v2.0-b26-ea3 
// See <a href="http://java.sun.com/xml/jaxb">http://java.sun.com/xml/jaxb</a> 
// Any modifications to this file will be lost upon recompilation of the source schema. 
// Generated on: 2006.07.18 at 07:56:31 PM CDT 
//


package edu.vanderbilt.isis.gme.xme;

import javax.xml.bind.annotation.AccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlAttribute;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlType;
import edu.vanderbilt.isis.gme.xme.Author;
import edu.vanderbilt.isis.gme.xme.Comment;
import edu.vanderbilt.isis.gme.xme.Folder;
import edu.vanderbilt.isis.gme.xme.Name;
import edu.vanderbilt.isis.gme.xme.Project;


/**
 * <p>Java class for project element declaration.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;element name="project">
 *   &lt;complexType>
 *     &lt;complexContent>
 *       &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *         &lt;sequence>
 *           &lt;element ref="{}name"/>
 *           &lt;element ref="{}comment" minOccurs="0"/>
 *           &lt;element ref="{}author" minOccurs="0"/>
 *           &lt;element ref="{}folder"/>
 *         &lt;/sequence>
 *         &lt;attribute name="cdate" type="{http://www.w3.org/2001/XMLSchema}string" />
 *         &lt;attribute name="guid" type="{http://www.w3.org/2001/XMLSchema}string" />
 *         &lt;attribute name="mdate" type="{http://www.w3.org/2001/XMLSchema}string" />
 *         &lt;attribute name="metaguid" type="{http://www.w3.org/2001/XMLSchema}string" />
 *         &lt;attribute name="metaname" use="required" type="{http://www.w3.org/2001/XMLSchema}string" />
 *         &lt;attribute name="metaversion" type="{http://www.w3.org/2001/XMLSchema}string" />
 *         &lt;attribute name="version" type="{http://www.w3.org/2001/XMLSchema}string" />
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
    "comment",
    "author",
    "folder"
})
@XmlRootElement(name = "project")
public class Project {

    protected Name name;
    protected Comment comment;
    protected Author author;
    protected Folder folder;
    @XmlAttribute
    protected String cdate;
    @XmlAttribute
    protected String guid;
    @XmlAttribute
    protected String mdate;
    @XmlAttribute
    protected String metaguid;
    @XmlAttribute(required = true)
    protected String metaname;
    @XmlAttribute
    protected String metaversion;
    @XmlAttribute
    protected String version;

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
     * Gets the value of the comment property.
     * 
     * @return
     *     possible object is
     *     {@link Comment }
     *     
     */
    public Comment getComment() {
        return comment;
    }

    /**
     * Sets the value of the comment property.
     * 
     * @param value
     *     allowed object is
     *     {@link Comment }
     *     
     */
    public void setComment(Comment value) {
        this.comment = value;
    }

    /**
     * Gets the value of the author property.
     * 
     * @return
     *     possible object is
     *     {@link Author }
     *     
     */
    public Author getAuthor() {
        return author;
    }

    /**
     * Sets the value of the author property.
     * 
     * @param value
     *     allowed object is
     *     {@link Author }
     *     
     */
    public void setAuthor(Author value) {
        this.author = value;
    }

    /**
     * Gets the value of the folder property.
     * 
     * @return
     *     possible object is
     *     {@link Folder }
     *     
     */
    public Folder getFolder() {
        return folder;
    }

    /**
     * Sets the value of the folder property.
     * 
     * @param value
     *     allowed object is
     *     {@link Folder }
     *     
     */
    public void setFolder(Folder value) {
        this.folder = value;
    }

    /**
     * Gets the value of the cdate property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCdate() {
        return cdate;
    }

    /**
     * Sets the value of the cdate property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCdate(String value) {
        this.cdate = value;
    }

    /**
     * Gets the value of the guid property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getGuid() {
        return guid;
    }

    /**
     * Sets the value of the guid property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setGuid(String value) {
        this.guid = value;
    }

    /**
     * Gets the value of the mdate property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getMdate() {
        return mdate;
    }

    /**
     * Sets the value of the mdate property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setMdate(String value) {
        this.mdate = value;
    }

    /**
     * Gets the value of the metaguid property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getMetaguid() {
        return metaguid;
    }

    /**
     * Sets the value of the metaguid property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setMetaguid(String value) {
        this.metaguid = value;
    }

    /**
     * Gets the value of the metaname property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getMetaname() {
        return metaname;
    }

    /**
     * Sets the value of the metaname property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setMetaname(String value) {
        this.metaname = value;
    }

    /**
     * Gets the value of the metaversion property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getMetaversion() {
        return metaversion;
    }

    /**
     * Sets the value of the metaversion property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setMetaversion(String value) {
        this.metaversion = value;
    }

    /**
     * Gets the value of the version property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getVersion() {
        return version;
    }

    /**
     * Sets the value of the version property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setVersion(String value) {
        this.version = value;
    }

}
