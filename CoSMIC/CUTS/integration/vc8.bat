@rem *********************************************
@rem ** Build the vc8 version of CUTS
@rem *********************************************

@setlocal
@call "%VS80COMNTOOLS%vsvars32.bat"
@call ant.bat -Dmpc.type=vc8 %*
@endlocal
