#include "stamp.h"

CStamp::CStamp()
{

}

CStamp::CStamp(HINSTANCE hInstance, wchar_t * filename, int _iX, int _iY)
{
	m_iStartX = _iX;
	m_iStartY = _iY;


}

CStamp::~CStamp()
{

}

void CStamp::Draw(HDC _hdc)
{
	HDC bmHDC = CreateCompatibleDC(_hdc);
}

void CStamp::SetStartX(int _iX)
{

}

void CStamp::SetStartY(int _iY)
{

}
