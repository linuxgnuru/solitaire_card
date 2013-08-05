all: bs

bs: main.o cards.o random.o Deck.o

main.o: main.cpp
  g++ -c main.cpp

cards.o: cards.cpp
	g++ -c cards.cpp

random.o: random.cpp
	g++ -c random.cpp
Deck.o: Deck.cpp
	g++ -c Deck.cpp
clean:
	rm -rf *o bs
#g++ -o bs main.cpp cards.o random.o Deck.o
