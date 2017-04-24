#include <ncurses.h>
#include "screen_update.h"
#include <iostream>
#include <thread>
//----------------------------------------------------------------------------------------------------
unsigned char Rti_Delay=10; 
//----------------------------------------------------------------------------------------------------
void Init_Screen_Update(void)
{
	new std::thread(Screen_Update_Rti);
}
void Screen_Update_Rti(void)
{
	while(1) {
		std::this_thread::sleep_for(std::chrono::milliseconds(Rti_Delay));
		doupdate();			//cada tanto hago el do update, ya que el resto de las funciones se encargan de hacer el update_panels que basicamente refresca en ram los cambios, mientras que esta funcion lo hace en pantalla.. con eso evito los flikeos y queda mas cuadrado todo...
	}
}
//----------------------------------------------------------------------------------------------------
