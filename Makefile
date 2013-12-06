all:

clean:
	@rm -f $(shell find . -name "*~") $(shell find . -name "#*#") $(shell find build -name "*.o")

mrproper: clean
	@rm -rf build