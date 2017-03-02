include ../../cpp.mk

LDLIBS += -lm

all: NodeTest CycleTest

NodeTest: CPPFLAGS += -I ../../11/cpp -I ../../12/cpp
NodeTest: ../../11/cpp/Node.o ../../11/cpp/NodeTest.o ../../12/cpp/LengthNodeTest.o ../../12/cpp/RemoveNodeTest.o ../../12/cpp/ReverseNodeTest.o Timing12Test.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

CycleTest: CPPFLAGS += -I ../../11/cpp -I ../../12/cpp
CycleTest: ../../11/cpp/Node.o CycleDetection.o CycleTest.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

test: NodeTest CycleTest
	./NodeTest; ./CycleTest

.PHONY: test all
