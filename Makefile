CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = Quizzer
OBJECTS = main.o tester.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

win: ${OBJECTS}
	i586-mingw32msvc-g++ main.cpp tester.cpp -o ${EXEC}.exe
