#ifndef FRAMEWORK
#define FRAMEWORK

#include <panel.h>

//---------------------------------------------------------------------------------------------------
class Framework{
public:
	static 				Sheet* Inst_Buf[];
	static unsigned short int 	Inst_Count;
	static void  			Create_Framework(void);

				Framework			(void);
	 			~Framework			(void);
private:
};

#endif
