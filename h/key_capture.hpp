#ifndef KEY_CAPTURE
#define KEY_CAPTURE

#include <pthread.h>

//----------------------------------------------------------------------------------------------------
class Key_Capture{
public:
	pthread_t 	PT_Rti;
	static void* 	Rti 			(void* Arg1);
			Key_Capture		(void);
	
private:
	static const unsigned long	Rti_Time=10000000;
};
#endif
//----------------------------------------------------------------------------------------------------
