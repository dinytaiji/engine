#pragma once

class CLoger
{
	enum {};
public:
	static BOOL	WriteLog(LPTSTR data, ...)
	{
		CONST INT LOG_MAX_LENGTH = 1024;
		SYSTEMTIME	SystemTime;
		TCHAR		CurrentDate[32]					= {0,};
		TCHAR		CurrentFileName[MAX_PATH]		= {0,};
		FILE*		FilePtr							= NULL;
		CHAR		DebugLog[LOG_MAX_LENGTH]		= {0,};

		va_list		ap;
		CHAR		Log[LOG_MAX_LENGTH]	= {0,};

		va_start(ap, data);
		vsprintf(Log, data, ap);
		va_end(ap);

		char szPath[MAX_PATH] = {0,};
		GetModuleFileName( GetModuleHandle( NULL ), szPath, MAX_PATH );
		*(strrchr(szPath, '\\')+1) = 0;

		GetLocalTime(&SystemTime);
		sprintf_s(CurrentDate, 32, "%d-%d-%d %d:%d:%d",
			SystemTime.wYear, 
			SystemTime.wMonth, 
			SystemTime.wDay, 
			SystemTime.wHour,
			SystemTime.wMinute,
			SystemTime.wSecond);

		sprintf_s(CurrentFileName, MAX_PATH, "%s/log/LOG_%d-%d-%d %d.log", 
			szPath,
			SystemTime.wYear, 
			SystemTime.wMonth, 
			SystemTime.wDay,
			SystemTime.wHour);

		FilePtr = fopen(CurrentFileName, "a");
		if (!FilePtr)
			return FALSE;

		fprintf(FilePtr, "[%s] %s\n", CurrentDate, Log);
		sprintf_s(DebugLog, LOG_MAX_LENGTH-1, "[%s] %s\n", CurrentDate, Log);

		fflush(FilePtr);

		fclose(FilePtr);
		OutputDebugString(DebugLog);
		printf("%s", DebugLog);

		return TRUE;
	}

	static BOOL	WriteGameLog(LPTSTR data, ...)
	{
#ifdef _DEVELOP_MODE_
		CONST INT LOG_MAX_LENGTH = 1024;
		SYSTEMTIME	SystemTime;
		TCHAR		CurrentDate[32]					= {0,};
		TCHAR		CurrentFileName[MAX_PATH]		= {0,};
		FILE*		FilePtr							= NULL;
		CHAR		DebugLog[LOG_MAX_LENGTH]		= {0,};

		va_list		ap;
		CHAR		Log[LOG_MAX_LENGTH]	= {0,};

		va_start(ap, data);
		vsprintf(Log, data, ap);
		va_end(ap);

		char szPath[MAX_PATH] = {0,};
		GetModuleFileName( GetModuleHandle( NULL ), szPath, MAX_PATH );
		*(strrchr(szPath, '\\')+1) = 0;

		GetLocalTime(&SystemTime);
		sprintf_s(CurrentDate, 32, "%d-%d-%d %d:%d:%d",
			SystemTime.wYear, 
			SystemTime.wMonth, 
			SystemTime.wDay, 
			SystemTime.wHour,
			SystemTime.wMinute,
			SystemTime.wSecond);

		sprintf_s(CurrentFileName, MAX_PATH, "%s/log/GAME_LOG_%d-%d-%d %d.log", 
			szPath,
			SystemTime.wYear, 
			SystemTime.wMonth, 
			SystemTime.wDay,
			SystemTime.wHour);

		FilePtr = fopen(CurrentFileName, "a");
		if (!FilePtr)
			return FALSE;

		fprintf(FilePtr, "[%s] %s\n", CurrentDate, Log);
		sprintf_s(DebugLog, LOG_MAX_LENGTH-1, "[%s] ¢º %s\n", CurrentDate, Log);

		fflush(FilePtr);

		fclose(FilePtr);
		OutputDebugString(DebugLog);
		printf("%s", DebugLog);
#endif

		return TRUE;
	}

	static BOOL	WriteSqlLog(LPTSTR data, ...)
	{
		CONST INT LOG_MAX_LENGTH = 1024;

		SYSTEMTIME	SystemTime;
		TCHAR		CurrentDate[32]					= {0,};
		TCHAR		CurrentFileName[MAX_PATH]		= {0,};
		FILE*			FilePtr							= NULL;
		CHAR			DebugLog[LOG_MAX_LENGTH]		= {0,};

		va_list		ap;
		CHAR		Log[LOG_MAX_LENGTH]	= {0,};

		va_start(ap, data);
		vsprintf(Log, data, ap);
		va_end(ap);

		char szPath[MAX_PATH] = {0,};
		GetModuleFileName( GetModuleHandle( NULL ), szPath, MAX_PATH );
		*(strrchr(szPath, '\\')+1) = 0;

		GetLocalTime(&SystemTime);
		sprintf_s(CurrentDate, 32, "%d-%d-%d %d:%d:%d",
			SystemTime.wYear, 
			SystemTime.wMonth, 
			SystemTime.wDay, 
			SystemTime.wHour,
			SystemTime.wMinute,
			SystemTime.wSecond);

		sprintf_s(CurrentFileName, MAX_PATH, "%s/log/SQL_LOG_%d-%d-%d %d.log", 
			szPath,
			SystemTime.wYear, 
			SystemTime.wMonth, 
			SystemTime.wDay,
			SystemTime.wHour);

		FilePtr = fopen(CurrentFileName, "a");
		if (!FilePtr)
			return FALSE;

		fprintf(FilePtr, "[%s] %s\n", CurrentDate, Log);
		sprintf_s(DebugLog, LOG_MAX_LENGTH-1, "[%s] %s\n", CurrentDate, Log);

		fflush(FilePtr);

		fclose(FilePtr);
		OutputDebugString(DebugLog);
		printf("%s", DebugLog);

		return TRUE;
	}

	static BOOL	WriteLogNoDate(LPTSTR data, ...)
	{
		SYSTEMTIME	SystemTime;
		TCHAR		CurrentDate[32]					= {0,};
		TCHAR		CurrentFileName[MAX_PATH]		= {0,};
		FILE*		FilePtr							= NULL;
		TCHAR		DebugLog[MAX_PATH]		= {0,};

		va_list		ap;
		TCHAR		Log[MAX_PATH]	= {0,};

		va_start(ap, data);
		vsprintf(Log, data, ap);
		va_end(ap);

		char szPath[MAX_PATH] = {0,};
		GetModuleFileName( GetModuleHandle( NULL ), szPath, MAX_PATH );
		*(strrchr(szPath, '\\')+1) = 0;

		GetLocalTime(&SystemTime);
		sprintf_s(CurrentDate, 32, "%d-%d-%d %d:%d:%d",
			SystemTime.wYear, 
			SystemTime.wMonth, 
			SystemTime.wDay, 
			SystemTime.wHour,
			SystemTime.wMinute,
			SystemTime.wSecond);

		sprintf_s(CurrentFileName, MAX_PATH, "%sLOG_%d-%d-%d %d.log", 
			SystemTime.wYear, 
			SystemTime.wMonth, 
			SystemTime.wDay,
			SystemTime.wHour);

		FilePtr = fopen(CurrentFileName, "a");
		if (!FilePtr)
			return FALSE;

		fprintf(FilePtr, "%s", Log);
		sprintf_s(DebugLog, MAX_PATH, "%s", Log);

		fflush(FilePtr);

		fclose(FilePtr);

		OutputDebugString(DebugLog);
		printf("%s", DebugLog);

		return TRUE;
	}
};