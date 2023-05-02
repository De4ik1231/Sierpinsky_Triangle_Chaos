/* Треугольник серпинского методом хаоса c Xlib */
/* Цель сравнить c OPENGL время выполнения фрактала Серпинского из 5000 точек,
 * без учёта инициализации, (только цикл). */
/* Отрисовка и отсчёт времени начанается с нажатия SPACE */
/* Конец отсёта в функции draw после отрисовки нужного количества точек */


#include <time.h> /* nanosleep */
#include "init.h"

#define  N_SLEEP   1000000   /* 0.001 секунды */

/* Определение функций */
void init(void); /* init.c */
void bye(char* str); /* bye.c */
int check_event(void); /* event.c */
void init_draw(void);  /* draw.c */

int main(void)
{
    struct timespec t_sleep ={0, N_SLEEP}; /* для nanosleep */	
    int play = 1;

    init();
    init_draw();

    while(play)
    {
       play = check_event();

       nanosleep(&t_sleep, NULL);
    }


    bye("Успешное завершение.");

    return 0;
}
