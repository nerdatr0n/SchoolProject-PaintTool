/***********************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2019 Media Design School

  File Name   :   main.cpp
  Description :   [One line description of what is the file is for]
  Author      :   David Haverland
  Mail        :   david.hav8466@mediadesign.school.nz
********************/

//#define WIN32_LEAN_AND_MEAN

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.
#include <shobjidl.h>  // For bitmaps


#include "resource.h"
#include "shape.h"
#include "line.h"
#include "canvas.h"
#include "rectangle.h"
#include "ellipse.h"
#include "polygon.h"
#include "stamp.h"
#include "backBuffer.h"

#define WINDOW_CLASS_NAME L"WINCLASS1"

//Global variables
HINSTANCE g_hInstance;
CCanvas* g_pCanvas;
IShape* g_pShape = 0;
HMENU g_hMenu;

//Enum to decalre the type of tool supported by the application.
enum ESHAPE
{	
	FREEHAND = 0,
	LINESHAPE,
	RECTANGLESHAPE,
	ELLIPSESHAPE,
	POLYGONSHAPE,
	STAMP
};



void GameLoop()
{
	//One frame of game logic occurs here...
}

LRESULT CALLBACK WindowProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	// This is the main message handler of the system.
	PAINTSTRUCT ps; // Used in WM_PAINT.
	HDC hdc;        // Handle to a device context.
	static ESHAPE s_currentShape = FREEHAND;
	static int s_iMouseX;
	static int s_iMouseY;
	static bool s_bMouseDown = false;

	// For the pen
	static int s_iPenStyle;
	static int s_iPenWidth;
	static COLORREF s_penColor = RGB(0, 0, 0);

	// For the fill
	static EBRUSHSTYLE s_iBrushStyle;
	static int s_iHatchStyle;
	static COLORREF s_FillColor = RGB(255, 255, 255);

	// For the stamp-bitmap
	static LPWSTR s_BitmapFilePath;


	switch (_msg)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here.
		g_pCanvas = new CCanvas();

		// Return Success.
		return (0);
	}
	break;

	


	case WM_PAINT:
	{
		hdc = BeginPaint(_hwnd, &ps);
		// You would do all your painting here...
		
		g_pCanvas->Draw(hdc);

		EndPaint(_hwnd, &ps);
		// Return Success.

	
		return (0);
	}
	break;

	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{

		case ID_PEN_COLOR:
		{

			// Variable for the colour creator
			CHOOSECOLOR cc;

			static COLORREF arrayCustomColors[16];
			ZeroMemory(&cc, sizeof(CHOOSECOLOR));
			cc.lStructSize = sizeof(CHOOSECOLOR);
			cc.hwndOwner = _hwnd;
			cc.lpCustColors = (LPDWORD)arrayCustomColors;
			cc.rgbResult = s_penColor;
			cc.Flags = CC_RGBINIT;

			if (ChooseColor(&cc) == TRUE)
			{
				s_penColor = cc.rgbResult;
			}
		}
		break;

		// Changes the line width
		case ID_WIDTH_1:
		{
			s_iPenWidth = 1;
			CheckMenuItem(g_hMenu, ID_WIDTH_1, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_WIDTH_2, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_WIDTH_3, MF_UNCHECKED);
		}
		break;
		case ID_WIDTH_2:
		{
			s_iPenWidth = 3;
			CheckMenuItem(g_hMenu, ID_WIDTH_1, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_WIDTH_2, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_WIDTH_3, MF_UNCHECKED);
		}
		break;
		case ID_WIDTH_3:
		{
			s_iPenWidth = 9;
			CheckMenuItem(g_hMenu, ID_WIDTH_1, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_WIDTH_2, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_WIDTH_3, MF_CHECKED);
		}
		break;

		// Changes the line style
		case ID_STYLE_SOLID:
		{
			s_iPenStyle = 0;
			CheckMenuItem(g_hMenu, ID_STYLE_SOLID, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DASHED, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DOTTED, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_D, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DASHDOTDOT, MF_UNCHECKED);

		}
		break;
		case ID_STYLE_DASHED:
		{
			s_iPenStyle = 1;
			CheckMenuItem(g_hMenu, ID_STYLE_SOLID, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DASHED, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DOTTED, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_D, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DASHDOTDOT, MF_UNCHECKED);
		}
		break;
		case ID_STYLE_DOTTED:
		{
			s_iPenStyle = 2;
			CheckMenuItem(g_hMenu, ID_STYLE_SOLID, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DASHED, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DOTTED, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_D, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DASHDOTDOT, MF_UNCHECKED);
		}
		break;
		case ID_STYLE_D:
		{
			s_iPenStyle = 3;
			CheckMenuItem(g_hMenu, ID_STYLE_SOLID, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DASHED, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DOTTED, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_D, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DASHDOTDOT, MF_UNCHECKED);
		}
		break;
		case ID_STYLE_DASHDOTDOT:
		{
			s_iPenStyle = 4;
			CheckMenuItem(g_hMenu, ID_STYLE_SOLID, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DASHED, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DOTTED, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_D, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DASHDOTDOT, MF_CHECKED);
		}
		break;



		// Changes The fill colour
		case ID_BRUSH_COLOR:
		{
			// Variable for the colour creator
			CHOOSECOLOR cc;

			static COLORREF arrayCustomColors[16];
			ZeroMemory(&cc, sizeof(CHOOSECOLOR));
			cc.lStructSize = sizeof(CHOOSECOLOR);
			cc.hwndOwner = _hwnd;
			cc.lpCustColors = (LPDWORD)arrayCustomColors;
			cc.rgbResult = s_FillColor;
			cc.Flags = CC_RGBINIT;

			if (ChooseColor(&cc) == TRUE)
			{
				s_FillColor = cc.rgbResult;
			}
		}
		break;
				
		// Closes the window
		case ID_FILE_EXIT:
		{
			PostQuitMessage(0);
			break;
		}

		// Sets the shape to the line
		case ID_SHAPE_LINE:
		{
			s_currentShape = LINESHAPE;
			CheckMenuItem(g_hMenu, ID_SHAPE_LINE, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_R, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_ELLIPSE, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_POLYGON, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_STAMP, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_FREEHAND, MF_UNCHECKED);
			break;
		}
				// Sets the shape to the rectangle
		case ID_SHAPE_R:
		{
			s_currentShape = RECTANGLESHAPE;
			CheckMenuItem(g_hMenu, ID_SHAPE_LINE, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_R, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_ELLIPSE, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_POLYGON, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_STAMP, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_FREEHAND, MF_UNCHECKED);
			break;
		}
				// Sets the shape to an ellipse
		case ID_SHAPE_ELLIPSE:
		{
			s_currentShape = ELLIPSESHAPE;
			CheckMenuItem(g_hMenu, ID_SHAPE_LINE, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_R, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_ELLIPSE, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_POLYGON, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_STAMP, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_FREEHAND, MF_UNCHECKED);
			break;
		}
		case ID_SHAPE_POLYGON:
		{
			s_currentShape = POLYGONSHAPE;
			CheckMenuItem(g_hMenu, ID_SHAPE_LINE, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_R, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_ELLIPSE, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_POLYGON, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_STAMP, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_FREEHAND, MF_UNCHECKED);
			break;
		}
		case ID_SHAPE_STAMP:
		{
			HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
			if (SUCCEEDED(hr))
			{
				IFileOpenDialog *pFileOpen;

				// Create the FileOpenDialog object.
				hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

				if (SUCCEEDED(hr))
				{
					// Show the Open dialog box.
					hr = pFileOpen->Show(NULL);

					// Get the file name from the dialog box.
					if (SUCCEEDED(hr))
					{
						IShellItem *pItem;
						hr = pFileOpen->GetResult(&pItem);
						if (SUCCEEDED(hr))
						{

							LPWSTR pszFilePath;

							hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

							// Display the file name to the user.
							if (SUCCEEDED(hr))
							{
								s_BitmapFilePath = pszFilePath;

								CoTaskMemFree(pszFilePath);
							}
							pItem->Release();
						}
					}
					pFileOpen->Release();
				}
				CoUninitialize();
			}

			s_currentShape = STAMP;
			CheckMenuItem(g_hMenu, ID_SHAPE_LINE, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_R, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_ELLIPSE, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_POLYGON, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_STAMP, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_FREEHAND, MF_UNCHECKED);
			break;
		}
		case ID_SHAPE_FREEHAND:
		{
			s_currentShape = FREEHAND;
			CheckMenuItem(g_hMenu, ID_SHAPE_LINE, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_R, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_ELLIPSE, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_POLYGON, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_STAMP, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_SHAPE_FREEHAND, MF_CHECKED);
			break;
		}
		


		// Sets the hatch type
		case ID_STYLE_SOLID40028: {
			s_iHatchStyle = 100;
			CheckMenuItem(g_hMenu, ID_STYLE_SOLID40028, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DIAGONAL, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DIAGONALBUTTHEOTHERWAY, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_CROSS, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_HORIZONTAL, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_Menu, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_VERTICAL, MF_UNCHECKED);
			break;
		}
		case ID_STYLE_DIAGONAL: {
			s_iHatchStyle = 2;
			CheckMenuItem(g_hMenu, ID_STYLE_SOLID40028, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DIAGONAL, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DIAGONALBUTTHEOTHERWAY, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_CROSS, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_HORIZONTAL, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_Menu, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_VERTICAL, MF_UNCHECKED);
			break;
		}
		case ID_STYLE_DIAGONALBUTTHEOTHERWAY: {
			s_iHatchStyle = 3;
			CheckMenuItem(g_hMenu, ID_STYLE_SOLID40028, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DIAGONAL, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DIAGONALBUTTHEOTHERWAY, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_CROSS, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_HORIZONTAL, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_Menu, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_VERTICAL, MF_UNCHECKED);
			break;
		}
		case ID_STYLE_CROSS: {
			s_iHatchStyle = 4;
			CheckMenuItem(g_hMenu, ID_STYLE_SOLID40028, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DIAGONAL, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DIAGONALBUTTHEOTHERWAY, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_CROSS, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_HORIZONTAL, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_Menu, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_VERTICAL, MF_UNCHECKED);
			break;
		}
		case ID_STYLE_HORIZONTAL: {
			s_iHatchStyle = 0;
			CheckMenuItem(g_hMenu, ID_STYLE_SOLID40028, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DIAGONAL, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DIAGONALBUTTHEOTHERWAY, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_CROSS, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_HORIZONTAL, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_Menu, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_VERTICAL, MF_UNCHECKED);
			break;
		}
		case ID_Menu: {
			s_iHatchStyle = 5;
			CheckMenuItem(g_hMenu, ID_STYLE_DIAGONAL, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DIAGONALBUTTHEOTHERWAY, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_CROSS, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_HORIZONTAL, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_Menu, MF_CHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_VERTICAL, MF_UNCHECKED);
			break;
		}
		case ID_STYLE_VERTICAL: {
			s_iHatchStyle = 1;
			CheckMenuItem(g_hMenu, ID_STYLE_DIAGONAL, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_DIAGONALBUTTHEOTHERWAY, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_CROSS, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_HORIZONTAL, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_Menu, MF_UNCHECKED);
			CheckMenuItem(g_hMenu, ID_STYLE_VERTICAL, MF_CHECKED);
			break;
		}



		// Displays the credits
		case ID_HELP_ABOUT:
		{
			MessageBox(_hwnd, L"This paint tool was developed by David Haverland In collaboration with [SAMPLE TEXT] Studios ltd.", L"Author Information", MB_OK | MB_ICONINFORMATION);
			break;
		}
		default:
			break;
		}
		return(0);
	}
	break;


	// For a mouse click
	case WM_LBUTTONDOWN:
	{

		// get the position of the mouse
		s_iMouseX = static_cast<int>(LOWORD(_lparam));
		s_iMouseY = static_cast<int>(HIWORD(_lparam));
		s_bMouseDown = true;

		switch (s_currentShape)
		{

			// Sets up the line
		case LINESHAPE:
		{
			g_pShape = new CLine(s_iPenStyle, s_iPenWidth, s_penColor, s_iMouseX, s_iMouseY);
			g_pCanvas->AddShape(g_pShape);

		}
		break;

		// Sets up the rectangle
		case RECTANGLESHAPE:
		{
			g_pShape = new CRectangle(s_iBrushStyle, s_iHatchStyle, s_FillColor, s_iPenStyle, s_penColor, s_iPenWidth, s_iMouseX, s_iMouseY);
			g_pCanvas->AddShape(g_pShape);
		}
		break;

		// Sets up the ellipse
		case ELLIPSESHAPE:
		{
			g_pShape = new CStamp(g_hInstance, s_BitmapFilePath, s_iMouseX, s_iMouseY);
			g_pShape->SetStartX(s_iMouseX);
			g_pShape->SetStartY(s_iMouseY);
			g_pCanvas->AddShape(g_pShape);
		}
		break;

		case POLYGONSHAPE:
		{

		}
		break;

		case STAMP:
		{
			g_pShape = new CEllipse(s_iBrushStyle, s_iHatchStyle, s_FillColor, s_iPenStyle, s_penColor, s_iPenWidth, s_iMouseX, s_iMouseY);


		}
		break;

		case FREEHAND:
		{
			g_pShape = new CLine(s_iPenStyle, s_iPenWidth, s_penColor, s_iMouseX, s_iMouseY);
			g_pCanvas->AddShape(g_pShape);
			g_pShape = nullptr;
		}
		break;

		default:
			break;
		}

		return (0); // MUST HAVE RETURN  - I CAN HANDLE THIS CASE. DO NOT USE TO DEFAULT CASE.
	}
	break;


	// On mouse release
	case WM_LBUTTONUP:
	{

		// Finishes the shape
		g_pShape = nullptr;

		// Stops it from redrawing a bunch o times
		s_bMouseDown = false;
	}
	break;


	case WM_MOUSEMOVE:
	{
		// get the position of the mouse
		s_iMouseX = static_cast<int>(LOWORD(_lparam));
		s_iMouseY = static_cast<int>(HIWORD(_lparam));

		if (s_bMouseDown == true)
		{
			if (s_currentShape == FREEHAND)
			{ 
				if (g_pShape != nullptr){
					g_pShape->SetEndX(s_iMouseX);
					g_pShape->SetEndY(s_iMouseY);
				}
				
				g_pShape = nullptr;
				g_pShape = new CLine(s_iPenStyle, s_iPenWidth, s_penColor, s_iMouseX, s_iMouseY);
				g_pCanvas->AddShape(g_pShape);

				InvalidateRect(_hwnd, NULL, TRUE);
				UpdateWindow(_hwnd);
			}

			else if (g_pShape != nullptr) // != nullptr
			{
				g_pShape->SetEndX(s_iMouseX);
				g_pShape->SetEndY(s_iMouseY);

				// Re-Draws the window
				InvalidateRect(_hwnd, NULL, TRUE);
				UpdateWindow(_hwnd);
			}

		}

				
		return (0); // MUST HAVE RETURN  - I CAN HANDLE THIS CASE. DO NOT USE TO DEFAULT CASE.
	}
	break;


	// Stops memory leakage, I think
	case WM_DESTROY:
	{
		delete g_pCanvas;
		// Kill the application, this sends a WM_QUIT message.
		PostQuitMessage(0);

		// Return success.
		return (0);
	}
	break;

		default:break;
	} // End switch.

	  // Process any messages that we did not take care of...

	return (DefWindowProc(_hwnd, _msg, _wparam, _lparam));
}


// This is like the "main" or "create" function
int WINAPI WinMain(HINSTANCE _hInstance,
	HINSTANCE _hPrevInstance,
	LPSTR _lpCmdLine,
	int _nCmdShow)
{
	// Makes a window class 
	WNDCLASSEX winclass; // This will hold the class we create.
	HWND hwnd;           // Generic window handle.
	MSG msg;             // Generic message.

	g_hInstance = _hInstance;
	// First fill in the window class structure.
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground =
		static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// register the window class
	if (!RegisterClassEx(&winclass))
	{
		return (0);
	}

	
	g_hMenu = LoadMenu(_hInstance, MAKEINTRESOURCE(IDR_MENU1));


	// create the window
	hwnd = CreateWindowEx(NULL, // Extended style.
		WINDOW_CLASS_NAME,      // Class.
		L"My Paint Tool",   // Title.
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100,                    // Initial x,y.
		1500, 800,                // Initial width, height.
		NULL,                   // Handle to parent.
		g_hMenu,                   // Handle to menu.
		_hInstance,             // Instance of this application.
		NULL);                  // Extra creation parameters.

	// Makes sure it works
	if (!(hwnd))
	{
		return (0);
	}



	// Enter main event loop
	while (true)
	{
		// Test if there is a message in queue, if so get it.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Test if this is a quit.
			if (msg.message == WM_QUIT)
			{
				break;
			}

			// Translate any accelerator keys.
			TranslateMessage(&msg);
			// Send the message to the window proc.
			DispatchMessage(&msg);
		}

		// Main game processing goes here.
		GameLoop(); //One frame of game logic occurs here...
	}

	// Return to Windows like this...
	return (static_cast<int>(msg.wParam));
}
