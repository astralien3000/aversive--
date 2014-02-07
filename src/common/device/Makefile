BUILD=../$(BUILD_EXPORT)
INCLUDE=../$(INCLUDE_EXPORT)

#export BUILD_EXPORT=$(BUILD)
#export INCLUDE_EXPORT=$(INCLUDE)

SUB_DIRS= stream # add the sub directory's names here

OBJS = # add object to compile

.PHONY: $(SUB_DIRS) all build

all: $(BUILD) build $(SUB_DIRS)

# to build local sources
build: $(addprefix $(BUILD)/,$(addsuffix .o,$(OBJS)))

$(SUB_DIRS):
	INCLUDE_EXPORT=$(INCLUDE) BUILD_EXPORT=$(BUILD) $(MAKE) -C $(@:.d=)

$(BUILD):
	mkdir $(BUILD)

$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<