include ../../cpp.mk

LDLIBS += -lm

DynamicArrayTest: DynamicArray.o DynamicArrayTest.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

test: DynamicArrayTest
	./DynamicArrayTest

.PHONY: test
