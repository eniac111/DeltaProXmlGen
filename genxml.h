#ifndef GENXML_H
#define GENXML_H
#include <QString>
#include <QMap>
#include <QVector>
#include <QtXml>
#include <QDomDocument>
#include <QDomElement>


class GenXML
{
public:
    GenXML( QVector<QMap<QString, QString>> data);
    int Convert();

private:
    QVector<QMap<QString, QString>> tabledata;

};

#endif // GENXML_H
