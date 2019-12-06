#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <QDialog>
#include"admin.h"

namespace Ui {
class Withdrawal;
}

class Withdrawal : public QDialog
{
    Q_OBJECT

public:
    explicit Withdrawal(QWidget *parent = 0);
    ~Withdrawal();

    /**
    *	@brief	get ad.
    *	@pre	None.
    *	@post	this->ad를 멤버변수 ad로 가져오기 위한 함수.
    */
    void applyAdmin(Admin* ad);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Withdrawal *ui;

    friend class Admin;
    Admin *ad;
    int ran;
};

#endif // WITHDRAWAL_H
