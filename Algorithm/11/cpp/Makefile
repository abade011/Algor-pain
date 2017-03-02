include ../../cpp.mk

NodeTest: Node.o NodeTest.o BasicNodeTest.o ExtendedNodeTest.o

test: NodeTest
	./NodeTest

test1: NodeTest
	./NodeTest Basic

test2: NodeTest
	./NodeTest Extended

all: NodeTest

.PHONY: test test1 test2 all
