CXX = g++
CXXFLAGS = -Wall -MMD -g
EXEC = Quizzer
OBJECTS = main.o tester.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

Quizzer.exe: ${OBJECTS}
	i586-mingw32msvc-g++ main.cpp tester.cpp -o ${EXEC}.exe

zip: Quizzer Quizzer.exe QuestionBank
	zip -r IS.zip Quizzer.exe QuestionBank
	mv IS.zip ~/Dropbox/Apps/My.DropPages/kam.droppages.com/Content/
