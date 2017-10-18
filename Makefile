all: lrlistDemo

CFLAGS = -g -O3

lrlistDemo: lrlist.o lrlistDemo.o
	cc -o $@ $^

lrlist.o: lrlist.c lrlist.h
	cc -c $(CFLAGS) lrlist.c

lrlistDemo.o: lrlistDemo.c lrlist.h
	cc -c $(CFLAGS) lrlistDemo.c

clean:
	rm -f *.o lrlistDemo
