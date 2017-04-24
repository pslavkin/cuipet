#include <cdk.h>
#include <panel.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "screen_update.h"
#include "sheet.hpp"
#include "menu.hpp"
#include "analog_clk.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>

////----------------------------------------------------------------------------------------------------
	Sheet::Sheet(WINDOW *Ext_Win)
{
	Win= 			Ext_Win!=NULL?Ext_Win:newwin(1, 1, 0,0);
	Panel= 			new_panel(Win);
}
void 	Sheet::Redraw_Box(void)
{
	wattron(Win,COLOR_PAIR(1));
	box   	  	(Win,0,0);
	wattroff(Win,COLOR_PAIR(1));
	wattron(Win,COLOR_PAIR(1));
	mvwprintw 	(Win,0,5,Name);
	wattroff(Win,COLOR_PAIR(1));
	update_panels();
}
void 	Sheet::Hide_Box(void)
{
	wborder	  	(Win,' ',' ',' ',' ',' ',' ',' ',' ');
	update_panels();
}
void 	Sheet::Set_Name(char* Sheet_Name)
{
	strcpy(Name,Sheet_Name);	
}
void 	Sheet::Set_Size(unsigned short int Height,unsigned short int Width)
{
	wclear(Win);
	wresize(Win,Height,Width);
	Redraw_Box();
	Menu::Main_Sheet->Touch_Win();	//sino quedan residuos del box
	update_panels();
}
unsigned short int Sheet::Get_Height(void)
{
	return getbegy(Win);
}
unsigned short int Sheet::Get_Width(void)
{
	return getbegx(Win);
}
char  	Sheet::To_Up(void)
{
	if((getbegy(Win)-1)>Menu::Menu::Main_Sheet->Beg_Y()) {
		Sheet::Move_Panel(Panel,getbegy(Win)-1,getbegx(Win));
		return 0;
	}
	else return -1;
}
char 	Sheet::To_Down(void)
{
	if((getbegy(Win)+getmaxy(Win)+1)<(Menu::Main_Sheet->Beg_Y()+Menu::Main_Sheet->Max_Y())) {
		Sheet::Move_Panel(Panel,getbegy(Win)+1,getbegx(Win));
		return 0;
	}
	else return -1;
}
char 	Sheet::To_Right(void)
{
	if((getbegx(Win)+getmaxx(Win)+1)<(Menu::Main_Sheet->Beg_X()+Menu::Main_Sheet->Max_X())) {
		Sheet::Move_Panel(Panel,getbegy(Win),getbegx(Win)+1);
		return 0;
	}
	else return -1;
}
char 	Sheet::To_Left(void)
{
	if((getbegx(Win)-1)>Menu::Main_Sheet->Beg_X()) {
		Sheet::Move_Panel(Panel,getbegy(Win),getbegx(Win)-1);
		return 0;
	}
	else return -1;
}
void 	Sheet::Inc_Width(void)
{
	if((getmaxx(Win)+getbegx(Win)+1)<Menu::Main_Sheet->Max_X()) {
			wclear(Win);
			wresize(Win,getmaxy(Win),getmaxx(Win)+1);
	}
	Redraw_Box();
	update_panels();
}
void 	Sheet::Dec_Width(void)
{
	if(getmaxx(Win)>MIN_WIDTH) {
		wclear(Win);
		wresize(Win,getmaxy(Win),getmaxx(Win)-1);
	}
	Redraw_Box();
	Menu::Main_Sheet->Touch_Win();	//sino quedan residuos del box
	update_panels();
}
void 	Sheet::Inc_Height(void)
{
	if((getmaxy(Win)+getbegy(Win)+1)<Menu::Main_Sheet->Max_Y()) {
			wclear(Win);
			wresize(Win,getmaxy(Win)+1,getmaxx(Win));
	}
	Redraw_Box();
	update_panels();
}
void 	Sheet::Dec_Height(void)
{
	if(getmaxy(Win)>MIN_HEIGHT) {
			wclear(Win);
			wresize(Win,getmaxy(Win)-1,getmaxx(Win));
	}
	Redraw_Box();
	Menu::Main_Sheet->Touch_Win();	//sino quedan residuos del box
	update_panels();
}
void 	Sheet::Set_Pos(unsigned short int Y,unsigned short int X)
{
	Move_Panel(Panel,Y,X);
}
void 	Sheet::Hide(void)
{
	hide_panel(Panel);
	update_panels();
}
void 	Sheet::Unhide(void)
{
	show_panel(Panel);
	update_panels();
}
void 	Sheet::Top(void)
{
	top_panel(Panel);
	update_panels();
}
void 	Sheet::Bottom(void)
{
	bottom_panel(Panel);
	update_panels();
}
void 	Sheet::Select(void)
{
	mvwaddch(Win,1,1,'*'|A_BOLD);
	update_panels();
}
void 	Sheet::Deselect(void)
{
	mvwaddch(Win,1,1,' '|A_NORMAL);
	update_panels();
}
void 	Sheet::Full_Screen(void)
{
	wclear(panel_window(Panel));
	move_panel(Panel,Menu::Main_Sheet->Beg_Y(),Menu::Main_Sheet->Beg_X());
	wresize(panel_window(Panel),Menu::Main_Sheet->Max_Y(),Menu::Main_Sheet->Max_X());
	Sheet::Redraw_Box();
	update_panels();
}
void Sheet::Set_Panel_User_Pointer(Sheet* Ptr)
{
	set_panel_userptr 	(Panel,(void*)Ptr);
}
 	Sheet::~Sheet(void)
{
	del_panel(Panel);
	delwin(Win);
};
void 	Sheet::Move_Panel(PANEL* Panel,unsigned short int Y,unsigned short int X)
{
	move_panel(Panel,Y,X);
	update_panels();
}
void 	Sheet::Touch_Win(void)
{
	touchwin(Win);
	update_panels();
}
unsigned short int  	Sheet::Max_Y(void)
{
	return getmaxy(Win);
}
unsigned short int  	Sheet::Max_X(void)
{
	return getmaxx(Win);
}
unsigned short int  	Sheet::Beg_Y(void)
{
	return getbegy(Win);
}
unsigned short int  	Sheet::Beg_X(void)
{
	return getbegx(Win);
}

