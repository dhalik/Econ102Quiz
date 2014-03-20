#include <QApplication>
#include <QWidget>

int main(int argc, char * argv[]){
	QApplication qapp(argc,argv);

	QWidget window;

	window.resize(200,200);
	window.setWindowTitle("Helloworld");
	window.show;

	qapp.exec();
}
