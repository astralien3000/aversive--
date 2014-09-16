.PHONY: all generate doc clean update mrproper

all: mk/all.mk
	$(MAKE) -f mk/all.mk all_targets

sasiae: mk/all.mk
	$(MAKE) -f mk/sasiae.mk

atmega32: mk/all.mk
	$(MAKE) -f mk/atmega32.mk

atmega128: mk/all.mk
	$(MAKE) -f mk/atmega128.mk

atmega2560: mk/all.mk
	$(MAKE) -f mk/atmega2560.mk

stm32: mk/all.mk
	$(MAKE) -f mk/stm32.mk

update: clean_mk
	tools/compilation/generate_files_pro.sh common > project/generated/common.files.pro
	tools/compilation/generate_files_pro.sh avr > project/generated/avr.files.pro
	tools/compilation/generate_files_pro.sh sasiae > project/generated/sasiae.files.pro
	tools/compilation/generate_files_pro.sh stm32 > project/generated/stm32.files.pro

architecture: archiparser
	cat architecture/atmega128.archi | tools/archi_parser/build/archiparser > include/avr/hardware/part/atmega128.hpp
	cat architecture/atmega2560.archi | tools/archi_parser/build/archiparser > include/avr/hardware/part/atmega2560.hpp
	cat architecture/atmega32.archi | tools/archi_parser/build/archiparser > include/avr/hardware/part/atmega32.hpp
	tools/license_header/license_header.sh tools/license_header/license.txt include/avr/hardware/part/atmega128.hpp
	tools/license_header/license_header.sh tools/license_header/license.txt include/avr/hardware/part/atmega2560.hpp
	tools/license_header/license_header.sh tools/license_header/license.txt include/avr/hardware/part/atmega32.hpp

mk/all.mk: update
	./tools/compilation/generate_all_mk.sh > mk/all.mk

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

clean_mk:
	@rm -rf mk/*

clean_generated:
	@rm -rf project/generated/*

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
