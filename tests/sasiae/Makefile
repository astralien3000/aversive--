SUBDIRS=client_thread device scheduler sync servo rds gp2

ALL_RULES=$(addsuffix _all,$(SUBDIRS))
TEST_RULES=$(addsuffix _test,$(SUBDIRS))
CLEAN_RULES=$(addsuffix _clean,$(SUBDIRS))
MRPROPER_RULES=$(addsuffix _mrproper,$(SUBDIRS))

.PHONY: $(SUBDIRS)

all: $(ALL_RULES)

test: $(TEST_RULES)

clean: $(CLEAN_RULES)

mrproper: $(MRPROPER_RULES)

$(ALL_RULES):
	make all -C $(@:_all=)

$(TEST_RULES):
	make test -C $(@:_test=)

$(CLEAN_RULES):
	make clean -C $(@:_clean=)

$(MRPROPER_RULES):
	make mrproper -C $(@:_mrproper=)
