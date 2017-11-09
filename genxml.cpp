#include "genxml.h"

GenXML::GenXML( QVector<QVector<QString>> data, QString file )
{
    tabledata = data;
    xmlfile = file;
}


int GenXML::Convert () {
    QDomDocument xmldoc;
    xmldoc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");

    QDomElement TransferData = xmldoc.createElement("TransferData");
    TransferData.setAttribute("xmlns", "urn:Transfer");

    QDomElement Accountings = xmldoc.createElement("Accountings");

    qDebug("RAZMER: %i", tabledata[1].size());

    for( int i=0; i<tabledata.size(); i++) {

        if(tabledata[i][0] == QString("Фактура").toUtf8()) {
            qDebug("FAKTURA");
        }
        else {
            qDebug("NE E FAKTURA");
        }
        qDebug("%s", tabledata[i][1]);
    }

//    if(tabledata[1][0] == QString("Фактура").toUtf8())
//            qDebug("FAKTURA E");

//    QMessageBox msgBox;
//    msgBox.setWindowTitle("foo");
//    msgBox.setText(tabledata[1][0]);
//    msgBox.exec();
////    qDebug(tabledata[1][0].toLatin1());

    return 0;
}
