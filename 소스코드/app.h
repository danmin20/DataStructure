#ifndef APP_H
#define APP_H

#include<QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include<iostream>
#include"UserType.h"
#include"DoublyLinkedList.h"
#include"admintype.h"
using namespace std;

namespace Ui {
class App;
}

class App : public QMainWindow
{
    Q_OBJECT

public:
    explicit App(QWidget *parent = 0);
    ~App();

    int Assign();	//add 사용

    int LogIn();	//get 사용

    int Withdrawal();

    void DisplayAllUserInfo();	//display 사용

    void DeleteAllUserInfo();

    void DisplayAllUserMusic();

    void DeleteUserInfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:

    Ui::App *ui;
};

#endif // APP_H
