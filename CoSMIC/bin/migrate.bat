@setlocal

@set CLASSPATH=%~dp0/migration/xalan.jar;%~dp0/migration/serializer.jar;%~dp0/migration/xml-apis.jar;%~dp0/migration/xercesImpl.jar;%CLASSPATH%
java org.apache.xalan.xslt.Process -IN %1 -OUT %2 -XSL %3

@endlocal