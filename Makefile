all: sasiae avr

sasiae avr:
	@$(MAKE) -sC src/$@

clean:
	@rm -f $(shell find . -name "*~") $(shell find . -name "#*#") $(shell find build -name "*.o")

newhpp:
	@./script/newhpp.sh

exporthpp:
	@./script/exporthpp.sh

mrproper: clean
	@rm -rf build/avr/* build/sasiae/*
