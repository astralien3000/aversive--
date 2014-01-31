SUBDIRS=client_thread device scheduler

.PHONY: $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	make test -C $@