#include <cdk.h>

#include "sheet.hpp"
#include "menu.hpp"
#include "key_capture.hpp"
#include "framework.hpp"

#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>

//----------------------------------------------------------------------------------------------------
const unsigned int Key_Capture::Rti_Time=5;
//----------------------------------------------------------------------------------------------------
	Key_Capture::Key_Capture(void)
{
	T = new std::thread(Rti);
}
//----------------------------------------------------------------------------------------------------
void  Key_Capture::Rti(void)
{
	int Key;
	while(1) {
		std::this_thread::sleep_for(std::chrono::milliseconds(Rti_Time));
		Key=getch();
		switch(Key) {	
			case KEY_F1:
			case ' ':
				Menu::Menu_Inst->Start_Menu_Menu();
				break;
			case KEY_F2:
				break;
			case KEY_F3:
				break;
			case KEY_F4:
				break;
			case KEY_F5:
				break;
			case KEY_F6:	
				break;
			case KEY_F7:
				break;
			case KEY_F8:
				break;
			case KEY_F9:
				break;
			case KEY_F10:
				break;
			case KEY_F11:
				break;
			case KEY_UP:
				Framework::Select_Next_Sheet();
				//Menu::Menu_Inst->Sheet4Top_Panel()->To_Up();
				break;
			case KEY_DOWN:
				Framework::Select_Prev_Sheet();
				//Menu::Menu_Inst->Sheet4Top_Panel()->To_Down();
				break;
			case KEY_RIGHT:
				Menu::Menu_Inst->Sheet4Top_Panel()->To_Right();
				break;
			case KEY_LEFT:
				Menu::Menu_Inst->Sheet4Top_Panel()->To_Left();
				break;
			case KEY_RETURN:
				Framework::Toogle_Actual_Sheet_Full_Screen();
				break;
			case 'l':
				Menu::Menu_Inst->Sheet4Top_Panel()->Inc_Width();
				break;
			case 'h':
				Menu::Menu_Inst->Sheet4Top_Panel()->Dec_Width();
				break;
			case 'j':
				Menu::Menu_Inst->Sheet4Top_Panel()->Inc_Height();
				break;
			case 'k':
				Menu::Menu_Inst->Sheet4Top_Panel()->Dec_Height();
				break;
			case KEY_BACKSPACE:
				break;
			case KEY_HOME:
				break;
			case KEY_ESC:
				exit(0);
				break;
		}
	}
}
//----------------------------------------------------------------------------------------------------

