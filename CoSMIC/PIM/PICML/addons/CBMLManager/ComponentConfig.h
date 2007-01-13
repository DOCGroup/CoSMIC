// Component configuration file automatically generated as ComponentConfig.h
// by ConfigureComponent on Wed Oct 04 17:24:48 2006


#define RAWCOMPONENT

// COM UUID-s, names and progID

#define TYPELIB_UUID "9289091B-ECBE-4934-B631-E3F69F3940C0"
#define TYPELIB_NAME "MGA AddOn TypeLibrary (CBMLManager)"
#define COCLASS_UUID "FC3DDE48-DD56-4F65-87DD-7DE9A262CEDC"
#define COCLASS_NAME "MGA AddOn CoClass (CBMLManager)"
#define COCLASS_PROGID "MGA.AddOn.CBMLManager"


// This name will appear in the popup window for interpreter selection.
#define COMPONENT_NAME "CBML Manager"


// This text will appear in the toolbar icon tooltip and in the menu.
#define TOOLTIP_TEXT "CBML Manager AddOn"


// This #define determines the interpreter type:
#define GME_ADDON

/**
 * GME add-on event mask. This add-on handles the following
 * events.
 *
 * OBJEVENT_CREATED
 * OBJEVENT_DESTROYED
 * OBJEVENT_SELECT
 */
#define ADDON_EVENTMASK \
  (OBJEVENT_CREATED | OBJEVENT_DESTROYED | OBJEVENT_SELECT | OBJEVENT_CLOSEMODEL)

// The name of the paradigm(s). The GME will use this component
// for this paradigm. Separate the names of paradigms by commas.
#define PARADIGMS "PICML"


// This is the location of the GME interfaces file (Mga.idl, Meta.idl, etc)
#define GME_BASE .


// not defined: #define BON_ICON_SUPPORT

#define BON_CUSTOM_TRANSACTIONS

#define REGISTER_SYSTEMWIDE

// Just to please the whims of those Microsoft jerks:
#define COCLASS_UUID_EXPLODED1 0xFC3DDE48
#define COCLASS_UUID_EXPLODED2  0xDD56
#define COCLASS_UUID_EXPLODED3  0x4F65
#define COCLASS_UUID_EXPLODED4  0x87
#define COCLASS_UUID_EXPLODED5  0xDD
#define COCLASS_UUID_EXPLODED6  0x7D
#define COCLASS_UUID_EXPLODED7  0xE9
#define COCLASS_UUID_EXPLODED8  0xA2
#define COCLASS_UUID_EXPLODED9  0x62
#define COCLASS_UUID_EXPLODED10  0xCE
#define COCLASS_UUID_EXPLODED11  0xDC
