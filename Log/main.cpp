
#include <iostream>
#include "Log.h"

int main()
{
	namespace clog = common::log;
	
	clog::Error( clog::ERROR_CRITICAL, 1, "error1" );
	clog::Error( clog::ERROR_CRITICAL, 2, "error2 %d %d", 10, 100 );

	clog::Log( clog::LOG_F_N_O, clog::LOG_PACKET, 1, "log1" );
	clog::Log( clog::LOG_F_N_O, clog::LOG_PACKET, 2, "log2", 11, 22 );


	return 0;
}
