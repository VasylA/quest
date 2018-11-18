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
          mainwindow.h \
          widgets/introwidget.h \
          widgets/kevininfowidget.h \
          widgets/markinfowidget.h \
          widgets/missioninfowidget.h \
          widgets/missionacceptedwidget.h \
          widgets/missionrejectedwidget.h \
          settingsmanager.h

SOURCES = main.cpp \
          pages/intropage.cpp \
          pages/kevininfopage.cpp \
          pages/markinfopage.cpp \
          pages/missioninfopage.cpp \
          pages/missionacceptedpage.cpp \
          pages/missionrejectedpage.cpp \
          missionwizard.cpp \
          mainwindow.cpp \
          widgets/introwidget.cpp \
          widgets/kevininfowidget.cpp \
          widgets/markinfowidget.cpp \
          widgets/missioninfowidget.cpp \
          widgets/missionacceptedwidget.cpp \
          widgets/missionrejectedwidget.cpp \
          settingsmanager.cpp

wince* {
   DEPLOYMENT_PLUGIN += qjpeg qgif
}
