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




CRectangle::CRectangle(EBRUSHSTYLE _iBrushStyle, int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _iPenWidth, int _X, int _Y) {

	m_iBrushStyle = _iBrushStyle;
	m_iHatchStyle = _iHatchStyle;
	m_iFillColor = _FillColor;
	m_iPenStyle = _iPenStyle;
	m_penColor = _PenColor;
	m_iPenWidth = _iPenWidth;
	m_iStartX = _X;
	m_iStartY = _Y;
}

CRectangle::CRectangle() {

}

CRectangle::~CRectangle() {

}


void CRectangle::Draw(HDC _hdc) {
	// Create the green pen:
	HPEN currentPen = CreatePen(m_iPenStyle, m_iPenWidth, m_penColor);
	// Select the pen into the context:
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, currentPen));

	Rectangle(_hdc, m_iStartX, m_iStartY, m_iEndX, m_iEndY);


	
	int FillRect(
		HDC hDC, // Handle to device context.
		const RECT *lprc,// Pointer to structure

		// with rectangle.
		HBRUSH hbr);
		


	SelectObject(_hdc, old_pen); // Restore old pen.
	DeleteObject(currentPen); // Delete the green pen.
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
