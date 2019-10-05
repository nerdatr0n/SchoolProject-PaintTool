/***********************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2019 Media Design School

  File Name   :   rectangle.h
  Description :   [One line description of what is the file is for]
  Author      :   David Haverland
  Mail        :   david.hav8466@mediadesign.school.nz
********************/

#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>
#include "shape.h"




class CRectangle : public IShape
{
public:
	CRectangle(EBRUSHSTYLE _iBrushStyle, int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _iPenWidth, int _X, int _Y);
	CRectangle();
	virtual ~CRectangle();

	virtual void Draw(HDC _hdc);
	void SetBrushStyle(EBRUSHSTYLE _brushStyle);
	void SetFillColor(COLORREF _newColor);
	void SetPenStyle (int _iPenStyle);
	void SetPenColor(COLORREF _newColor);
	void SetHatchStyle(int _iHatchStyle);
	

private:
	EBRUSHSTYLE m_iBrushStyle;
	int m_iHatchStyle;
	COLORREF m_iFillColor;
	int m_iPenStyle;
	COLORREF m_penColor;
	int m_iPenWidth;
};

#endif