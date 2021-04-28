#ifndef CALC_H
#define CALC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class calc; }
QT_END_NAMESPACE

class calc : public QMainWindow
{
    Q_OBJECT

public:
    explicit calc(QWidget *parent = 0);
    ~calc();

private:
    Ui::calc *ui;
private slots:
    /**
     * @brief Function to connect number buttons
     */
    void NumberPressed();

    /**
     * @brief Function to connect decimal separator button
     */ 
    void DotPressed();

    /**
     * @brief Function to connect math operation buttons
     */ 
    void MathButtonPressed();

    /**
     * @brief Function to connect equal button
     */ 
    void EqualButtonPressed();

    /**
     * @brief Function to connect DEL button
     */ 
    void DelButtonPressed();

    /**
     * @brief Function to connect AC button
     */ 
    void ACButtonPressed();

    /**
     * @brief Function for help window
     */
    void HelpButtonPressed();

};
#endif // CALC_H
