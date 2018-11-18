QT += widgets multimedia

CONFIG += c++11

HEADERS = \
          pages/intropage.h \
          pages/kevininfopage.h \
          pages/markinfopage.h \
          pages/missioninfopage.h \
          pages/missionacceptedpage.h \
          pages/missionrejectedpage.h \
          missionwizard.h \
          settingsmanager.h

SOURCES = main.cpp \
          pages/intropage.cpp \
          pages/kevininfopage.cpp \
          pages/markinfopage.cpp \
          pages/missioninfopage.cpp \
          pages/missionacceptedpage.cpp \
          pages/missionrejectedpage.cpp \
          missionwizard.cpp \
          settingsmanager.cpp

wince* {
   DEPLOYMENT_PLUGIN += qjpeg qgif
}
