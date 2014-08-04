#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QRadioButton>
#include <QLabel>
#include <QPushButton>

class Window : public QWidget
{
    Q_OBJECT

    public:
        Window(QWidget *parent = 0);

        private slots:
            void checkAnswer();
            void skip();
    private:
        QLabel * question;
        QRadioButton * a;
        QRadioButton * b;
        QRadioButton * c;
        QRadioButton * d;
        QRadioButton * e;

        QPushButton *answerButton;
        QPushButton *skipButton;

        QPushButton * createButton(const QString &, const char*);
};

#endif
