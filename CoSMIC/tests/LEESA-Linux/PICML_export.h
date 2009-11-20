#ifndef MOBIES_PICML_export_H
#	define MOBIES_PICML_export_H
#	ifndef PICML_Export 
#		if defined (PICML_HAS_DLL) && (PICML_HAS_DLL == 1)
#			if defined (PICML_EXPORT)
#				define PICML_Export __declspec(dllexport)
#			else
#				define PICML_Export __declspec(dllimport)
#			endif /* PICML_EXPORT */
#		else
#			define PICML_Export 
#		endif /* PICML_HAS_DLL */
#	endif /* ifndef PICML_Export  */
#endif /* MOBIES_PICML_export_H */
