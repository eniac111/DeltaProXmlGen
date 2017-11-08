#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QDesktopWidget>
#include <QStyle>

namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();

private slots:

private:
    Ui::About *ui;
};

#endif // ABOUT_H
