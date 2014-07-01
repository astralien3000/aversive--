
sasiae:
	$(MAKE) -f mk/sasiae.mk


atmega128:
	$(MAKE) -f mk/atmega128.mk


atmega2560:
	$(MAKE) -f mk/atmega2560.mk


atmega32:
	$(MAKE) -f mk/atmega32.mk

all_targets:  sasiae atmega128 atmega2560 atmega32
