#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    this->setWindowTitle("About DP XML Generator " + APP_VERSION);
    this->setGeometry(QStyle::alignedRect(
                          Qt::LeftToRight,
                          Qt::AlignCenter,
                          this->size(),
                          qApp->desktop()->availableGeometry()
                          ));
    ui->label_version->setText(QString("Version: ") + APP_VERSION);
    ui->label_releasedate->setText(QString("Released on: ") + APP_RELEASE_DATE);
}

About::~About()
{
    delete ui;
}

