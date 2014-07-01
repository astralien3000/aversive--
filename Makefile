.PHONY: all generate doc test clean sasiae atmega128 atmega2560

all: mk/all.mk
	$(MAKE) -f all.mk all_targets

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
	@./script/newhpp.sh

exporthpp:
	@./script/exporthpp.sh

todo:
	@grep --color=auto -nr todo include/ src/

mrproper: clean clean_archiparser clean_test
	@rm -rf build/*

clean_doc:
	@rm -rf build/doc/*

clean_archiparser:
	@$(MAKE) clean -sC tools/archi_parser

clean_test:
	@$(MAKE) mrproper -sC tests/sasiae

test:
	$(MAKE) test -C tests/sasiae
