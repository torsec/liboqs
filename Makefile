ROOT 				?= $(CURDIR)
LIBOQS_ROOT 		?= $(ROOT)/build

.PHONY: all
all: build

.PHONY: build
build:
	$(MAKE) -C $(LIBOQS_ROOT) \
	PLATFORM=$(PLATFORM) \
	CROSS_COMPILE=$(CROSS_COMPILE) \
	TA_DEV_KIT_DIR=$(TA_DEV_KIT_DIR)

.PHONY: install
install:
	mkdir -p $(TA_DEV_KIT_DIR)/lib
	cp $(LIBOQS_ROOT)/lib/liboqs.a $(TA_DEV_KIT_DIR)/lib/. && \
	mkdir -p $(TA_DEV_KIT_DIR)/include/oqs && \
	cp $(LIBOQS_ROOT)/include/oqs/* $(TA_DEV_KIT_DIR)/include/oqs/.

.PHONY: clean
clean:
	rm -rf build

.PHONY: uninstall
uninstall:
	rm -r $(TA_DEV_KIT_DIR)/include/oqs; \
	rm $(TA_DEV_KIT_DIR)/lib/liboqs.a;