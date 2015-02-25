.PHONY: all generate doc clean update mrproper

DISTRIB_INFO=./tools/distrib/distrib_toolchain_info.sh
BUILD_DIR=./build

all: 
	@${MAKE} atmega2560
	@${MAKE} atmega128
	@${MAKE} atmega32
	@${MAKE} sasiae

compile: DISTRIB_FILE=distrib/$(DISTRIB).distrib
compile: INCLUDE_FLAGS=$(addprefix -I,$(shell $(DISTRIB_INFO) $(DISTRIB_FILE) include))
compile: OBJECTS_BUILD_DIR=$(BUILD_DIR)/$(DISTRIB)_$(TARGET)
# CXX
compile: CXX=$(shell $(DISTRIB_INFO) $(DISTRIB_FILE) cxx)
compile: CXXFLAGS=$(shell $(DISTRIB_INFO) $(DISTRIB_FILE) cxxflags | sed s/TARGET/$(TARGET)/g)
compile: CXXSOURCES=$(shell $(DISTRIB_INFO) $(DISTRIB_FILE) cxxsources)
compile: CXXSOURCES_NOTDIR=$(notdir $(CXXSOURCES))
compile: CXXOBJECTS=$(addprefix $(OBJECTS_BUILD_DIR)/,$(CXXSOURCES_NOTDIR:%.cpp=%_cpp.o))
compile: CXX_RULES_BEGIN=$(addsuffix ":",$(CXXOBJECTS))
compile: CXX_RULES=$(join $(CXX_RULES_BEGIN),$(CXXSOURCES))
compile: CXX_RULE_CMD='\t$(CXX) -c $(CXXFLAGS) $(INCLUDE_FLAGS) $$< -o $$@\n'
compile: CXX_RULES_CMD=$(addsuffix $(CXX_RULE_CMD),$(foreach i,$(CXX_RULES),"$(i)\n"))
# C
compile: CC=$(shell $(DISTRIB_INFO) $(DISTRIB_FILE) cc)
compile: CFLAGS=$(shell $(DISTRIB_INFO) $(DISTRIB_FILE) cflags | sed s/TARGET/$(TARGET)/g)
compile: CSOURCES=$(shell $(DISTRIB_INFO) $(DISTRIB_FILE) csources)
compile: CSOURCES_NOTDIR=$(notdir $(CSOURCES))
compile: COBJECTS=$(addprefix $(OBJECTS_BUILD_DIR)/,$(CSOURCES_NOTDIR:%.c=%_c.o))
compile: C_RULES_BEGIN=$(addsuffix ":",$(COBJECTS))
compile: C_RULES=$(join $(C_RULES_BEGIN),$(CSOURCES))
compile: C_RULE_CMD='\t$(CC) -c $(CFLAGS) $(INCLUDE_FLAGS) $$< -o $$@\n'
compile: C_RULES_CMD=$(addsuffix $(C_RULE_CMD),$(foreach i,$(C_RULES),"$(i)\n"))
# Archive
compile: AR=$(shell $(DISTRIB_INFO) $(DISTRIB_FILE) ar)
compile: AR_OBJECTS=$(COBJECTS) $(CXXOBJECTS)
compile: AR_TARGET=$(BUILD_DIR)/aversive_$(DISTRIB)_$(TARGET).a
compile: 
	@mkdir -p $(OBJECTS_BUILD_DIR)
	@echo -e "all: $(AR_TARGET)\n" > $(OBJECTS_BUILD_DIR)/Makefile
	@echo -e "$(AR_TARGET): $(CXXOBJECTS)" > $(OBJECTS_BUILD_DIR)/Makefile
	@echo -e "\t$(AR) r $(AR_TARGET) $(AR_OBJECTS)\n" >> $(OBJECTS_BUILD_DIR)/Makefile
	@echo -en $(CXX_RULES_CMD) >> $(OBJECTS_BUILD_DIR)/Makefile
	@echo -en $(C_RULES_CMD) >> $(OBJECTS_BUILD_DIR)/Makefile
	@${MAKE} -f $(OBJECTS_BUILD_DIR)/Makefile

eirbot2014: DISTRIB=eirbot2014
eirbot2014: compile

atmega32:   TARGET=atmega32
atmega128:  TARGET=atmega128
atmega2560: TARGET=atmega2560
atmega32 atmega128 atmega2560: eirbot2014
atmega32 atmega128 atmega2560:

sasiae: TARGET=x86
sasiae: DISTRIB=sasiae
sasiae: compile

architecture: archiparser
	cat architecture/atmega128.archi | tools/archi_parser/build/archiparser > include/avr/hardware/part/atmega128.hpp
	cat architecture/atmega2560.archi | tools/archi_parser/build/archiparser > include/avr/hardware/part/atmega2560.hpp
	cat architecture/atmega32.archi | tools/archi_parser/build/archiparser > include/avr/hardware/part/atmega32.hpp
	tools/license_header/license_header.sh tools/license_header/license.txt include/avr/hardware/part/atmega128.hpp
	tools/license_header/license_header.sh tools/license_header/license.txt include/avr/hardware/part/atmega2560.hpp
	tools/license_header/license_header.sh tools/license_header/license.txt include/avr/hardware/part/atmega32.hpp

doc:
	@mkdir -p build/doc
	@doxygen 1> /dev/null

archiparser:
	@$(MAKE) -sC tools/archi_parser

clean:
	@rm -f $(shell find . -name "*~" -o -name "#*#" -o -name "*.o" -o -name "*.gch")

newhpp:
	@./tools/script/newhpp.sh

exporthpp:
	@./tools/script/exporthpp.sh

config_symbols:
	@./tools/script/config_symbols.sh

qtcreator:
	@./tools/compilation/configure_qtcreator.sh

todo:
	@grep --color=auto -nr todo include/ src/

mrproper: clean clean_archiparser clean_test clean_mk clean_generated
	@rm -rf build/*

clean_qtcreator:
	@rm -f aversive--.{creator,files,includes,config} aversive--.creator.user*

clean_doc:
	@rm -rf build/doc/*

clean_archiparser:
	@$(MAKE) clean -sC tools/archi_parser

clean_test:
	@(cd tests && ./run_tests.sh clean)

test_all:
	@(cd tests && ./run_tests.sh test)

test_common:
	@(cd tests && ./run_tests.sh common)

test_sasiae:
	@(cd tests && ./run_tests.sh sasiae)

test_avr:
	@(cd tests && ./run_tests.sh avr)

test_stm32:
	@(cd tests && ./run_tests.sh stm32)
