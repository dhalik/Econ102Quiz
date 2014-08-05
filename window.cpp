#include <QtWidgets>

#include "window.h"
#include "question.h"
#include <vector>

using namespace std;

Window::Window(QWidget *parent): QWidget(parent){

    //create push buttons
    answerButton = createButton(tr("&Answer"), SLOT(checkAnswer()));
    skipButton = createButton(tr("&Skip"), SLOT(skip()));

    QHBoxLayout * hbox = new QHBoxLayout;
    hbox->addWidget(answerButton);
    hbox->addWidget(skipButton);

    question = new QLabel(tr("This here... This is supposed to be a question"));

    //set up radio button layout
    QGroupBox * groupBox= new QGroupBox;
    QVBoxLayout * vbox = new QVBoxLayout;
    for (int i = 0; i < 5; i++){
        QRadioButton * tmp = new QRadioButton(tr("Answer1"));
        buttons.push_back(tmp);
        vbox->addWidget(tmp);
    }
    groupBox->setLayout(vbox);

    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addWidget(question);
    mainLayout->addWidget(groupBox);
    mainLayout->addLayout(hbox);

    //set QWidget layout and info
    setLayout(mainLayout);
    setWindowTitle(tr("Economics"));

    t = new Tester();
}

void Window::update(){
    Question * q = t->getQuestionObj();
    vector<string> answerList = q->getAnswerList();
    question->setText(tr(q->getQuestion().c_str()));
    for (vector<QRadioButton*>::iterator it = buttons.begin();
            it != buttons.end();
            ++it){
        (*it)->setText(tr(answerList[it-buttons.begin()].c_str()));
    }
}

QPushButton *Window::createButton(const QString &text, const char *member){
    QPushButton *button = new QPushButton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void Window::checkAnswer(){
    char ans = '0';
    for (vector<QRadioButton*>::iterator it = buttons.begin(); it != buttons.end(); ++it){
        if ((*it)->isChecked()){
            ans = 'a' + (it-buttons.begin());
        }
    }
    if (ans == '0')
        return;
    t->getAnswer(ans);
    update();
}

void Window::skip(){
    update();
}
