
CFLAGS=-g



all :test_lexeur test_node test_orthographe

test_orthographe :  lexem.o Dictionnaire.o  Analyse_lexical.o test_orthographe.o
	g++  -o $@ $^ $(LDFLAGS)

test_node :  node.o Dictionnaire.o test_node.o
	#g++ -o test_node -g $^ $(LDFLAGS)
	g++ -o $@    $^ $(LDFLAGS)

test_lexeur :  lexeur.o  Dictionnaire.o Analyse_lexical.o test_lexeur.o
	g++ -o $@  $^ $(LDFLAGS)

%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS)


clean:
	rm -f *.o *~ test_lexeur test_node test_orthographe 

