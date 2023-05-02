#include "init.h"

#define BORDER  10
#define CFP     CopyFromParent     /* Меньше писанины */
#define BLACK BlackPixel(ini.dpy, ini.screen)
#define WHITE WhitePixel(ini.dpy, ini.screen)

/* Определение функций */
void bye(char* str);  /* bye.c */

/* Глобальные данные */
struct s_init ini;

void init(void)
{
    Window root;
    XSetWindowAttributes swa;
    unsigned long valuemask;
    Atom close_win;       /* атом для корректного закрытия окна */
    int screen;


    ini.dpy = XOpenDisplay(NULL);

    if(ini.dpy == 0)
        bye("Ошибка : XOpenDisplay");

    /* Задаю геометрию окна */
    ini.width_win = 600;
    ini.height_win = 600;

    root = XDefaultRootWindow(ini.dpy);
    ini.screen = DefaultScreen(ini.dpy);

    swa.background_pixel = BLACK;
    swa.event_mask = KeyPressMask | KeyReleaseMask;

    valuemask = CWEventMask | CWBackPixel;
    
    /* Создаю окно */
    ini.win = XCreateWindow(ini.dpy, root, 0, 0, ini.width_win,
                           ini.height_win, BORDER, 0, CFP, CFP,
                           valuemask, &swa);


    if(ini.win == 0)
        bye("Ошибка XCreateWindow");


    /* Создаю холст для рисования */
    ini.gc = XCreateGC(ini.dpy, root, 0, 0);

    if(ini.gc == 0)
        bye("Ошибка GC");

    /*получаю атом для корректного закрытия окна*/
    close_win = XInternAtom(ini.dpy, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(ini.dpy, ini.win, &close_win, True);


    XMapWindow(ini.dpy, ini.win);
  
    XStoreName(ini.dpy, ini.win, "Serpinski_triangle");


}
