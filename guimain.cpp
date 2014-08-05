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

    vector<string> a;
    a.push_back("a");
    a.push_back("b");
    a.push_back("c");
    a.push_back("d");
    a.push_back("e");


    Question * q = new Question("HIHI", a,'A');

    window.update(q);
    return app.exec();
}
