CC=g++
CPPFLAGS=-O3
LDFLAGS=-lpthread
DEBUG =-Wall -Wextra -Werror -pedantic
PROGNAME=headers

$(PROGNAME): main.o
	$(CC) -o $(PROGNAME) main.o $(CPPFLAGS) $(LDFLAGS)

strip:
	strip -S --strip-unneeded --remove-section=.note.gnu.gold-version --remove-section=.comment --remove-section=.note --remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag $(PROGNAME)


.PHONY: clean
clean:
	rm $(PROGNAME) *.o *.out
