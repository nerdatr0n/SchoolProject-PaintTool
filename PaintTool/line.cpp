/***********************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2019 Media Design School

  File Name   :   line.cpp
  Description :   [One line description of what is the file is for]
  Author      :   David Haverland
  Mail        :   [your.name]@mediadesign.school.nz
********************/



#include "line.h"

CLine::CLine(int _iStyle, int _iWidth, COLORREF _newColor, int _iStartX, int _iStartY)
{

}
CLine::CLine()
{

}
CLine::~CLine()
{

}

void CLine::Draw(HDC _hdc)
{
	// Create the green pen:
	HPEN green_pen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	// Select the pen into the context:
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, green_pen));

	MoveToEx(_hdc, m_iStartX, m_iStartY, NULL); // Draw the line...
	LineTo(_hdc, m_iEndX, m_iEndY);

	SelectObject(_hdc, old_pen); // Restore old pen.
	DeleteObject(green_pen); // Delete the green pen.
}
void CLine::SetWidth(int _iNewWidth)
{

}



