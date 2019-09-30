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

CEllipse::CEllipse(COLORREF _newColor, int, int)
{

}

CEllipse::CEllipse()
{

}

CEllipse::~CEllipse()
{

}

void CEllipse::Draw(HDC _hdc)
{
	// Create the green pen:
	HPEN green_pen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	// Select the pen into the context:
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, green_pen));

	Ellipse(_hdc, m_iStartX, m_iStartY, m_iEndX, m_iEndY);

	SelectObject(_hdc, old_pen); // Restore old pen.
	DeleteObject(green_pen); // Delete the green pen.
}

void CEllipse::SetColor(COLORREF _newColor)
{

}


