/***********************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2019 Media Design School

  File Name   :   [Filename]
  Description :   [One line description of what is the file is for]
  Author      :   [Your name]
  Mail        :   [your.name]@mediadesign.school.nz
********************/



#include "shape.h"

IShape::IShape()
{

}

void IShape::SetStartX(int _iStartX)
{
	m_iStartX = _iStartX;
}

void IShape::SetEndX(int _iEndX)
{
	m_iEndX = _iEndX;
}

void IShape::SetStartY(int _iStartY)
{
	m_iStartY = _iStartY;
}
void IShape::SetEndY(int _iEndY)
{
	m_iEndY = _iEndY;

}

//void SetColor(COLORREF _newColor);



