#include "include/templates.h"

const char MAIN[] =
    "#include <stdio.h>\n"
    "\n"
    "int main(int argc, char const *argv[])\n"
    "{\n"
    "\tprintf(\"Hello, World!\\n\");\n"
    "}\n";

const char MAKE[] =
    "CC = gcc\n"
    "SRC = src\n"
    "SRCS = $(wildcard $(SRC)/*.c)\n"
    "OBJ = obj\n"
    "OBJS = $(patsubst $(SRC)/%%.c, $(OBJ)/%%.o, $(SRCS))\n"
    "DFLAGS = -g3 -Wall\n"
    "FLAGS = -O3 -Wall\n"
    "LFLAGS = -O3 -static\n"
    "BINDIR = bin\n"
    "BIN = $(BINDIR)/%s\n" /*Insert name*/
    "\n"
    "ifeq ($(OS),Windows_NT)\n"
    "RM = del /Q /F\n"
    "CP = copy /Y\n"
    "ifdef ComSpec\n"
    "SHELL := $(ComSpec)\n"
    "endif\n"
    "ifdef COMSPEC\n"
    "SHELL := $(COMSPEC)\n"
    "endif\n"
    "else\n"
    "RM = rm -rf\n"
    "CP = cp -f\n"
    "endif\n"
    "\n"
    "all: $(BIN)\n"
    "\n"
    "$(BIN): $(OBJS)\n"
    "	$(CC) $(OBJS) $(FLAGS) $(LFLAGS) -o $@\n"
    "\n"
    "$(OBJ)/%%.o: $(SRC)/%%.c\n"
    "	$(CC) $(FLAGS) -c $< -o $@\n"
    "\n"
    ".PHONY : clean run\n"
    "\n"
    "ifeq ($(OS),Windows_NT)\n"
    "OBJS := $(subst /,\\, $(OBJS))\n"
    "BIN := $(subst /,\\, $(BIN))\n"
    "endif\n"
    "clean:\n"
    "	$(RM) $(BIN).* $(OBJS)\n"
    "\n"
    "run: all\n"
	"   $(BIN)\n"
    ;