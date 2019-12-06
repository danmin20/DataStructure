#ifndef APPLICATION_H
#define APPLICATION_H

#include <QDialog>
#include <QMessageBox>
#include<iostream>
#include"UserType.h"
#include"DoublyLinkedList.h"
#include"admin.h"

namespace Ui {
class Application;
}

class Application : public QDialog
{
    Q_OBJECT

public:
    explicit Application(QWidget *parent = 0);
    ~Application();

private slots:
    /**
    *	@brief	회원가입을 실행시킨다.
    *	@pre	회원가입이 시작되어야 한다..
    *	@post	회원가입이 끝난다.
    */
    void on_pushButton_clicked();

    /**
    *	@brief	로그인을 실행시킨다.
    *	@pre	로그인이 시작되어야 한다.
    *	@post	로그인이 끝난다.
    */
    void on_pushButton_2_clicked();

    /**
    *	@brief	회원탈퇴를 실행시킨다.
    *	@pre	회원탈퇴가 시작되어야 한다.
    *	@post	회원탈퇴가 끝난다.
    */
    void on_pushButton_3_clicked();

    /**
    *	@brief	관리자모드를 실행시킨다.
    *	@pre	관리자모드가 시작되어야 한다.
    *	@post	관리자모드가 끝난다.
    */
    void on_pushButton_4_clicked();

private:
    Ui::Application *ui;
    Admin *admin;
};

#endif // APPLICATION_H
