sources := $(wildcard src/*.c)
objects := $(sources:.c=.o)
depends := $(sources:.c=.d)

CFLAGS := -g -O2 -MD -Wall -Wextra -Werror -std=c11 ${CFLAGS}

all : ${objects}

src/test_llist.o : src/llist.o
src/test_llist : LDLIBS := ${LDLIBS} src/llist.o

src/test_tree.o : src/tree.o
src/test_tree : LDLIBS := ${LDLIBS} src/tree.o

src/test_treap.o : src/treap.o
src/test_treap : LDLIBS := ${LDLIBS} src/treap.o src/tree.o

-include ${depends}

check : \
	src/test_llist  \
	src/test_treap  \
	src/test_tree   \
# keep
	src/test_llist
	src/test_treap
	src/test_tree

clean :
	$(RM)  ${depends} ${objects}

.PHONY : all check clean
