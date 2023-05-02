#include <stdio.h>
#include <stdlib.h>
#include "init.h"

/* Глобальные данные */
extern struct s_init ini; /* init.c */

void bye(char* str)
{
    printf("%s\n", str);

    if(ini.gc != 0)
        XFreeGC(ini.dpy, ini.gc);
    
    if(ini.win != 0)
        XDestroyWindow(ini.dpy, ini.win);	    


    if(ini.dpy != 0)
        XCloseDisplay(ini.dpy);


   exit(0); 

}
