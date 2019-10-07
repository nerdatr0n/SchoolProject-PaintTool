#include "backBuffer.h"

CBackBuffer::CBackBuffer()
{
}

CBackBuffer::~CBackBuffer()
{
}

bool CBackBuffer::Initialise(HWND _hWnd, int _iWidth, int _iHeight)
{
	return false;
}

HDC CBackBuffer::GetBFDC() const
{
	return HDC();
}

int CBackBuffer::GetWidth() const
{
	return 0;
}

void CBackBuffer::Clear()
{
}

void CBackBuffer::Present()
{
}
