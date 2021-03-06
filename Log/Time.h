//------------------------------------------------------------------------
// Name:    Time.h
// Author:  jjuiddong
// Date:    12/23/2012
// 
// 시간을 스트링으로 생성한다.
//------------------------------------------------------------------------
#pragma once

#include <windows.h>
#include <winbase.h>
#include "String.h"

namespace common
{
	// (xx년xx월xx일) xx시xx분xx초
	static std::string GetTimeString()
	{
		SYSTEMTIME t;
		GetLocalTime(&t);
		return common::format("(%d-%d-%d) %d시%d분%d초", t.wYear, t.wMonth, t.wDay, 
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
