#-------------------------------------------------
#
# Project created by QtCreator 2019-02-25T00:34:33
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SAPDRAW
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS \

INCLUDEPATH +=  \
/usr/local/Cellar/oce/0.18.2/include/oce

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    view.cpp \
    divideline_dialog.cpp \
    axesdialog.cpp \
    occ_helper_functions.cpp \
    profilesdialog.cpp

HEADERS += \
        mainwindow.h \
    view.h \
    divideline_dialog.h \
    axesdialog.h \
    occ_helper_functions.h \
    profilesdialog.h

FORMS += \
        mainwindow.ui \
    divideline_dialog.ui \
    axesdialog.ui \
    profilesdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


DEPENDPATH += /usr/local/Cellar/oce/0.18.2/lib

LIBS +=         \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKBin                     \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKBinL                    \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKBinTObj                 \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKBinXCAF                 \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKBO                      \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKBool                    \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKBRep                    \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKCAF                     \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKCDF                     \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKernel                   \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKFeat                    \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKFillet                  \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKG2d                     \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKG3d                     \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKGeomAlgo                \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKGeomBase                \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKHLR                     \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKIGES                    \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKLCAF                    \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKMath                    \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKMesh                    \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKMeshVS                  \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKOffset                  \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKOpenGl                  \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKPrim                    \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKService                 \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKShHealing               \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKSTEP                    \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKSTEP209                 \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKSTEPAttr                \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKSTEPBase                \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKSTL                     \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKTObj                    \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKTopAlgo                 \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKV3d                     \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKVRML                    \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKXCAF                    \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKXDEIGES                 \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKXDESTEP                 \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKXMesh                   \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKXml                     \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKXmlL                    \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKXmlTObj                 \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKXmlXCAF                 \
  -L"/usr/local/Cellar/oce/0.18.2/lib"  -lTKXSBase                  \

RESOURCES += \
    resources.qrc

