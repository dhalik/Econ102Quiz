CXX = g++
CXXFLAGS = -Wall -MMD -g -DDEBUG
EXEC = Quizzer
OBJECTS = main.o tester.o question.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

questionrepo.h: QuestionBank/econ.xml
	python encode.py QuestionBank/econ.xml

Quizzer.exe: ${OBJECTS}
	i586-mingw32msvc-g++ main.cpp tester.cpp question.cpp -o ${EXEC}.exe
