@rem *********************************************
@rem ** Build the vc71 version of CUTS
@rem *********************************************

@setlocal
@call "%VS71COMNTOOLS%vsvars32.bat"
@call ant.bat -Dmpc.type=vc71 %*
@endlocal
