sources := $(wildcard src/*.c)
objects := $(sources:.c=.o)
depends := $(sources:.c=.d)

CFLAGS := -g -O2 -MD -Wall -Wextra -Werror -std=c11 ${CFLAGS}

all : ${objects} \
	src/test_llist

src/test_llist.o : src/llist.o
src/test_llist : LDLIBS := ${LDLIBS} src/llist.o

clean :
	$(RM)  ${depends} ${objects}

-include ${depends}
