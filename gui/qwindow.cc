#include <QApplication>
#include <QWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>


int main(int argc, char * argv[]){
	QApplication app(argc,argv);

	QGroupBox * groupBox = new QGroupBox("RB");
	QRadioButton * r1 = new QRadioButton ("Ans1");
	QRadioButton * r2 = new QRadioButton ("Ans2");
	QRadioButton * r3 = new QRadioButton ("Ans3");

	QVBoxLayout * vbox = new QVBoxLayout;
	vbox->addWidget(r1);
	vbox->addWidget(r2);
	vbox->addWidget(r3);
	vbox->addStretch(1);

	groupBox->setLayout(vbox);

	groupBox->setWindowTitle("Helloworld");
	groupBox->show();

	app.exec();
}
