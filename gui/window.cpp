#include <QtWidgets>

#include "window.h"

Window::Window(QWidget *parent): QWidget(parent){

    //create push buttons
    answerButton = createButton(tr("&Answer"), SLOT(checkAnswer()));
    skipButton = createButton(tr("&Skip"), SLOT(skip()));

    QHBoxLayout * hbox = new QHBoxLayout;
    hbox->addWidget(answerButton);
    hbox->addWidget(skipButton);

    question = new QLabel(tr("This here... This is supposed to be a question"));

    //create radio buttons
    a = new QRadioButton(tr("Answer1"));
    b = new QRadioButton(tr("Answer2"));
    c = new QRadioButton(tr("Answer3"));
    d = new QRadioButton(tr("Answer4"));
    e = new QRadioButton(tr("Answer5"));

    //set up radio button layout
    QGroupBox * groupBox= new QGroupBox;
    QVBoxLayout * vbox = new QVBoxLayout;
    vbox->addWidget(a);
    vbox->addWidget(b);
    vbox->addWidget(c);
    vbox->addWidget(d);
    vbox->addWidget(e);
    groupBox->setLayout(vbox);

    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addWidget(question);
    mainLayout->addWidget(groupBox);
    mainLayout->addLayout(hbox);

    //set QWidget layout and info
    setLayout(mainLayout);
    setWindowTitle(tr("Find Files"));
    resize(700, 300);
}

QPushButton *Window::createButton(const QString &text, const char *member)
{
    QPushButton *button = new QPushButton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void Window::checkAnswer(){

}

void Window::skip(){

}
