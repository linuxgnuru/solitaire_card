PROGNAME = bathsol
CC = g++
DEBUG = -O2 -ggdb
CFLAGS = $(DEBUG) -Wall -std=c++11
SRC = main.cpp cards.cpp random.cpp deck.cpp
OBJ = $(SRC:.cpp=.o)

ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

all: clean $(PROGNAME)

$(PROGNAME): $(OBJ)
	@$(CC) -o $@ $(OBJ) $(LIBS)

.cpp.o:
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(PROGNAME)

install: $(PROGNAME)
	sudo install -d $(PREFIX)/bin/
	sudo install -m 755 $(PROGNAME) $(PREFIX)/bin/
	sudo install -d $(PREFIX)/man/man6/
	sudo install -g 0 -o 0 -m 0644 $(PROGNAME).6 $(PREFIX)/man/man6/
	sudo gzip $(PREFIX)/man/man6/$(PROGNAME).6
