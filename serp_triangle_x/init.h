#ifndef INIT_H
#define INIT_H

#include <X11/Xlib.h>

struct s_init
{
    Display* dpy;	
    int width_win;
    int height_win;
    Window win;
    GC gc;
    int screen;
};


#endif /* INIT_H */

