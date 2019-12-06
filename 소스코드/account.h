#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include <QString>

#include"SortedList.h"
#include"SimpleMusicType.h"
#include"CircularQueue.h"
#include"DoublyLinkedList.h"
using namespace std;

#define FILENAMESIZE 1024

namespace Ui {
class Account;
}

class Account : public QDialog
{
    Q_OBJECT

public:
    explicit Account(QWidget *parent = 0);
    ~Account();
    /**
    *	@brief  음악 정보를 반환한다.
    *	@pre	없음.
    *	@post	음악 정보를 반환한다.
    */
    QString DisplayAllMusic();

private slots:
    /**
    *	@brief	Add Music.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_clicked();

    /**
    *	@brief	Delete Music.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_2_clicked();

    /**
    *	@brief	Make MusicList Empty.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_3_clicked();

    /**
    *	@brief	Search Mode.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_4_clicked();

    /**
    *	@brief	Display Recently Added Music.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_9_clicked();

    /**
    *	@brief	Display All Music.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_13_clicked();

    /**
    *	@brief	Display All Music in PlayList.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_11_clicked();

    /**
    *	@brief	Play Music.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_10_clicked();

    /**
    *	@brief	Make PlayList Empty.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_12_clicked();

    void on_pushButton_5_clicked();

private:
    friend class Search;
    friend class AddSong;
    friend class DeleteSong;
    friend class PlaySong;
    friend class FileOut;

    Ui::Account *ui;
    SortedList<MusicType> MusicList;			//PK로 sort
    CircularQueue<SimpleMusicType> PlayList;	//최근 재생목록
};

#endif // ACCOUNT
