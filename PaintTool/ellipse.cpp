/***********************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2019 Media Design School

  File Name   :   ellipse.h
  Description :   [One line description of what is the file is for]
  Author      :   David Haverland
  Mail        :   david.hav8466@mediadesign.school.nz
********************/

#include "ellipse.h"




CEllipse::CEllipse(EBRUSHSTYLE _iBrushStyle, int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _iPenWidth, int _X, int _Y)
{
	m_iBrushStyle = _iBrushStyle;
	m_iHatchStyle = _iHatchStyle;
	m_iFillColor = _FillColor;
	m_iPenStyle = _iPenStyle;
	m_penColor = _PenColor;
	m_iPenWidth = _iPenWidth;
	m_iStartX = _X;
	m_iStartY = _Y;
}

CEllipse::CEllipse()
{

}

CEllipse::~CEllipse()
{

}

void CEllipse::Draw(HDC _hdc)
{
	// Create the pen:
	HPEN currentPen = CreatePen(m_iPenStyle, m_iPenWidth, m_penColor);
	// Select the pen into the context:
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, currentPen));
	HBRUSH currentBrush;

	if (m_iHatchStyle == 100)
	{
		currentBrush = CreateSolidBrush(m_iFillColor);
	}
	else
	{
		currentBrush = CreateHatchBrush(m_iHatchStyle, m_iFillColor);;
	}

	HBRUSH old_Brush = static_cast<HBRUSH>(SelectObject(_hdc, currentBrush));

	Ellipse(_hdc, m_iStartX, m_iStartY, m_iEndX, m_iEndY);




	SelectObject(_hdc, old_pen); // Restore old pen.
	DeleteObject(currentPen); // Delete the green pen.

	SelectObject(_hdc, old_Brush); // Restore old pen.
	DeleteObject(currentBrush); // Delete the green pen.
}

void CEllipse::SetColor(COLORREF _newColor)
{

}


