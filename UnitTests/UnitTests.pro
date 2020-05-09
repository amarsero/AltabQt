QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_serialization.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Altab/release/ -lAltab
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Altab/debug/ -lAltab
else:unix: LIBS += -L$$OUT_PWD/../Altab/ -lAltab

INCLUDEPATH += $$PWD/../Altab
DEPENDPATH += $$PWD/../Altab

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Altab/release/libAltab.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Altab/debug/libAltab.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Altab/release/Altab.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Altab/debug/Altab.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Altab/libAltab.a
