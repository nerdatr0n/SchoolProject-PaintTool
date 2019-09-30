/***********************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2019 Media Design School

  File Name   :   canvas.cpp
  Description :   [One line description of what is the file is for]
  Author      :   David Haverland
  Mail        :   david.hav8466@mediadesign.school.nz
********************/



#include "canvas.h"
#include "shape.h"

CCanvas::CCanvas()
{

}
CCanvas::~CCanvas()
{
	while (!m_shapes.empty()) {
		delete m_shapes.back();
		m_shapes.pop_back();
	}
}
bool CCanvas::Initialise(HWND _hwnd, int _iWidth, int _iHeight)
{
	return true;
}
CBackBuffer* CCanvas::GetBackBuffer()
{
	return nullptr;
}
bool CCanvas::Draw(HDC _hdc)
{
	auto iter = m_shapes.begin();
	while (iter != m_shapes.end())
	{
		(*iter)->Draw(_hdc);
		iter++;
	}
	return true;
}
void CCanvas::Save(HWND _hwnd)
{

}
void CCanvas::AddShape(IShape* _shape)
{
	m_shapes.push_back(_shape);
}