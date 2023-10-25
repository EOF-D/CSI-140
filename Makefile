CFILES = $(wildcard ${SRC}/*.cpp)
OBJFILES = $(CFILES:.cpp=.o)

CC = g++
OUT = output

$(OUT): $(OBJFILES)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o $@ $^

clean:
	find . -path "*/*.o"  -delete
	rm -rf "output"
