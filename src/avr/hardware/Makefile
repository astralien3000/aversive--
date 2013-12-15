BUILD=../$(BUILD_EXPORT)
INCLUDE=../$(INCLUDE_EXPORT)

LIB=$(BUILD)/libaversive_$(MMCU).a
SUB_DIRS=  # add the sub directory's names here

OBJS= timer uart

all: build $(SUB_DIRS) $(LIB)

build: $(addprefix $(BUILD)/,$(addsuffix .o,$(OBJS)))

$(BUILD)/%.o: %.cpp $(INCLUDE)/hardware/%.hpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

$(SUB_DIRS):
	$(MAKE) -C $@

$(LIB): $(addprefix $(BUILD)/,$(addsuffix .o,$(OBJS)))
	ar cr $(LIB) $?
