#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include"doublylinkedlist.h"
#include"usertype.h"

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = 0);
    ~Admin();

    /**
    *	@brief	UserList내의 아이템들과 ID비교.
    *	@pre	None.
    *	@post	같은 ID를 가지는 아이템이 존재하는 경우 1 반환.
    */
    int CheckID(UserType& user);

    /**
    *	@brief	UserList에 계정 추가.
    *	@pre	None.
    *	@post	None.
    */
    void AddAccount(UserType user);

    /**
    *	@brief	UserList에서 계정 삭제.
    *	@pre	None.
    *	@post	None.
    */
    void DelAccount(UserType& user);

private slots:

    /**
    *	@brief	delete user's info.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_2_clicked();


    /**
    *	@brief	display all users' info.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_clicked();


    /**
    *	@brief	delete all users' info.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_3_clicked();


    /**
    *	@brief	display all users' musics.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_4_clicked();

private:
    friend class Assign;
    friend class Withdrawal;
    Ui::Admin *ui;
    DoublyLinkedList<UserType>UserList;
};

#endif // ADMIN_H
