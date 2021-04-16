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
    void NumberPressed();
    void DotPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void DelButtonPressed();
    void ACButtonPressed();
};
#endif // CALC_H
