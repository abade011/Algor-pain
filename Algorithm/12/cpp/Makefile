include ../../cpp.mk

NodeTest: CPPFLAGS += -I ../../11/cpp
NodeTest: ../../11/cpp/Node.o ../../11/cpp/NodeTest.o LengthNodeTest.o RemoveNodeTest.o ReverseNodeTest.o 
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

test: NodeTest
	./NodeTest

all: NodeTest

.PHONY: test all
