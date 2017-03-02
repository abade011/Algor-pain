include ../../java.mk

TESTCLASSFILES = ../../12/java/LengthNodeTest.class ../../12/java/RemoveNodeTest.class ../../12/java/ReverseNodeTest.class Timing12Test.class CycleTest.class
CLASSFILES = ../../11/java/Node.class CycleInfo.class CycleDetection.class $(TESTCLASSFILES)

CLASSPATHS += ../../11/java ../../12/java

all: $(CLASSFILES)

clean:
	-rm -f $(TESTCLASSFILES) test.xml

%.class: %.java
	$(JAVAC) $(CP) $(CLASSPATH) $^

test: all
	(((($(JAVA) -Xss10m $(CP) $(CLASSPATH) org.junit.runner.JUnitCore $(subst .class,,$(notdir $(TESTCLASSFILES))); echo $$? >&3) | egrep -v \(org.junit\|sun.reflect\|java.lang.reflect\) >&4) 3>&1) | (read xs; exit $$xs)) 4>&1

test.xml: all
	-java $(CP) $(CLASSPATH):/home/csr21/src/goldsmiths/JUnitXmlFormatter/target/JUnitXmlFormatter-1.0.jar -Dorg.schmant.task.junit4.target=test.xml uk.ac.gold.doc.junitXmlFormatter.Runner $(subst .class,,$(TESTCLASSFILES))

.PHONY: test all clean
