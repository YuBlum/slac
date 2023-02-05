LIBNAME=slac
BUILD=build/
BIN=$(BUILD)lib$(LIBNAME).so
INC=src/
SRCDIRS=src/
LIBS=-lm

CC=cc
FLAGS=-g -Wall -Wextra -fPIC $(foreach D,$(INCDIRS),-I$(D))
CFILES=$(foreach D,$(SRCDIRS),$(wildcard $(D)*.c))

OBJS=$(CFILES:%.c=$(BUILD)%.o)
DEPS=$(OBJS:%.o=%.d)

.SILENT: all $(BIN) install clean
.PHONY: all install clean

all: $(BIN)

$(BIN): $(OBJS)
	@echo Generating $@...
	$(CC) -shared $(FLAGS) -o $(BIN) $^ $(LIBS)

includes:
	mkdir -p /usr/include/$(LIBNAME)
	cp $(INC)*.h /usr/include/$(LIBNAME)/
	@echo Copying the include files to /usr/include/$(LIBNAME)

install: includes all
	cp $(BIN) /usr/lib/
	@echo Copying $(BIN) to /usr/lib/
	@echo $(LIBNAME) installed!

-include $(DEPS)

$(BUILD)%.o: %.c
	mkdir -p build/src
	@echo Generating $@...
	@$(CC) -MMD $(FLAGS) -c $< -o $@

clean:
	@echo Removing binaries...
	rm $(BIN) $(OBJS) $(DEPS)
