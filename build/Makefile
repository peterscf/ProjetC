
CFLAGS= -WALL -g

all : test

test : test.o
	g++ -o lexeur $^ $(LDFLAGS)


%.o:%.cc
	g++ $(CFLAGS) -c -g $^

clean:
	rm -f *.o *~ test test1
