CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = Quizzer
OBJECTS = main.o tester.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

