all: sasiae avr

sasiae avr:
	@$(MAKE) -sC src/$@

clean:
	@rm -f $(shell find . -name "*~" -o -name "#*#" -o -name "*.o")

newhpp:
	@./script/newhpp.sh

exporthpp:
	@./script/exporthpp.sh

mrproper: clean
	@rm -rf build/avr/* build/sasiae/*

clean_doc: 
	@rm -rf doc_build/*