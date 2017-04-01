#ifndef FRAMEWORK
#define FRAMEWORK

#include <panel.h>

//---------------------------------------------------------------------------------------------------
class Framework{
public:
	static 				Sheet* Inst_Buf[];
	static unsigned short int 	Inst_Count;
	static void  			Create_Framework		(void);
	static void  			Select_Sheet			(unsigned char Sheet);
	static void 			Select_Next_Sheet		(void);
	static void 			Select_Prev_Sheet		(void);
	static void 			Toogle_Actual_Sheet_Full_Screen	(void);

					Framework			(void);
	 				~Framework			(void);
	static unsigned char 		Actual_Sheet;
	static unsigned char 		Full_Screen;
private:
	static const unsigned char 	MAX_SHEETS=7;
};

#endif
