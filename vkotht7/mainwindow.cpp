#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->num1->setText("0");
    ui->num2->setText("0");
    ui->result->setText("0");

    number1 = "";
    number2 = "";
    state = 1;
    result = 0;
    operand = 0;

    connect(ui->N0,&QPushButton::clicked,this,
    &MainWindow::numberClickHandler);
    connect(ui->N1,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N2,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N3,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N4,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N5,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N6,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N7,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N8,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N9,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);

    connect(ui->add,&QPushButton::clicked,this,
            &MainWindow::addSubMulDivClickHandler);
    connect(ui->div,&QPushButton::clicked,this,
            &MainWindow::addSubMulDivClickHandler);
    connect(ui->sub,&QPushButton::clicked,this,
            &MainWindow::addSubMulDivClickHandler);
    connect(ui->mul,&QPushButton::clicked,this,
            &MainWindow::addSubMulDivClickHandler);

    connect(ui->clear,&QPushButton::clicked,this,
            &MainWindow::clearAndEnterClickHandler);
    connect(ui->enter,&QPushButton::clicked,this,
            &MainWindow::clearAndEnterClickHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::numberClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    if (button == ui->N0)
    {
        if (state == 1)
        {
            number1 += "0";
            ui->num1->setText(number1);
        }
        else if (state == 2)
        {
            number2 += "0";
            ui->num2->setText(number2);
        }
    }

    if (button == ui->N1)
    {
        if (state == 1)
        {
            number1 += "1";
            ui->num1->setText(number1);
        }
        else if (state == 2)
        {
            number2 += "1";
            ui->num2->setText(number2);
        }
    }

    if (button == ui->N2)
    {
        if (state == 1)
        {
            number1 += "2";
            ui->num1->setText(number1);
        }
        else if (state == 2)
        {
            number2 += "2";
            ui->num2->setText(number2);
        }
    }

    if (button == ui->N3)
    {
        if (state == 1)
        {
            number1 += "3";
            ui->num1->setText(number1);
        }
        else if (state == 2)
        {
            number2 += "3";
            ui->num2->setText(number2);
        }
    }

    if (button == ui->N4)
    {
        if (state == 1)
        {
            number1 += "4";
            ui->num1->setText(number1);
        }
        else if (state == 2)
        {
            number2 += "4";
            ui->num2->setText(number2);
        }
    }

    if (button == ui->N5)
    {
        if (state == 1)
        {
            number1 += "5";
            ui->num1->setText(number1);
        }
        else if (state == 2)
        {
            number2 += "5";
            ui->num2->setText(number2);
        }
    }

    if (button == ui->N6)
    {
        if (state == 1)
        {
            number1 += "6";
            ui->num1->setText(number1);
        }
        else if (state == 2)
        {
            number2 += "6";
            ui->num2->setText(number2);
        }
    }

    if (button == ui->N7)
    {
        if (state == 1)
        {
            number1 += "7";
            ui->num1->setText(number1);
        }
        else if (state == 2)
        {
            number2 += "7";
            ui->num2->setText(number2);
        }
    }

    if (button == ui->N8)
    {
        if (state == 1)
        {
            number1 += "8";
            ui->num1->setText(number1);
        }
        else if (state == 2)
        {
            number2 += "8";
            ui->num2->setText(number2);
        }
    }

    if (button == ui->N9)
    {
        if (state == 1)
        {
            number1 += "9";
            ui->num1->setText(number1);
        }
        else if (state == 2)
        {
            number2 += "9";
            ui->num2->setText(number2);
        }
    }

    qDebug() << "number1:" << number1;
    qDebug() << "number2:" << number2;
    qDebug() << "state:" << state;
}


void MainWindow::clearAndEnterClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    if (button == ui->clear)
    {
        state = 1;
        number1 = "";
        number2 = "";
        result = 0;
        operand = 0;

        resetLineEdits();

        qDebug() << "tyhjennys";
    }

    else if (button == ui->enter)
    {
        float num1 = number1.toFloat();
        float num2 = number2.toFloat();

        switch (operand)
        {
        case 0:
            result = num1 + num2;
            break;
        case 1:
            result = num1 - num2;
            break;
        case 2:
            result = num1 * num2;
            break;
        case 3:
        if (num2 != 0)
        {
            result = num1 / num2;
        }
        else
            {
            ui->result->setText("ei voi jakaa nollalla");
            return;
            }
        break;
        default:
            return;
        }
    }



    ui->result->setText(QString::number(result));
        qDebug() << "result:" << result;


        }


void MainWindow::addSubMulDivClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString buttonText = button->text();

    if (buttonText == "+")
    {
        operand = 0;
    }
    else if (buttonText == "-")
    {
        operand = 1;
    }
    else if (buttonText == "*")
    {
        operand = 2;
    }
    else if (buttonText == "/")
    {
        operand = 3;
    }

    state = 2;
    qDebug() << "operand:" << operand;
    qDebug() << "state vaihtui:" << state;
}


void MainWindow::resetLineEdits()
{
    ui->num1->setText("0");
    ui->num2->setText("0");
    ui->result->setText("0");
}
