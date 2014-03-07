BUILD=../../$(BUILD_EXPORT)
INCLUDE=../../$(INCLUDE_EXPORT)

SUB_DIRS= # add the sub directory's names here

OBJS= eeprom_stream

.PHONY: $(SUB_DIRS)

all: build $(SUB_DIRS)

build: $(addprefix $(BUILD)/,$(addsuffix .o,$(OBJS)))

$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

$(SUB_DIRS):
	$(MAKE) -C $@
