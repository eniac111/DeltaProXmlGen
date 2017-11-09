#include "genxml.h"

GenXML::GenXML( QVector<QVector<QString>> data )
{
    QVector<QVector<QString>> tabledata = data;
}


int GenXML::Convert () {
    QDomDocument xmldoc;
    xmldoc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");

    QDomElement TransferData = xmldoc.createElement("TransferData");
    TransferData.setAttribute("xmlns", "urn:Transfer");

    QDomElement Accountings = xmldoc.createElement("Accountings");
//    for( int i=0; i<= tabledata.length(); i++) {
//        if(tabledata[i][])
//    }

    return 0;
}
