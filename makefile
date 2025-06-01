CC:=gcc
EXEC:=simplifyFunction
OBJECTS:=main.o linked.o k_map_attr.o parse_function.o find_bits.o gen_func.o
SOURCES:=main.c $(shell ls lib/*)
INC:= -I inc/
CFLAGS:= 
DEBUG:=
RM:=rm -f


all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $^ -o $@

main.o: $(SOURCES)
	$(CC) $(INC) $(CFLAGS) -c $^ $(DEBUG)

%.o: lib/%.c
	$(CC) $(INC) $(CFLAGS) -c $^ $(DEBUG)
.PHONY: clean

clean:
	$(RM) $(EXEC) $(OBJECTS)
