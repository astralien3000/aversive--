all: sasiae avr

sasiae avr:
	@$(MAKE) -sC src/$@

doc: Doxyfile
	@doxygen

archiparser:
	@$(MAKE) -sC tools/archi_parser

clean:
	@rm -f $(shell find . -name "*~" -o -name "#*#" -o -name "*.o")

newhpp:
	@./script/newhpp.sh

exporthpp:
	@./script/exporthpp.sh

mrproper: clean clean_doc clean_archiparser
	@rm -rf build/avr/* build/sasiae/*

clean_doc: 
	@rm -rf build/doc/*

clean_archiparser:
	@$(MAKE) clean -sC tools/archi_parser
