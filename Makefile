.PHONY: all doc test clean sasiae avr atmega128 atmega2560

all: sasiae atmega128 atmega2560

atmega128: export MMCU=atmega128
atmega128: avr

atmega2560: export MMCU=atmega2560
atmega2560: avr

sasiae avr:
	$(MAKE) -C src/$@

doc:
	mkdir -p build/doc
	@doxygen

archiparser:
	@$(MAKE) -sC tools/archi_parser

clean:
	@rm -f $(shell find . -name "*~" -o -name "#*#" -o -name "*.o")

newhpp:
	@./script/newhpp.sh

exporthpp:
	@./script/exporthpp.sh

mrproper: clean clean_archiparser
	@rm -rf build/*

clean_doc: 
	@rm -rf build/doc/*

clean_archiparser:
	@$(MAKE) clean -sC tools/archi_parser

test:
	$(MAKE) -C tests/sasiae