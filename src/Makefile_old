CFLAGS=-g

all : test_syntaxe

test_syntaxe :  lexem.o Dictionnaire.o  lexical_funct.o test_syntaxe.o
	g++ -o test_syntaxe $^ $(LDFLAGS)
 

%.o:%.cc
	g++ $(CFLAGS) -c -g $^

clean:
	rm -f *.o *~ test_syntaxe test_syntaxe

