#ifndef MOBIES_SM_export_H
#	define MOBIES_SM_export_H
#	ifndef eesa 
#		if defined (SM_HAS_DLL) && (SM_HAS_DLL == 1)
#			if defined (SM_EXPORT)
#				define eesa __declspec(dllexport)
#			else
#				define eesa __declspec(dllimport)
#			endif /* SM_EXPORT */
#		else
#			define eesa 
#		endif /* SM_HAS_DLL */
#	endif /* ifndef eesa  */
#endif /* MOBIES_SM_export_H */
