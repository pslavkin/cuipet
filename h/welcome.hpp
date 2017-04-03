#ifndef WELCOME
#define WELCOME

#include <panel.h>

//---------------------------------------------------------------------------------------------------
class Welcome{
public:
#define VERSION 			"V0.1"
	static void  			Create_Welcome		(void);
	static void* 			Print_Next_Character_Rti(void* Arg1);
private:
	static Sheet* 			W;
	static unsigned char 		Printing;
	static unsigned int 		Actual_Char;
	static const char* 		Presentation;
	static pthread_t 		PT_Rti;
	static struct timespec 		Rti_Delay;
};

#endif
