#ifndef WELCOME
#define WELCOME

#include <panel.h>
#include <thread>

//---------------------------------------------------------------------------------------------------
class Welcome{
public:
#define VERSION 			"V0.1"
					Welcome			(void);
	static void 			Print_Next_Character_Rti(void);
private:
	static Sheet* 			W;
	static unsigned char 		Printing;
	static unsigned int 		Actual_Char;
	static const char* 		Presentation;
	static unsigned int 		Rti_Delay;
	std::thread			*T;
};

#endif
