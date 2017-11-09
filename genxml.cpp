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

//    qDebug("RAZMER: %i", tabledata[1].size());

//    for( int i=0; i<tabledata.size(); i++) {

//        if(tabledata[i][1] == QString("Фактура")) {
//            qDebug("FAKTURA");
//        }
//        else {
//            qDebug("NE E FAKTURA");
//        }
//    }

    return 0;
}
