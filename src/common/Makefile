BUILD=$(BUILD_EXPORT)
INCLUDE=$(INCLUDE_EXPORT)

SUB_DIRS= filter device geometry # add the sub directory's names here

OBJS = # add object to compile

.PHONY: $(SUB_DIRS) all build

all: $(BUILD) build $(SUB_DIRS)

# to build local sources
build: $(addprefix $(BUILD)/,$(addsuffix .o,$(OBJS)))

$(SUB_DIRS):
	$(MAKE) -C $(@:.d=)

$(BUILD):
	mkdir $(BUILD)

$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<