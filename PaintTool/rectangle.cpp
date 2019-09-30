/***********************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2019 Media Design School

  File Name   :   rectangle.cpp
  Description :   [One line description of what is the file is for]
  Author      :   David Haverland
  Mail        :   david.hav8466@mediadesign.school.nz
********************/



//	Library Includes
#include <windows.h>
#include <windowsx.h>
#include "rectangle.h"




CRectangle::CRectangle(EBRUSHSTYLE _iBrushStyle, int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _X, int _Y) {

}

CRectangle::CRectangle() {

}

CRectangle::~CRectangle() {

}


void CRectangle::Draw(HDC _hdc) {
	// Create the green pen:
	HPEN green_pen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	// Select the pen into the context:
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, green_pen));

	MoveToEx(_hdc, m_iStartX, m_iStartY, NULL); // Draw the line...
	LineTo(_hdc, m_iStartX, m_iEndY);
	LineTo(_hdc, m_iEndX, m_iEndY);
	LineTo(_hdc, m_iEndX, m_iStartY);
	LineTo(_hdc, m_iStartX, m_iStartY);

	SelectObject(_hdc, old_pen); // Restore old pen.
	DeleteObject(green_pen); // Delete the green pen.
}


void CRectangle::SetHatchStyle(int _iHatchStyle)
{

}

void CRectangle::SetBrushStyle(EBRUSHSTYLE _brushStyle)
{
	
}

void CRectangle::SetFillColor(COLORREF _newColor)
{

}

void CRectangle::SetPenStyle(int _iPenStyle)
{

}

void CRectangle::SetPenColor(COLORREF _newColor)
{

}
