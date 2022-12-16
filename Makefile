CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c2x -O2 
LIBS=

INSTALL_PATH=/usr/bin/

TARGET=ecc
CACHE=.cache
OUTPUT=$(CACHE)/release


MODULES += main.o
MODULES += compiler.o
MODULES += cprocess.o
MODULES += buffer.o
MODULES += vector.o

TEST += test.o


OBJ=$(addprefix $(CACHE)/,$(MODULES))
T_OBJ=$(addprefix $(CACHE)/,$(TEST))


$(CACHE)/%.o:
	$(CC) $(CFLAGS) -c $< -o $@


all: env $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(OUTPUT)/$(TARGET)

exec: all
	$(OUTPUT)/$(TARGET)

-include dep.list


.PHONY: env dep clean install


dep:
	$(CC) -MM src/*.c app/*.c test/*.c | sed 's|[a-zA-Z0-9_-]*\.o|$(CACHE)/&|' > dep.list


test: env $(T_OBJ)
	$(CC) $(CFLAGS) $(T_OBJ) $(LIBS) -o $(OUTPUT)/test
	$(OUTPUT)/test


install:
	cp -v $(OUTPUT)/$(TARGET) $(INSTALL_PATH)/$(TARGET)


env:
	mkdir -pv $(CACHE)
	mkdir -pv $(OUTPUT)


clean: 
	rm -rvf $(CACHE)



