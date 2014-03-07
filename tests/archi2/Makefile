BUILD_DIR=build
EXE=archiparser

OBJS=uc_node struct_node hardware_node register_node parent_node child_node config_node sub_register_nod

CC=g++
INCLUDE_DIRS=.
CFLAGS=$(addprefix -I,$(INCLUDE_DIRS)) -Wall -std=c++11
CLIBS=-ll

OBJECT_FILES=$(addprefix $(BUILD_DIR)/, $(addsuffix .o,$(OBJS)))

all: $(BUILD_DIR) $(BUILD_DIR)/$(EXE)

clean:
	rm -rf $(BUILD_DIR)/*

$(BUILD_DIR): 
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/$(EXE): $(BUILD_DIR)/y.tab.o $(BUILD_DIR)/lex.yy.o $(OBJECT_FILES)
	$(CC) $(CFLAGS) $^ $(CLIBS) -o $@

$(BUILD_DIR)/y.tab.o : $(BUILD_DIR)/y.tab.c
$(BUILD_DIR)/lex.yy.o : $(BUILD_DIR)/lex.yy.c
$(BUILD_DIR)/%.o : %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD_DIR)/y.tab.c:
	yacc -d -o $@ archi.y

$(BUILD_DIR)/lex.yy.c:
	flex -o $@ archi.lex
