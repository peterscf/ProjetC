CFLAGS=-g

all :

test_syntaxe :  lexem.o Dictionnaire.o  lexical_funct.o test_syntaxe.o
	g++ -o test_syntaxe $^ $(LDFLAGS)

test_node :  node.o Dictionnaire.o test_node.o
	#g++ -o test_node -g $^ $(LDFLAGS)
	g++ -o $@ -g $^ $(LDFLAGS)

test_lexeur :  lexeur.o test_lexeur.o
	g++ -o $@ -g $^ $(LDFLAGS)

%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS)


clean:
	rm -f *.o *~

