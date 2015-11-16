purge.commands = rm -f *~ && rm -f */*~

CONFIG		+= qt release warn_on
mac {
CONFIG          += app_bundle
}
DEFINES		+=
LANGUAGE	= C++
QT		+= gui
TEMPLATE	= app

QMAKE_CLEAN	+= Joker
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -fPIE -fstack-protector-all -fwrapv \
                          -mtune=generic -pie -O3 \
                          -Wall -Wcast-align -Wcast-qual \
                          -Werror -Wextra \
                          -Woverloaded-virtual -Wpointer-arith \
                          -Wstack-protector -Wstrict-overflow=5
QMAKE_DISTCLEAN += -r temp
QMAKE_EXTRA_TARGETS = purge
QMAKE_STRIP	= echo

ICON		=
INCLUDEPATH	+= Include
LIBS		+=
RESOURCES	=

MOC_DIR = temp/moc
OBJECTS_DIR = temp/obj
RCC_DIR = temp/rcc
UI_DIR = temp/ui

FORMS           = UI\\joker.ui

UI_HEADERS_DIR  = Include

HEADERS		= Include\\joker.h

SOURCES		= Source\\joker.cc \
                  Source\\joker_card.cc \
		  Source\\joker_deck.cc \
		  Source\\joker_game.cc \
                  Source\\main.cc

TRANSLATIONS    =

PROJECTNAME	= Joker
TARGET		= Joker

mac {
joker.path	  = /Applications/Joker.d/Joker.app
joker.files	  = Joker.app/*
macdeployqt.path  = ./Joker.app
macdeployqt.extra = $$[QT_INSTALL_BINS]/macdeployqt ./Joker.app

INSTALLS	= macdeployqt \
                  joker
}

unix {
joker.path      = /usr/local/bin
joker.files     = Joker

INSTALLS        = joker
}
