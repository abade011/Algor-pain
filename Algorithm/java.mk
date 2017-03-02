JAVAC = javac
JAVA = java
CP = -cp
CLASSPATHS = . /usr/share/java/junit4.jar

empty :=
space := $(empty) $(empty)
CLASSPATH = $(subst $(space),:,$(CLASSPATHS))
