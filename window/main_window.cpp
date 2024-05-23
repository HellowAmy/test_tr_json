
#include "main_window.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QHBoxLayout>

#include "Ttr_json.h"

main_window::main_window(QWidget *parent) : QWidget(parent)
{
    this->resize(500,200);
    this->setWindowTitle(TTRS("Login Window"));

    QVBoxLayout *lay_main = new QVBoxLayout(this);

    {
        QLabel *lab = new QLabel(TTRS("Welcome to XX Hospital"),this);
        lay_main->addWidget(lab);
    }
    {
        QLabel *lab = new QLabel(TTRS("It is the best hospital in the world"),this);
        lay_main->addWidget(lab);
    }
    {
        QHBoxLayout *lay = new QHBoxLayout;
        QRadioButton *rbutt_student = new QRadioButton(TTRS("Student"),this);
        QRadioButton *rbutt_doctor_s = new QRadioButton(TTRSC("Doctor","at school"),this);
        QRadioButton *rbutt_doctor_h = new QRadioButton(TTRSC("Doctor","at hospital"),this);
        QRadioButton *rbutt_director = new QRadioButton(TTRS("Director"),this);

        rbutt_student->setChecked(true);

        lay->addWidget(rbutt_student);
        lay->addWidget(rbutt_doctor_s);
        lay->addWidget(rbutt_doctor_h);
        lay->addWidget(rbutt_director);
        lay_main->addLayout(lay);
    }

    {
        QHBoxLayout *lay = new QHBoxLayout;
        QLabel *lab = new QLabel(TTRS("Account:"),this);

        QLineEdit *edit = new QLineEdit(this);
        edit->setPlaceholderText(TTRS("Please enter the account"));

        lay->addWidget(lab);
        lay->addWidget(edit);
        lay_main->addLayout(lay);
    }
    {
        QHBoxLayout *lay = new QHBoxLayout;
        QLabel *lab = new QLabel(TTRS("Password:"),this);

        QLineEdit *edit = new QLineEdit(this);
        edit->setPlaceholderText(TTRS("Please enter the Password"));

        lay->addWidget(lab);
        lay->addWidget(edit);
        lay_main->addLayout(lay);
    }

    {
        QHBoxLayout *lay = new QHBoxLayout;
        QPushButton *butt_cancel = new QPushButton(TTRS("Exit"),this);
        QPushButton *butt_confirm = new QPushButton(TTRS("Login"),this);
        lay->addWidget(butt_cancel);
        lay->addWidget(butt_confirm);
        lay_main->addLayout(lay);
    }

}

main_window::~main_window()
{
}