sources := $(wildcard src/*.c)
objects := $(sources:.c=.o)
depends := $(sources:.c=.d)

CFLAGS := -g -O2 -MD -Wall -Wextra -Werror -std=c11 ${CFLAGS}

all : ${objects}

clean :
	$(RM)  ${depends} ${objects}

-include ${depends}
