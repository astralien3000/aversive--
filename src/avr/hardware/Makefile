BUILD=../$(BUILD_EXPORT)
INCLUDE=../$(INCLUDE_EXPORT)

LIB=$(BUILD)/libaversive_$(MMCU).a
SUB_DIRS=  # add the sub directory's names here

OBJS= timer uart

all: build $(SUB_DIRS) $(LIB)

build: $(addprefix $(BUILD)/$(MMCU)/,$(addsuffix .o,$(OBJS)))

$(BUILD)/$(MMCU)/%.o: %.cpp $(INCLUDE)/hardware/%.hpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

$(SUB_DIRS):
	$(MAKE) -C $@

$(LIB): $(addprefix $(BUILD)/$(MMCU)/,$(addsuffix .o,$(OBJS)))
	ar cr $(LIB) $?
