sources := $(wildcard src/*.c)
objects := $(sources:.c=.o)
depends := $(sources:.c=.d)

CFLAGS :=         \
	-MD 	  \
	-O2 	  \
	-Wall     \
	-Wbad-function-cast \
	-Wcast-align \
	-Wconversion \
	-Werror   \
	-Wextra   \
	-Wfloat-equal \
	-Wformat \
	-Wformat-security \
	-Wpedantic \
	-Wshadow \
	-Wswitch-default \
	-Wswitch-enum \
	-Wtraditional-conversion \
	-Wwrite-strings \
	-Waggregate-return \
	-Wlogical-op \
	-Wpacked \
	-Wpadded \
	-g 	  \
	-std=c11  \
	${CFLAGS}


all : ${objects}

src/test_llist.o : src/llist.o
src/test_llist : LDLIBS := ${LDLIBS} src/llist.o

src/test_bst.o : src/bst.o
src/test_bst : LDLIBS := ${LDLIBS} src/bst.o

src/test_treap.o : src/treap.o
src/test_treap : LDLIBS := ${LDLIBS} src/treap.o src/bst.o

-include ${depends}

check : \
	src/test_bst   \
	src/test_llist  \
	src/test_treap  \
# keep
	src/test_bst
	src/test_llist
	src/test_treap

clean :
	$(RM)  ${depends} ${objects}

.PHONY : all check clean
