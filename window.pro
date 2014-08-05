QT += widgets

HEADERS       = window.h question.h tester.h
SOURCES       = guimain.cpp \
                window.cpp \
                question.cpp \
                tester.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/dialogs/findfiles
INSTALLS += target
