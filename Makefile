.PHONY: all atmega32 atmega128 atmega2560 stm32f4 doc clean mrproper

all: sasiae atmega32 atmega128 atmega2560 stm32f4

ifeq ($(VERBOSE),1)
_VERBOSE=VERBOSE=1
else
_VERBOSE=-s
endif

sasiae:
	@(mkdir -p build/sasiae/ && cd build/sasiae/ && cmake -DCMAKE_TOOLCHAIN_FILE=../../cmake/toolchain/simul/sasiae.cmake ../../ && $(MAKE) $(_VERBOSE))

atmega32:
	@(mkdir -p build/atmega32/ && cd build/atmega32/ && cmake -DCMAKE_TOOLCHAIN_FILE=../../cmake/toolchain/avr/atmega32.cmake ../../ && $(MAKE) $(_VERBOSE))

atmega128:
	@(mkdir -p build/atmega128/ && cd build/atmega128/ && cmake -DCMAKE_TOOLCHAIN_FILE=../../cmake/toolchain/avr/atmega128.cmake ../../ && $(MAKE) $(_VERBOSE))

atmega2560:
	@(mkdir -p build/atmega2560/ && cd build/atmega2560/ && cmake -DCMAKE_TOOLCHAIN_FILE=../../cmake/toolchain/avr/atmega2560.cmake ../../ && $(MAKE) $(_VERBOSE))

stm32f4:
	@(mkdir -p build/stm32f4/ && cd build/stm32f4/ && cmake -DCMAKE_TOOLCHAIN_FILE=../../cmake/toolchain/arm/stm32f4.cmake ../../ && $(MAKE) $(_VERBOSE))

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
