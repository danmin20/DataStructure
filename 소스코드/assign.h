#ifndef ASSIGN_H
#define ASSIGN_H

#include <QDialog>
#include"usertype.h"
#include"admin.h"

namespace Ui {
class Assign;
}

class Assign : public QDialog
{
    Q_OBJECT

public:
    explicit Assign(QWidget *parent = 0);
    ~Assign();

    /**
    *	@brief	get ad.
    *	@pre	None.
    *	@post	this->ad를 멤버변수 ad로 가져오기 위한 함수.
    */
    void applyAdmin(Admin* ad);

private slots:
    /**
    *	@brief	UserList에 회원정보 추가.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_clicked();

private:
    friend class Admin;
    Ui::Assign *ui;

    Admin *ad;
};

#endif // ASSIGN_H
