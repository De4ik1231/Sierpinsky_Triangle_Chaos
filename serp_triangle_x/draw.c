#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "init.h"

#define NUM_POINT      3
#define TARGET_POINT   50000
#define WHITE WhitePixel(ini.dpy, ini.screen)

struct point
{
    int x;
    int y;
};

/* Опреление функций */
void end_time(void); /* time.c */

/* Глобальные данные */
static int point_counter = 0;
extern struct s_init ini; /* init.c */
static struct point T_Point[NUM_POINT]; /* массив для точек */


void init_draw(void)
{
    T_Point[0].x = 0;
    T_Point[0].y = ini.width_win;
    
    T_Point[1].x = ini.width_win /2;
    T_Point[1].y = 0;

    T_Point[2].x = ini.width_win;
    T_Point[2].y = ini.width_win;

    /* Задаю цвет для рисования */
    XSetForeground(ini.dpy, ini.gc, WHITE);
}


int rand_num(void)
{
    struct timespec time_rand;

    clock_gettime(CLOCK_REALTIME, &time_rand);

    srand(time_rand.tv_nsec);

    int i = (rand() % NUM_POINT);

    return i;
}





void draw(void)
{
    int rand_point;   /* Одна из трёх точек выбирается рандомно */
    struct point previos_point = T_Point[1];   /* Вчерашняя точка */

    /* Текущая точка середина отрезка между previos_poin и rand_point  */
    struct point curr_point;

     while((point_counter) < TARGET_POINT)
     {
        rand_point = rand_num();

        /*нахожу точку */
        curr_point.x = (T_Point[rand_point].x + previos_point.x) / 2; 	
        curr_point.y = (T_Point[rand_point].y + previos_point.y) / 2;

        XDrawPoint(ini.dpy, ini.win, ini.gc, curr_point.x, curr_point.y);

        point_counter++;

	previos_point = curr_point;

        XFlush(ini.dpy);

     }

    end_time();   
    printf("%d точек\n", point_counter);



}
