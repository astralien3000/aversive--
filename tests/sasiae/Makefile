SUBDIRS=client_thread device scheduler sync

.PHONY: $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	make test -C $@
