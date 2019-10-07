/***********************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2019 Media Design School

  File Name   :   line.cpp
  Description :   [One line description of what is the file is for]
  Author      :   David Haverland
  Mail        :   david.hav8466@mediadesign.school.nz
********************/



#include "line.h"

CLine::CLine(int _iStyle, int _iWidth, COLORREF _newColor, int _iStartX, int _iStartY)
{
	m_iStyle = _iStyle;
	m_iWidth = _iWidth;
	m_Color = _newColor;
	m_iStartX = _iStartX;
	m_iStartY = _iStartY;
	m_iEndX = _iStartX;
	m_iEndY = _iStartY;
}

CLine::CLine()
{
	m_iStyle = PS_SOLID;
	m_Color = RGB(0, 255, 0);
	m_iStartX = 0;
	m_iStartY = 0;
}

CLine::~CLine()
{

}

void CLine::Draw(HDC _hdc)
{
	// Create the green pen:
	HPEN currentPen = CreatePen(m_iStyle, m_iWidth, m_Color);

	// Select the pen into the context:
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, currentPen));

	MoveToEx(_hdc, m_iStartX, m_iStartY, NULL); // Draw the line...
	LineTo(_hdc, m_iEndX, m_iEndY);

	SelectObject(_hdc, old_pen); // Restore old pen.
	DeleteObject(currentPen); // Delete the green pen.
}

void CLine::SetWidth(int _iNewWidth)
{

}



