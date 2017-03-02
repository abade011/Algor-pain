include ../../java.mk

TESTCLASSFILES = BasicNodeTest.class ExtendedNodeTest.class
CLASSFILES = Node.class $(TESTCLASSFILES)

all: $(CLASSFILES)

clean:
	-rm -f $(CLASSFILES) test.xml

%.class: %.java
	$(JAVAC) $(CP) $(CLASSPATH) $^

test: all
	(((($(JAVA) $(CP) $(CLASSPATH) org.junit.runner.JUnitCore $(subst .class,,$(TESTCLASSFILES)); echo $$? >&3) | egrep -v \(org.junit\|sun.reflect\|java.lang.reflect\) >&4) 3>&1) | (read xs; exit $$xs)) 4>&1

test1: all
	(((($(JAVA) $(CP) $(CLASSPATH) org.junit.runner.JUnitCore BasicNodeTest; echo $$? >&3) | egrep -v \(org.junit\|sun.reflect\|java.lang.reflect\) >&4) 3>&1) | (read xs; exit $$xs)) 4>&1

test2: all
	(((($(JAVA) $(CP) $(CLASSPATH) org.junit.runner.JUnitCore ExtendedNodeTest; echo $$? >&3) | egrep -v \(org.junit\|sun.reflect\|java.lang.reflect\) >&4) 3>&1) | (read xs; exit $$xs)) 4>&1

test.xml: all
	-java $(CP) $(CLASSPATH):/home/csr21/src/goldsmiths/JUnitXmlFormatter/target/JUnitXmlFormatter-1.0.jar -Dorg.schmant.task.junit4.target=test.xml uk.ac.gold.doc.junitXmlFormatter.Runner $(subst .class,,$(TESTCLASSFILES))

.PHONY: test test1 test2 all clean
