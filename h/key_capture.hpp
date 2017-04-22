#ifndef KEY_CAPTURE
#define KEY_CAPTURE

#include <thread>
#include <chrono>
#include <unistd.h>

//----------------------------------------------------------------------------------------------------
class Key_Capture{
public:
	static void 			Rti 			(void);
					Key_Capture		(void);
	static const unsigned int	Rti_Time;
	
private:
	std::thread *T;
};
#endif
//----------------------------------------------------------------------------------------------------
