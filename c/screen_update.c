#include <cdk/cdk.h>
#include <ncurses.h>
#include <panel.h>
#include <pthread.h>
#include "screen_update.h"
//----------------------------------------------------------------------------------------------------
pthread_t 	PT_Screen_Update_Rti;
static struct timespec 		Rti_Delay={0,100000000}; //100 milis
//----------------------------------------------------------------------------------------------------
void Init_Screen_Update(void)
{
	pthread_create 	(&PT_Screen_Update_Rti, NULL, Screen_Update_Rti, NULL);
}
void* Screen_Update_Rti(void* Arg1)
{
	while(1) {
		nanosleep(&Rti_Delay,&Rti_Delay);
			doupdate();			//cada tanto hago el do update, ya que el resto de las funciones se encargan de hacer el update_panels que basicamente refresca en ram los cambios, mientras que esta funcion lo hace en pantalla.. con eso evito los flikeos y queda mas cuadrado todo...
	}
}
void Destroy_Screen_Update(void)
{
	pthread_exit(&PT_Screen_Update_Rti);
}
//----------------------------------------------------------------------------------------------------
