BUILD_DIR=build
EXE=archiparser

CC=gcc
CFLAGS=-Wall -std=c99
CLIBS=-ll

all: $(BUILD_DIR) $(BUILD_DIR)/$(EXE)

clean:
	rm -rf $(BUILD_DIR)/*

$(BUILD_DIR): 
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/$(EXE): $(BUILD_DIR)/y.tab.o $(BUILD_DIR)/lex.yy.o
	$(CC) $(CFLAGS) $^ $(CLIBS) -o $@

$(BUILD_DIR)/%.o : $(BUILD_DIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD_DIR)/y.tab.c:
	yacc -d -o $@ archi.y

$(BUILD_DIR)/lex.yy.c:
	flex -o $@ archi.l
