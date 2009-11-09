#ifndef MOBIES_SM_export_H
#	define MOBIES_SM_export_H
#	ifndef SM_Export 
#		if defined (SM_HAS_DLL) && (SM_HAS_DLL == 1)
#			if defined (SM_EXPORT)
#				define SM_Export __declspec(dllexport)
#			else
#				define SM_Export __declspec(dllimport)
#			endif /* SM_EXPORT */
#		else
#			define SM_Export 
#		endif /* SM_HAS_DLL */
#	endif /* ifndef SM_Export  */
#endif /* MOBIES_SM_export_H */
