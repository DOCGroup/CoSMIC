Overview of CoSMIC
============================
The CoSMIC tool-suite consists of a collection of Domain Specific
Modeling Languages (DSML) and related tools for meta-data generation,
quality-of-service (QoS) analysis and more. CoSMIC tool-suite consists
of following DSMLs.

* Platform-Independent Component Modeling Language (PICML) - A paradigm 
  for modeling CORBA Component Model (CCM) based applications.

* Component QoS Modeling Language (CQML) - A paradigm for modeling QoS 
  characteristics such as fault-tolerance, real-time on top of PICML models.

* Data Distribution Service (DDS) QoS Modeling Language (DQML) - A paradigm 
  for modeling QoS of DDS-based systems.

If you have problems with the installation, please send mail to:
cosmic-users@list.isis.vanderbilt.edu

Minimum Requirements
============================
You need to have administrator privileges to install CoSMIC. The following
are the minimum system requirements for installing CoSMIC:
1.  Windows 2000, Windows XP, Windows Server 2003, Windows XP 64-bit
2.  Generic Modeling Environment (GME) version (10.8.18)

This document gives some preliminary information on getting started with
using CoSMIC as well as information on supported features.

Getting Started
============================
1.  Start GME.

2.  Select File->Import XML, and navigate to the directory �examples� under
    the directory in which CoSMIC was installed. Note that each paradigm
    mentioned above has its examples in its corresponding �examples�
    directory. Choose Hello.xme. Leave the default item �Create
    project file� checked in the dialog box that pops up. Click Next. Accept
    the default name �Hello�. Click Open.

3.  The importer should succeed. Click on OK button on the next dialog box.

4.  You should see new icons corresponding to the paradigm interpreters on
    the GME toolbar. If you see double question marks (like ) with a tooltip,
    please refer to the instructions below on information about reporting
    errors.

5.  Expanding the tree-view on the right-hand model-browser pane should open
    up the model. Further expansion should open up the whole model.
    Double-click on any one of them to show the contents in the model-editor
    pane.

Generating Descriptors
============================
1.  Clicking on any of the interpreter icons opens up a directory browser,
    which lets you specify the output directory for the generated descriptors.

2.  For example, in case of PICML models, to generate component package
    descriptors, click on the icon that says �Generate Package Descriptors�.
    It will generate the component packaging, deployment and configuration
    related descriptors.

Supported Features
============================
PICML is currently capable of generating the following types of descriptors
specified in the D&C specification:

* CORBA Component Descriptor (.ccd) - Contains information about component 
  interfaces including component ports.

* Component Implementation Descriptor (.cid) - Contains information
  about component implementations which might be either monolithic or
  assembly based. In the case of assembly based implementations, this
  descriptor also captures the dependencies and the connections among
  components

* Implementation Artifact Descriptor (.iad) - Contains information
  about implementation artifacts including dependencies between such
  artifacts

* Component Package Descriptor (.cpd) - Contains information about
  grouping of multiple implementations of the same component interface
  into component packages

* Package Configuration Descriptor (.pcd) - Contains information about
  specific configurations of such component packages

* Component Domain Descriptor (.cdd) - Contains information about the
  target environment in which the component-based application will be
  deployed

* Top-Level Package Descriptor (.tpd) - Contains information identifying
  the top-level element in a component package descriptor which might
  include information about multiple elements

* Component Deployment Plan (.cdp) - Contains information that actually
  drives the deployment including information about individual
  components that represent the leaf-nodes in case of a hierarchical
  assembly, connections between components, and assignment of
  components to nodes etc.

**Note.** While importing the .xme files generated with the previous versions 
of CoSMIC, GME will pop up dialog boxes about deleted properties. You can 
safely click "ignore" to suppress these messages.

You can find more information on how to use the tools by clicking
Start -> CoSMIC -> Docs.
