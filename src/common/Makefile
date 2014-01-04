BUILD=../../build/common
export BUILD_EXPORT=$(BUILD)
INCLUDE=../../include/common
export INCLUDE_EXPORT=$(INCLUDE)

SUB_DIRS= filter # add the sub directory's names here

OBJS = # add object to compile

all: $(BUILD) build $(addsuffix .d,$(SUB_DIRS))

# to build local sources
build: $(addprefix $(BUILD)/,$(addsuffix .o,$(OBJS)))

filter.d:
	$(MAKE) -C $(@:.d=)

$(BUILD):
	mkdir $(BUILD)

$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<