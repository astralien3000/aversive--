.PHONY: all doc test clean sasiae atmega128 atmega2560

all: sasiae atmega128 atmega2560

atmega128: export MMCU=atmega128
atmega128:
	$(MAKE) -C src/avr

atmega2560: export MMCU=atmega2560
atmega2560:
	$(MAKE) -C src/avr

sasiae:
	$(MAKE) -C src/sasiae

doc:
	mkdir -p build/doc
	@doxygen 1> /dev/null

archiparser:
	@$(MAKE) -sC tools/archi_parser

clean:
	@rm -f $(shell find . -name "*~" -o -name "#*#" -o -name "*.o")

newhpp:
	@./script/newhpp.sh

exporthpp:
	@./script/exporthpp.sh

mrproper: clean clean_archiparser clean_test
	@rm -rf build/*

clean_doc: 
	@rm -rf build/doc/*

clean_archiparser:
	@$(MAKE) clean -sC tools/archi_parser

clean_test:
	@$(MAKE) clean -sC tests/sasiae

test:
	$(MAKE) test -C tests/sasiae
