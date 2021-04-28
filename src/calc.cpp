#include "calc.h"
#include "ui_calc.h"
#include "lib/cmath.h"
#include <stdexcept>

// #include <QDebug>

//Initial value of calculation
double calcVal=0;

QString displayNum = "";
//QString displayNum_2 = "";
//QString displayOperand = "";

bool next_val = false;

//Button triggers
bool divTrigger=false;
bool mulTrigger=false;
bool addTrigger=false;
bool subTrigger=false;
bool facTrigger=false;
bool powTrigger=false;
bool sqrTrigger=false;
bool logTrigger=false;

void reset();

calc::calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calc)
{
    ui->setupUi(this); //Initialize UI
    ui->display->setText(""); //Display default value
    QPushButton *numbers[10]; //Make array of number buttons

    for (int i=0; i < 10; i++) {
        QString numButton = "button"+QString::number(i);
        numbers[i] = calc::findChild<QPushButton *> (numButton);
        connect(numbers[i], SIGNAL(released()), this, SLOT(NumberPressed()));
        numbers[i]->setShortcut(QKeySequence(QString::number(i)));
    }

    // KEYBOARD SHORTCUTS
    ui->buttonDEL->setShortcut(Qt::Key_Backspace);
    ui->buttonDOT->setShortcut(Qt::Key_Period);
    ui->buttonEQUAL->setShortcut(Qt::Key_Enter);
    ui->buttonAC->setShortcut(Qt::Key_Escape);
    ui->buttonADD->setShortcut(Qt::Key_Plus);
    ui->buttonSUB->setShortcut(Qt::Key_Minus);
    ui->buttonMUL->setShortcut(QKeySequence("*"));
    ui->buttonDIV->setShortcut(Qt::Key_Slash);

    // CALL FUNCTIONS WHEN BUTTON IS RELEASED

    //MATH OPERATION BUTTONS
    connect(ui->buttonADD, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->buttonSUB, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->buttonMUL, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->buttonDIV, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->buttonFACT, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->buttonPOW, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->buttonSQRT, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->buttonLOG, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));

    //DOT BUTTON RELEASE
    connect(ui->buttonDOT, SIGNAL(released()), this,
            SLOT(DotPressed()));
    //EQUAL BUTTON RELEASED
    connect(ui->buttonEQUAL, SIGNAL(released()), this,
            SLOT(EqualButtonPressed()));
    //DELETE BUTTON RELEASED
    connect(ui->buttonDEL, SIGNAL(released()), this,
            SLOT(DelButtonPressed()));
    //AC BUTTON RELEASED
    connect(ui->buttonAC, SIGNAL(released()), this,
            SLOT(ACButtonPressed()));
}

//calc destructor
calc::~calc()
{
    delete ui;
}

void calc::NumberPressed() {
    QPushButton *button = (QPushButton *)sender();
    QString butValue = button->text();
    QString displayValue = ui->display->text();

    if(displayNum.length() < 16){
        if(QString::compare(displayNum, "0", Qt::CaseInsensitive) != 0) {
        displayNum = displayNum + butValue;
        ui->display->setText(displayValue + butValue);
        } else {
            displayNum = butValue;
            ui->display->setText(displayNum);
        }
    }
}

void calc::DotPressed() {
    QPushButton *button = (QPushButton *)sender();
    QString butValue = button->text();
    QString displayValue = ui->display->text();

    if(!displayNum.contains(".", Qt::CaseInsensitive)){
        displayNum = displayNum + ".";
        ui->display->setText(displayValue + ".");
    }
}

void calc::MathButtonPressed() {

    QString displayVal = ui->display->text();

    // Sender returns a pointer to the button pressed
    QPushButton *button = (QPushButton *)sender();

    // Get math symbol on the button
    QString butVal = button->text();

    if (QString::compare(displayNum, "", Qt::CaseInsensitive) != 0) {
        if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
            divTrigger = true;
        }
        else if(QString::compare(butVal, "X", Qt::CaseInsensitive) == 0){
            mulTrigger = true;
            butVal = "*";
        }
        else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
            addTrigger = true;
        }
        else if(QString::compare(butVal, "-", Qt::CaseInsensitive) == 0){
            subTrigger = true;
        }
        else if(QString::compare(butVal, "√", Qt::CaseInsensitive) == 0){
            sqrTrigger = true;
        }
        else if(QString::compare(butVal, "log", Qt::CaseInsensitive) == 0){
            logTrigger = true;
        }
        else if(QString::compare(butVal, "!", Qt::CaseInsensitive) == 0){
            facTrigger = true;
        }
        else if(QString::compare(butVal, "X^Y", Qt::CaseInsensitive) == 0){
            powTrigger = true;
            butVal = "^";
        }

        QString output;

        if(next_val){
            output = "invalid operation!";
            displayNum = "0";
            reset();
        } else {
            next_val = true;
            calcVal = displayNum.toDouble();
            displayNum = "";
            output = displayVal + butVal;
        }
        
        ui->display->setText(output);
        //calcVal=displayVal.toDouble();
    }
    else if(QString::compare(butVal, "-", Qt::CaseInsensitive) == 0){
        displayNum = butVal;
        ui->display->setText(displayVal + butVal);
    }
}

void calc::EqualButtonPressed(){

    // Holds new calculation
    double solution = 0;

    // Get value in display
    //QString displayVal = ui->display->text();
    //double dblDisplayVal = displayVal.toDouble();

    bool exception = false;

    //qDebug() << calcVal << displayNum;

    // Make sure a math button was pressed
    if(addTrigger || subTrigger || mulTrigger || divTrigger || logTrigger || facTrigger || powTrigger || sqrTrigger){
        double val2 = displayNum.toDouble();
        //qDebug() << calcVal << val2;
        if(addTrigger){
            solution = CalcMath::add(calcVal, val2);
        }
        else if(subTrigger){
            solution = CalcMath::sub(calcVal, val2);
        }
        else if(mulTrigger){
            solution = CalcMath::mult(calcVal, val2);
        }
        else if(divTrigger){
            try {
                solution = CalcMath::div(calcVal, val2);
            } catch(std::invalid_argument e) {
                ui->display->setText(e.what());
                exception = true;
            }
        }
        else if(logTrigger){
            try {
                solution = CalcMath::log(calcVal, val2);
            } catch(std::invalid_argument e) {
                ui->display->setText(e.what());
                exception = true;
            }
        }
        else if(facTrigger){
            try {
                solution = CalcMath::fact(calcVal);
            } catch(std::invalid_argument e) {
                ui->display->setText(e.what());
                exception = true;
            }
        }
        else if(powTrigger){
            solution = CalcMath::pow(calcVal, val2);
        }
        else if(sqrTrigger){
            try {
                solution = CalcMath::root(calcVal, val2);
            } catch(std::invalid_argument e) {
                ui->display->setText(e.what());
                exception = true;
            }
        }

        // Put solution in display
        if (!exception) {
            displayNum = QString::number(solution);
            ui->display->setText(displayNum);
        } else {
            displayNum = "0";
        }
    } else {
        ui->display->setText(displayNum);
    }

    // set calcValues to NULL
    calcVal = 0;

    reset();
}

void calc::DelButtonPressed() {
    QString displayValue = ui->display->text();

    if(QString::compare(displayValue, "", Qt::CaseInsensitive) != 0) {
        displayValue.chop(1);
        if(QString::compare(displayNum, "", Qt::CaseInsensitive) != 0) {
            displayNum.chop(1);
        } else {
            displayNum = displayValue;
            reset();
        }
        
        ui->display->setText(displayValue);
    }
}

void calc::ACButtonPressed() {
    ui->display->setText("");
    // set calcValues to NULL
    calcVal = 0;

    displayNum="";

    //reset nextVal bool
    reset();
}

void reset(){
    next_val = false;

    divTrigger=false;
    mulTrigger=false;
    addTrigger=false;
    subTrigger=false;
    facTrigger=false;
    powTrigger=false;
    sqrTrigger=false;
    logTrigger=false;
}