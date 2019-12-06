#ifndef DISPLAY_H
#define DISPLAY_H

#include <QDialog>

namespace Ui {
class Display;
}

class Display : public QDialog
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = 0);
    ~Display();

    /**
    *	@brief	display.
    *	@pre	None.
    *	@post	str을 가져와 창에 띄움.
    */
    void DisplaySong(QString str);

private:
    Ui::Display *ui;
};

#endif // DISPLAY_H
