#include "init.h"

#define SPACE_KEY   65

/* Определение функций */
void draw(void);  /* draw.c */
void start_time(void);  /* time.c */


/* Глобальные данные */
extern struct s_init ini; /* init.c */

int check_event(void)
{

  XEvent ev;

  if(XPending(ini.dpy) > 0)
  {
      XNextEvent(ini.dpy, &ev);

      switch(ev.type)
      {
          case ClientMessage:
              return 0;
              break;

	  case KeyPress:
                if(ev.xkey.keycode == SPACE_KEY)
		{
		    start_time();	
		    draw();
		}    
                break;    
      }


  }

  return 1;
}
