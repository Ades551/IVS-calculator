#include "calc.h"
#include "ui_calc.h"
#include "lib/cmath.h"
#include <QDebug>


//Initial value of calculation
double calcVal=0.0;

//Button triggers
bool divTrigger=false;
bool mulTrigger=false;
bool addTrigger=false;
bool subTrigger=false;
bool facTrigger=false;
bool powTrigger=false;
bool sqrTrigger=false;
bool logTrigger=false;
bool dotTrigger=false;

calc::calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calc)
{
    ui->setupUi(this); //Initialize UI
    ui->display->setText(QString::number(calcVal)); //Display default value
    QPushButton *numbers[10]; //Make array of number buttons

    for (int i=0; i < 10; i++) {
        QString numButton = "button"+QString::number(i);
        numbers[i] = calc::findChild<QPushButton *> (numButton);
        connect(numbers[i], SIGNAL(released()), this, SLOT(NumberPressed()));
    }

    // CALL FUNCTIONS WHEN BUTTON IS RELEASED

    //MATH OPERATION BUTTONS
    connect(ui->buttonADD, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    /*connect(ui->buttonADD, SIGNAL(pressed()), this,
            SLOT( change_color() ));*/

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

void calc::change_color() { //FIXME OR DELETE ME IDUNNO
    QPushButton *button = (QPushButton *)sender();
    button->setStyleSheet("QPushButton { background-color: red }");
}

void calc::NumberPressed() {
    QPushButton *button = (QPushButton *)sender();
    QString butValue = button->text();
    QString displayValue = ui->display->text();

    //button->setStyleSheet("QPushButton { background-color: red }"); //DELETE ME

    if((QString::compare(displayValue, "0", Qt::CaseInsensitive) == 0) || (QString::compare(displayValue, "0.0", Qt::CaseInsensitive) == 0)){
        ui->display->setText(butValue);
    } else {
        QString newValueString = displayValue + butValue; //concat new to the number current
        double newValue = newValueString.toDouble();
        ui->display->setText(QString::number(newValue, 'g', 16));
    }
}

void calc::DotPressed() {
    QPushButton *button = (QPushButton *)sender();
    QString butValue = button->text();
    QString displayValue = ui->display->text();

    if (dotTrigger==false) {
        QString newValueString = displayValue + butValue; //concat new to the number current
        ui->display->setText(newValueString);
        dotTrigger=true;
    }
}

void calc::MathButtonPressed() {

    QString displayVal = ui->display->text();
    double calcValtmp = displayVal.toDouble();


    // Sender returns a pointer to the button pressed
    QPushButton *button = (QPushButton *)sender();

    // Get math symbol on the button
    QString butVal = button->text();

    if (calcValtmp!=0 || calcValtmp!=0.0) {
        if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
            divTrigger = true;
        }
        else if(QString::compare(butVal, "X", Qt::CaseInsensitive) == 0){
            mulTrigger = true;
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
        }
        ui->display->setText("");
        calcVal=displayVal.toDouble();
    }
    else {
        ui->display->setText(butVal);
    }
}

void calc::EqualButtonPressed(){

    // Holds new calculation
    double solution = 0.0;

    // Get value in display
    QString displayVal = ui->display->text();
    double dblDisplayVal = displayVal.toDouble();

    // Make sure a math button was pressed
    if(addTrigger || subTrigger || mulTrigger || divTrigger || logTrigger || facTrigger || powTrigger || sqrTrigger){
        if(addTrigger){
            solution = CalcMath::add(calcVal, dblDisplayVal);
        }
        else if(subTrigger){
            solution = CalcMath::sub(calcVal, dblDisplayVal);
        }
        else if(mulTrigger){
            solution = CalcMath::mult(calcVal, dblDisplayVal);
        }
        else if(divTrigger){
            solution = CalcMath::div(calcVal, dblDisplayVal);
            if (!solution) {
                ui->display->setText("MATH ERROR: Division by zero!");
            }
        }
        else if(logTrigger){
            solution = CalcMath::log(calcVal, dblDisplayVal);
            if (!solution) {
                ui->display->setText("MATH ERROR: Invalid use of log!");
            }
        }
        else if(facTrigger){
            solution = CalcMath::fact(calcVal);
            if (!solution) {
                ui->display->setText("MATH ERROR: Invalid number used!");
            }
        }
        else if(powTrigger){
            solution = CalcMath::pow(calcVal, dblDisplayVal);
        }
        else { //fix
            solution = CalcMath::root(calcVal, dblDisplayVal);
            if (!solution) {
                ui->display->setText("MATH ERROR: Invalid use of operation!");
            }
        }
    }

    // Put solution in display
    if (solution) {
        ui->display->setText(QString::number(solution));
    }
    // Reset all triggers
    divTrigger=false;
    mulTrigger=false;
    addTrigger=false;
    subTrigger=false;
    facTrigger=false;
    powTrigger=false;
    sqrTrigger=false;
    logTrigger=false;
}

void calc::DelButtonPressed() {
    QString displayValue = ui->display->text();

    if((displayValue.toDouble()!=0) && (displayValue.toDouble()!=0.0)) {
        displayValue.chop(1);
        ui->display->setText(displayValue);
    }
}

void calc::ACButtonPressed() {
    ui->display->setText("0.0");
    calcVal=0.0;
    divTrigger=false;
    mulTrigger=false;
    addTrigger=false;
    subTrigger=false;
    facTrigger=false;
    powTrigger=false;
    sqrTrigger=false;
    logTrigger=false;
}