#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QRadioButton>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include "question.h"
#include "tester.h"

class Window : public QWidget
{
    Q_OBJECT

    public:
        Window(QWidget *parent = 0);
        void update(Question*);

        private slots:
            void checkAnswer();
            void skip();

    private:
        //QT Onscreen items
        QLabel * question;
        std::vector<QRadioButton*> buttons;
        QPushButton *answerButton;
        QPushButton *skipButton;
        QMenu * fileMenu;
        QAction * selectChapters;

        //Tester
        Tester * t;

        //Internal Functions
        QPushButton * createButton(const QString &, const char*);
};

#endif
