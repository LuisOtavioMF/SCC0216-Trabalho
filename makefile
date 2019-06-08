DIR := ${CURDIR}
SRC = $(wildcard */*.c) $(wildcard *.c)
FLAGS = -Wall -Ihdr
OBJDIR = $(DIR)/.makeobjects
ERRDIR = $(DIR)/.errors
OBJECTS = $(shell find $(OBJDIR) -name '*.o')
TARGET = RecomendacaoFilmes

.PHONY: makedir $(TARGET)

all: makedir $(TARGET)

makedir:
	if [ -d $(OBJDIR) ]; then rm -dr $(OBJDIR); fi
	if [ -d $(ERRDIR) ]; then rm -dr $(ERRDIR); fi
	mkdir $(OBJDIR)
	mkdir $(ERRDIR)

$(TARGET): $(SRC:.c=.o)
	gcc -o $(TARGET) $(OBJECTS) $(FLAGS)

.c.o:
	gcc -c -o $(DIR)/.makeobjects/$(notdir $@) $^ $(FLAGS) 2> $(ERRDIR)/$(notdir $(@:.o=.err))

clean:
	rm -rf $(TARGET)
	rm -dr $(OBJDIR)
	rm -dr $(ERRDIR)
