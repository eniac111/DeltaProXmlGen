#Workaround for Issue #60
CONFIG += git_build

load(qt_build_config)

MODULE_VERSION = 0.3.0

QT       += core gui xml


include(./3rdparty/qtxlsx-olf/src/xlsx/qtxlsx.pri)
QT += xlsx

#CONFIG += static

RC_FILE = deltaproxmlgen.rc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DeltaProXmlGen
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        about.cpp \
    genxml.cpp

HEADERS  += mainwindow.h \
    about.h \w \
    genxml.h
    mainwindow.h

FORMS    += mainwindow.ui \
    about.ui

#RESOURCES += \
#    logo.qrc

SUBDIRS += \
    3rdparty/qtxlsx/examples/xlsx/calendar/calendar.pro \
    3rdparty/qtxlsx/examples/xlsx/chart/chart.pro \
    3rdparty/qtxlsx/examples/xlsx/chartsheet/chartsheet.pro \
    3rdparty/qtxlsx/examples/xlsx/conditionalformatting/conditionalformatting.pro \
    3rdparty/qtxlsx/examples/xlsx/datavalidation/datavalidation.pro \
    3rdparty/qtxlsx/examples/xlsx/definename/definename.pro \
    3rdparty/qtxlsx/examples/xlsx/demo/demo.pro \
    3rdparty/qtxlsx/examples/xlsx/documentproperty/documentproperty.pro \
    3rdparty/qtxlsx/examples/xlsx/extractdata/extractdata.pro \
    3rdparty/qtxlsx/examples/xlsx/formulas/formulas.pro \
    3rdparty/qtxlsx/examples/xlsx/hello/hello.pro \
    3rdparty/qtxlsx/examples/xlsx/hyperlinks/hyperlinks.pro \
    3rdparty/qtxlsx/examples/xlsx/image/image.pro \
    3rdparty/qtxlsx/examples/xlsx/mergecells/mergecells.pro \
    3rdparty/qtxlsx/examples/xlsx/numberformat/numberformat.pro \
    3rdparty/qtxlsx/examples/xlsx/richtext/richtext.pro \
    3rdparty/qtxlsx/examples/xlsx/rowcolumn/rowcolumn.pro \
    3rdparty/qtxlsx/examples/xlsx/style/style.pro \
    3rdparty/qtxlsx/examples/xlsx/worksheetoperations/worksheetoperations.pro \
    3rdparty/qtxlsx/examples/xlsx/xlsxwidget/xlsxwidget.pro \
    3rdparty/qtxlsx/examples/xlsx/xlsx.pro \
    3rdparty/qtxlsx/examples/examples.pro \
    3rdparty/qtxlsx/src/xlsx/doc/snippets/doc_src_qtxlsx.pro \
    3rdparty/qtxlsx/src/xlsx/xlsx.pro \
    3rdparty/qtxlsx/src/src.pro \
    3rdparty/qtxlsx/tests/auto/cellreference/cellreference.pro \
    3rdparty/qtxlsx/tests/auto/cmake/cmake.pro \
    3rdparty/qtxlsx/tests/auto/document/document.pro \
    3rdparty/qtxlsx/tests/auto/format/format.pro \
    3rdparty/qtxlsx/tests/auto/propsapp/propsapp.pro \
    3rdparty/qtxlsx/tests/auto/propscore/propscore.pro \
    3rdparty/qtxlsx/tests/auto/relationships/relationships.pro \
    3rdparty/qtxlsx/tests/auto/richstring/richstring.pro \
    3rdparty/qtxlsx/tests/auto/sharedstrings/sharedstrings.pro \
    3rdparty/qtxlsx/tests/auto/styles/styles.pro \
    3rdparty/qtxlsx/tests/auto/utility/utility.pro \
    3rdparty/qtxlsx/tests/auto/worksheet/worksheet.pro \
    3rdparty/qtxlsx/tests/auto/xlsxconditionalformatting/xlsxconditionalformatting.pro \
    3rdparty/qtxlsx/tests/auto/zipreader/zipreader.pro \
    3rdparty/qtxlsx/tests/auto/auto.pro \
    3rdparty/qtxlsx/tests/benchmarks/xmlspace/xmlspace.pro \
    3rdparty/qtxlsx/tests/benchmarks/benchmarks.pro \
    3rdparty/qtxlsx/tests/tests.pro \
    3rdparty/qtxlsx/qtxlsx.pro

DISTFILES += \
    3rdparty/qtxlsx/src/xlsx/qtxlsx.pri \
    3rdparty/qtxlsx/examples/xlsx/demo/doc/images/xlsx_demo.gif \
    3rdparty/qtxlsx/examples/xlsx/documentproperty/doc/images/doc_property.png \
    3rdparty/qtxlsx/examples/xlsx/hello/doc/images/hello.png \
    3rdparty/qtxlsx/examples/xlsx/mergecells/doc/images/xlsx-mergecells.png \
    3rdparty/qtxlsx/examples/xlsx/richtext/doc/images/richtext.png \
    3rdparty/qtxlsx/README.md \
    3rdparty/qtxlsx/src/xlsx/doc/qtxlsx.qdocconf \
    3rdparty/qtxlsx/examples/xlsx/CMakeLists.txt \
    3rdparty/qtxlsx/tests/auto/cmake/CMakeLists.txt \
    3rdparty/qtxlsx/tests/auto/CMakeLists.txt \
    3rdparty/qtxlsx/tests/CMakeLists.txt \
    3rdparty/qtxlsx/CMakeLists.txt \
    3rdparty/qtxlsx/QtXlsxWriterConfig.cmake.in \
    3rdparty/qtxlsx/sync.profile \
    3rdparty/qtxlsx/examples/xlsx/conditionalformatting/doc/src/conditionalformatting.qdoc \
    3rdparty/qtxlsx/examples/xlsx/demo/doc/src/demo.qdoc \
    3rdparty/qtxlsx/examples/xlsx/documentproperty/doc/src/documentproperty.qdoc \
    3rdparty/qtxlsx/examples/xlsx/extractdata/doc/src/extractdata.qdoc \
    3rdparty/qtxlsx/examples/xlsx/formulas/doc/src/formulas.qdoc \
    3rdparty/qtxlsx/examples/xlsx/hello/doc/src/hello.qdoc \
    3rdparty/qtxlsx/examples/xlsx/mergecells/doc/src/mergecells.qdoc \
    3rdparty/qtxlsx/examples/xlsx/richtext/doc/src/richtext.qdoc \
    3rdparty/qtxlsx/examples/xlsx/style/doc/src/style.qdoc \
    3rdparty/qtxlsx/examples/xlsx/worksheetoperations/doc/src/worksheetoperations.qdoc \
    3rdparty/qtxlsx/src/xlsx/doc/src/examples.qdoc \
    3rdparty/qtxlsx/src/xlsx/doc/src/qtxlsx-index.qdoc \
    3rdparty/qtxlsx/src/xlsx/doc/src/qtxlsx.qdoc \
    3rdparty/qtxlsx/src/xlsx/doc/src/usage.qdoc
