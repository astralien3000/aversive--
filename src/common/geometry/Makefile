BUILD=../$(BUILD_EXPORT)
INCLUDE=../$(INCLUDE_EXPORT)

SUB_DIRS= # add the sub directory's names here

OBJS = point_collision segment_collision circle_collision aabb_collision triangle_collision quadrilateral_collision # add object to compile

all: $(BUILD) $(BUILD) build

# to build local sources
build: $(addprefix $(BUILD)/,$(addsuffix .o,$(OBJS)))

$(BUILD):
	mkdir $@

$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<