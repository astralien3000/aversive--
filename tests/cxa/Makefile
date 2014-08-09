########################################
# Rules
all:
	@echo "Usage :"
	@echo "\t- make sasiae: Compile your project for sasiae"
	@echo "\t- make atmegaX: Compile your project for atmegaX (X may be 16, 32, 128 or 2560)"
	@echo "\t- make clean: Remove all temporary files"
	@echo "\t- make mrproper: Remove all temporary files + the binary files"

sasiae:
	make -f withcxa.make sasiae
	make -f withoutcxa.make sasiae

atmega128:
	make -f withcxa.make atmega128
	make -f withoutcxa.make atmega128

atmega2560:
	make -f withcxa.make atmega2560
	make -f withoutcxa.make atmega2560

clean:
	make -f withcxa.make clean
	make -f withoutcxa.make clean

mrproper:
	make -f withcxa.make mrproper
	make -f withoutcxa.make mrproper
