serp : ./obj/main.o   \
       ./obj/init.o   \
       ./obj/bye.o    \
       ./obj/event.o  \
       ./obj/draw.o   \
       ./obj/time.o
	gcc -o serp   \
       ./obj/main.o   \
	./obj/init.o  \
	./obj/bye.o   \
	./obj/event.o \
	./obj/draw.o  \
	./obj/time.o  \
	-s -lX11


./obj/main.o : main.c
	gcc -c main.c -o ./obj/main.o

./obj/init.o : init.c
	gcc -c init.c -o ./obj/init.o

./obj/bye.o : bye.c
	gcc -c bye.c -o ./obj/bye.o

./obj/event.o : event.c
	gcc -c event.c -o ./obj/event.o

./obj/draw.o : draw.c
	gcc -c draw.c -o ./obj/draw.o

./obj/time.o : time.c
	gcc -c time.c -o ./obj/time.o
