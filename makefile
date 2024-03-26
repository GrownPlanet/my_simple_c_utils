CC = clang

TARGET = main

SRCDIR = sourcefiles
INCDIR = headerfiles
BINDIR = bin
SOURCES = $(SRCDIR)/* main.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = $(BINDIR)/$(TARGET)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -I$(INCDIR) $^ -o $@
	@echo "----------------- done compiling -----------------"
	@mv *.o $(BINDIR)
