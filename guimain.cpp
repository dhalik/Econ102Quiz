#include <QApplication>

#include "window.h"
#include "question.h"
#include "tester.h"
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window window;
    window.show();
    return app.exec();
}
