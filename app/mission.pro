QT += widgets multimedia

CONFIG += c++11

HEADERS = \
          intropage.h \
          kevininfopage.h \
          markinfopage.h \
          missioninfopage.h \
          missionwizard.h \
          settingsmanager.h \
    missionacceptedpage.h \
    missionrejectedpage.h

SOURCES = main.cpp \
          intropage.cpp \
          kevininfopage.cpp \
          markinfopage.cpp \
          missioninfopage.cpp \
          missionwizard.cpp \
          settingsmanager.cpp \
    missionacceptedpage.cpp \
    missionrejectedpage.cpp

wince* {
   DEPLOYMENT_PLUGIN += qjpeg qgif
}
