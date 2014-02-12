Building CoSMIC
=================

This document contains detailed instructions for how to build 
CoSMIC manually.

System Requirments
-------------------

* Microsoft Windows XP, or later

* Microsoft Visual Studio 2009 (vc7), or later

* ActiveState ActivePERL (http://www.activestate.com/activeperl)

* Generic Modeling Environment 13.x.x (http://www.isis.vanderbilt.edu/Projects/gme)

* Universal Data Model (UDM) 3.2.11 (http://repo.isis.vanderbilt.edu/UDM)

* Boost 1.43, or later (http://www.boost.org)

* Xerces-C (http://xerces.apache.org/xerces-c)

* ACE (see downloading sources below)

* GAME (see downloading sources below)

Downloading Sources
--------------------

### ACE

Download the latest version of **ACE** from its **Subversion** repo:

    https://svn.dre.vanderbilt.edu/DOC/Middleware/trunk/ACE

Set **ACE** environment variable to the location of ACE. Also, add
**%ACE_ROOT%\lib** and **%ACE_ROOT%\bin** to the **PATH** environment
variable.

If you want to download ACE+TAO+CIAO+DAnCE, then use the following location

   https://svn.dre.vanderbilt.edu/DOC/Middleware/trunk


### GAME

Download the latest version of **GAME** from the appropriate distribution
location below depending on what you can access:

    git@github.iu.edu:SEDS/GAME.git
    git://git.dre.vanderbilt.edu/cosmic/game.git

Set **GAME_ROOT** environment variable to the location of GAME. Also, add
**%GAME_ROOT%\lib** and **%GAME_ROOT%\bin** to the **PATH** environment
variable.

### CoSMIC

Download the latest version of **CoSMIC** from its **Git** repo:

    git://git.dre.vanderbilt.edu/cosmic/cosmic.git

Set **COSMIC_ROOT** environment variable to the location of CoSMIC. Also, add
**%COSMIC_ROOT%\lib** and **%COSMIC_ROOT%\bin** to the **PATH** environment
variable.


Building the Sources
---------------------

First, make sure that "ace/config.h" exist in %ACE_ROOT%. If not, create it

You can build both CoSMIC, GAME, and ACE using a single workspace. We 
actually recommend this since it does not require managing two separate 
workspaces to complete the build. Build CoSMIC, GAME, and ACE using the 
following steps:

    cd %COSMIC_ROOT%
    %ACE_ROOT%\bin\mwc.pl -type vc9 CoSMIC_GAME.mwc
    devenv /useenv CoSMIC_GAME.sln

If you built ACE with versioned namespace support (i.e., -features versioned_namespace=1),
then make sure you enable versioned namespace support with building 
CoSMIC. If you do not enable this support, then you will have link
errors in the end.

The binaries will be installed in either %COSMIC_ROOT%\lib and 
%COSMIC_ROOT%\bin depending on the type of binary built.
