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


#ifndef __ELLIPSE_H__
#define __ELLIPSE_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>

#include "shape.h"




class CEllipse : public IShape
{
public:
	CEllipse(EBRUSHSTYLE _iBrushStyle, int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _iPenWidth, int _X, int _Y);
	CEllipse();
	virtual ~CEllipse();

	virtual void Draw(HDC _hdc);
	void SetColor(COLORREF _newColor);


private:
	EBRUSHSTYLE m_iBrushStyle;
	int m_iHatchStyle;
	COLORREF m_iFillColor;
	int m_iPenStyle;
	COLORREF m_penColor;
	int m_iPenWidth;
};

#endif