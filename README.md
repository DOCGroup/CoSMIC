CoSMIC
============================
The CoSMIC tool-suite consists of a collection of Domain Specific
Modeling Languages (DSML) and related tools for meta-data generation,
quality-of-service (QoS) analysis and more. CoSMIC tool-suite consists
of following DSMLs.

* **Platform-Independent Component Modeling Language (PICML)** - A 
  paradigm for modeling CORBA Component Model (CCM) based applications.

* **Component QoS Modeling Language (CQML)** - A paradigm for modeling
  QoS characteristics such as fault-tolerance, real-time on top of PICML 
  models.

* **Data Distribution Service (DDS) QoS Modeling Language (DQML)** - A 
  paradigm for modeling QoS of DDS-based systems.

If you have problems with the installation, please send mail to:
cosmic-users@list.isis.vanderbilt.edu

Minimum Requirements
---------------------------------
You need to have administrator privileges to install CoSMIC. The following
are the minimum system requirements for installing CoSMIC:

1. Windows 2000, Windows XP, Windows Server 2003, Windows XP 64-bit
2. Generic Modeling Environment (GME) version (14.7.28, or better)

Building from Sources
---------------------------------

Please see the following file:

  https://github.com/DOCGroup/CoSMIC/blob/master/BUILDING
  
Supported Features
============================

PICML is currently capable of generating the following types of descriptors
specified in the D&C specification:

* **Interface Definition Language (.idl)** - Contains interface definitions for
  the components in the system.

* **CORBA Domain Descriptor (.cdd)** - Contains information about the domain
  where components are to be deployed.

* **Component Deployment Plan (.cdp)** - Contains information that actually
  drives the deployment including information about individual
  components that represent the leaf-nodes in case of a hierarchical
  assembly, connections between components, and assignment of
  components to nodes etc.
