QT += widgets

HEADERS       = window.h question.h
SOURCES       = guimain.cpp \
                window.cpp \
                question.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/dialogs/findfiles
INSTALLS += target
