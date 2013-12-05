#ifndef MOBIES_CQML_export_H
#	define MOBIES_CQML_export_H
#	ifndef CQML_Export 
#		if defined (CQML_HAS_DLL) && (CQML_HAS_DLL == 1)
#			if defined (CQML_EXPORT)
#				define CQML_Export __declspec(dllexport)
#			else
#				define CQML_Export __declspec(dllimport)
#			endif /* CQML_EXPORT */
#		else
#			define CQML_Export 
#		endif /* CQML_HAS_DLL */
#	endif /* ifndef CQML_Export  */
#endif /* MOBIES_CQML_export_H */
