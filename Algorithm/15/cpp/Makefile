include ../../cpp.mk

LDLIBS += -lm

BinarySearchTest: BinarySearch.o BinarySearchTest.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

test: BinarySearchTest
	./BinarySearchTest

ListVisualiser: CPPFLAGS += -I ../../11/cpp
ListVisualiser: ListVisualiser.o ../../11/cpp/Node.o ListVisualiserDriver.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

.PHONY: test
