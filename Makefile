all: sasiae avr

sasiae avr:
	@$(MAKE) -sC src/$@

doc: Doxyfile
	@doxygen

clean:
	@rm -f $(shell find . -name "*~" -o -name "#*#" -o -name "*.o")

newhpp:
	@./script/newhpp.sh

exporthpp:
	@./script/exporthpp.sh

mrproper: clean clean_doc
	@rm -rf build/avr/* build/sasiae/*

clean_doc: 
	@rm -rf build/doc/*