CC = g++ -std=c++11
CFLAGS = -Wall -Werror -Wmissing-prototypes
OBJS = server.o rio.o

new_main.o : player.o board.o  

clean:
    rm -f *~ *.o sysstatd