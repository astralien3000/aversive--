.PHONY: all generate doc test clean update mrproper

all: mk/all.mk
	$(MAKE) -f mk/all.mk all_targets

update: clean_mk
	./tools/compilation/generate_files_pro.sh common > project/generated/common.files.pro
	./tools/compilation/generate_files_pro.sh avr > project/generated/avr.files.pro
	./tools/compilation/generate_files_pro.sh sasiae > project/generated/sasiae.files.pro
	./tools/compilation/generate_files_pro.sh stm32 > project/generated/stm32.files.pro

mk/all.mk:
	./tools/compilation/generate_all_mk.sh > mk/all.mk

doc:
	mkdir -p build/doc
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

todo:
	@grep --color=auto -nr todo include/ src/

mrproper: clean clean_archiparser clean_test clean_mk
	@rm -rf build/*

clean_mk:
	@rm -rf mk/*

clean_doc:
	@rm -rf build/doc/*

clean_archiparser:
	@$(MAKE) clean -sC tools/archi_parser

clean_test:
	@$(MAKE) mrproper -sC tests/sasiae

test:
	$(MAKE) test -C tests/sasiae
