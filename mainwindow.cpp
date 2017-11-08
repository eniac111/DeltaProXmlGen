#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("DeltaPro XML Generator");
    this->setFixedSize(500,260);
    this->setGeometry(QStyle::alignedRect(
                          Qt::LeftToRight,
                          Qt::AlignCenter,
                          this->size(),
                          qApp->desktop()->availableGeometry()
                          ));
//    if (QCoreApplication::arguments().length() >=2) {
//        QString argvstr = QCoreApplication::arguments().at(1);
//        filename = argvstr.section("/",-1,-1);
//        ui->FileLabel->setText(filename);
//        doEncrypt(QString(filename));
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_BtnBrowse_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Open a file for encryption", QString(), "Excel Spreadsheets (*.xlsx)");
    filename = filepath;
    ui->FileLabel->setText(filepath.section("/",-1,-1));

}


void MainWindow::on_actionAbout_triggered()
{
    About *AboutWindow = new About(this);
    AboutWindow->show();
}

int MainWindow::ReadExcel(QString file)
{

    QXlsx::Document *xlsx = new QXlsx::Document(file);
    int cellcount = 2;
    QString xmlfile = file.left(file.length()-1) + QString(".xml");
    int num_of_row = xlsx->dimension().lastRow();
    int num_of_col = xlsx->dimension().lastColumn();

//    qDebug()<<xlsx.rowHeight(3);
//    qDebug()<< xlsx->read("A1");

//    if (xlsx.rowHeight(3) != 15) {
//        QMessageBox::warning(this, tr("Warning: Incorrect format"),
//                             tr("The number of cells does not match the format of the document!"),
//                             QMessageBox::Ok);
//        return 2;
//    }


    qDebug()<<xlsx.rowHeight(2);
    qDebug()<< "H6 should be empty:__ " << xlsx.read("H6");
    qDebug()<<xlsx.read("C4");
    qDebug()<<xlsx.read("B4");
    qDebug()<<xlsx.read("A6");
    qDebug()<<xlsx.read("A7");

    while (true)
    {
        QMap<QString, QString> tmp;
        tmp["A"] = xlsx.read(QString("A%1").arg(cellcount));
        tmp["B"] = xlsx.read("B" + QString::number(cellcount)).toString();
        tmp["C"] = xlsx.read("C" + QString::number(cellcount)).toString();
        tmp["D"] = xlsx.read("D" + QString::number(cellcount)).toString();
        tmp["E"] = xlsx.read("E" + QString::number(cellcount)).toString();
        tmp["F"] = xlsx.read("F" + QString::number(cellcount)).toString();
        tmp["G"] = xlsx.read("G" + QString::number(cellcount)).toString();
        tmp["H"] = xlsx.read("H" + QString::number(cellcount)).toString();
        tmp["I"] = xlsx.read("I" + QString::number(cellcount)).toString();
        tmp["J"] = xlsx.read("J" + QString::number(cellcount)).toString();
        tmp["K"] = xlsx.read("K" + QString::number(cellcount)).toString();
        tmp["L"] = xlsx.read("L" + QString::number(cellcount)).toString();
        tmp["M"] = xlsx.read("M" + QString::number(cellcount)).toString();
        tmp["N"] = xlsx.read("N" + QString::number(cellcount)).toString();

        if(
                tmp["A"] == QString("") &&
                tmp["B"] == QString("") &&
                tmp["C"] == QString("") &&
                tmp["D"] == QString("") &&
                tmp["E"] == QString("") &&
                tmp["F"] == QString("") &&
                tmp["G"] == QString("") &&
                tmp["H"] == QString("") &&
                tmp["I"] == QString("") &&
                tmp["J"] == QString("") &&
                tmp["K"] == QString("") &&
                tmp["L"] == QString("") &&
                tmp["M"] == QString("") &&
                tmp["N"] == QString("")
                )
        {
            break;
        }
        else {
            tabledata.append(tmp);
            qDebug("Count: %d",tabledata.count());
            cellcount++;
        }

    }

    qDebug("LastValue: %s", tabledata[5]["J"]);
    ui->FileLabel->setText(tabledata[5]["A"]);


//    QFile file(xmlfile);
//    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
//        return 0;


    return 0;
}

void MainWindow::on_BtnSaveAs_clicked()
{
    ReadExcel(filename);
}
