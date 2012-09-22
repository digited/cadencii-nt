#-------------------------------------------------
#
# Project created by QtCreator 2012-01-15T14:31:31
#
#-------------------------------------------------

QT       += core gui

TARGET = Cadencii
TEMPLATE = app


SOURCES += main.cpp\
    qt/gui/WindowMainView.cpp \
    Controller.cpp \
    qt/gui/EditorWidgetBase.cpp \
    qt/gui/EditorWidgetBaseMainContent.cpp \
    qt/gui/EditorWidgetBaseSubContent.cpp \
    qt/gui/CurveControlChangeView.cpp \
    qt/gui/PianorollTrackView.cpp \
    qt/gui/ConcreteBarCountView.cpp \
    qt/gui/ConcreteTempoView.cpp \
    qt/gui/ConcreteTimesigView.cpp \
    Settings.cpp

HEADERS  += \
    gui/TrackView.hpp \
    qt/gui/WindowMainView.hpp \
    gui/MainView.hpp \
    Controller.hpp \
    ControllerAdapter.hpp \
    ControlChangeView.hpp \
    qt/gui/EditorWidgetBase.hpp \
    qt/gui/EditorWidgetBaseMainContent.hpp \
    qt/gui/EditorWidgetBaseSubContent.hpp \
    qt/gui/CurveControlChangeView.hpp \
    qt/gui/PianorollTrackView.hpp \
    gui/BarCountView.hpp \
    qt/gui/ConcreteBarCountView.hpp \
    gui/TempoView.hpp \
    qt/gui/ConcreteTempoView.hpp \
    gui/TimesigView.hpp \
    qt/gui/ConcreteTimesigView.hpp \
    enum/QuantizeMode.hpp \
    Settings.hpp

FORMS    += \
    qt/gui/WindowMainView.ui \
    qt/gui/EditorWidgetBase.ui

OTHER_FILES +=

RESOURCES += \
    qt/Cadencii.qrc

mac {
    ICON = resource/icon.icns
}
