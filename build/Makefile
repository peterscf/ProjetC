
CFLAGS= -WALL -g

all : test

test : test.o alpha.cc alpha.o
	g++ -o test $^ $(LDFLAGS)


%.o:%.cc
	g++ $(CFLAGS) -c -g $^

clean:
	rm -f *.o *~ test test1
