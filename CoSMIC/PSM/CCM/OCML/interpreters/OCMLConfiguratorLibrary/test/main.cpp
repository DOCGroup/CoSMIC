#include <windows.h>
#include "assert.h"

#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>

#include "../DllEntry.hpp"

LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM); 

bool pause = false;

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
  WNDCLASSEX wcx; 

  wcx.cbSize = sizeof(wcx);
  wcx.style = CS_HREDRAW | CS_VREDRAW;
  wcx.lpfnWndProc = MainWndProc;
  wcx.cbClsExtra = 0;
  wcx.cbWndExtra = 0;
  wcx.hInstance = hInstance;
  wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcx.hbrBackground = (HBRUSH)( COLOR_WINDOW+1 );
  wcx.lpszMenuName =  "MainMenu";
  wcx.lpszClassName = "MainWClass";
  wcx.hIconSm = NULL;

  ATOM a = RegisterClassEx(&wcx); 
  assert(a);

  HWND hwnd = CreateWindow("MainWClass",
                           "Test DLL",
                           WS_OVERLAPPEDWINDOW,
                           CW_USEDEFAULT,
                           CW_USEDEFAULT,
                           CW_USEDEFAULT,
                           CW_USEDEFAULT,
                           (HWND) NULL,
                           (HMENU) NULL,
                           hInstance,
                           (LPVOID) NULL);
  assert(hwnd);

  ShowWindow(hwnd, nCmdShow); 
  UpdateWindow(hwnd); 

  long bRet;
  MSG msg;
  while((bRet = GetMessage( &msg, NULL, 0, 0 )) != 0 ) 
    {
      if (bRet != -1)
        {
          TranslateMessage( &msg );
          DispatchMessage( &msg );
        }
    }

  return 0;
}

// Windows Callback Procedure
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  PAINTSTRUCT ps;
  HDC hDC;

  switch( msg ) {
  case WM_PAINT:
    hDC = BeginPaint( hWnd, &ps );
    TextOut( hDC, 10, 10, "Click on this form to launch dll", 32 );
    EndPaint( hWnd, &ps );
    break;

  case WM_DESTROY:
    PostQuitMessage( 0 );
    break;

  case WM_LBUTTONUP:
    {
      if (pause)
        return 0;
#ifdef _DEBUG
      HMODULE hModule = LoadLibrary("OCMLConfiguratord.dll");
#elif
      HMODULE hModule = LoadLibrary("OCMLConfigurator.dll");
#endif
      assert(hModule);

      DLLFunctionPtr pProc =
        (DLLFunctionPtr)GetProcAddress(hModule, "DLLFunction");
      assert(pProc);

      // Read the values from file
      std::string values;
      std::ifstream values_file("c:\\Data\\values.xml");
      values_file.unsetf(std::ios_base::skipws);
      std::copy(std::istream_iterator<char>(values_file),
                std::istream_iterator<char>(),
                std::back_inserter(values));

      // Load up the DLL and call DLLFunction
      pause = true;
      char* new_values = (pProc)(values.c_str(), values.size());
      if (new_values)
        {
          std::ofstream of("c:\\Data\\values.xml");
          of << new_values;
        }
      FreeLibrary(hModule);
      pause = false;
    }
    break;

  default:
    return( DefWindowProc( hWnd, msg, wParam, lParam ));
  }
  return 0;
}
