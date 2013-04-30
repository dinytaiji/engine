//------------------------------------------------------------------------
// Name:    Time.h
// Author:  jjuiddong
// Date:    12/23/2012
// 
// �ð��� ��Ʈ������ �����Ѵ�.
//------------------------------------------------------------------------
#pragma once

#include <windows.h>
#include <winbase.h>
#include "String.h"

namespace common
{
	// (xx��xx��xx��) xx��xx��xx��
	static std::string GetTimeString()
	{
		SYSTEMTIME t;
		GetLocalTime(&t);
		return common::format("(%d-%d-%d) %d��%d��%d��", t.wYear, t.wMonth, t.wDay, 
			t.wHour, t.wMinute, t.wSecond);
	}

	/// YY-MM-DD-HH
	static std::string GetDateString()
	{
		SYSTEMTIME t;
		GetLocalTime(&t);
		return common::format("%d-%d-%d-%d", t.wYear, t.wMonth, t.wDay, t.wHour );
	}

}