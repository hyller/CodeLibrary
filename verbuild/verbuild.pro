#-------------------------------------------------
#
# Project created by QtCreator 2013-05-29T00:18:44
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = verbuild
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += Settings.cpp \
    main.cpp

HEADERS += \
    VersionInfo.hpp \
    version.hpp \
    CFormatter.hpp \
    Formatter.hpp \
    Settings.hpp \
    tclap/ZshCompletionOutput.h \
    tclap/XorHandler.h \
    tclap/Visitor.h \
    tclap/VersionVisitor.h \
    tclap/ValuesConstraint.h \
    tclap/ValueArg.h \
    tclap/UnlabeledValueArg.h \
    tclap/UnlabeledMultiArg.h \
    tclap/SwitchArg.h \
    tclap/StdOutput.h \
    tclap/StandardTraits.h \
    tclap/OptionalUnlabeledTracker.h \
    tclap/MultiSwitchArg.h \
    tclap/MultiArg.h \
    tclap/IgnoreRestVisitor.h \
    tclap/HelpVisitor.h \
    tclap/DocBookOutput.h \
    tclap/Constraint.h \
    tclap/CmdLineOutput.h \
    tclap/CmdLineInterface.h \
    tclap/CmdLine.h \
    tclap/ArgTraits.h \
    tclap/ArgException.h \
    tclap/Arg.h \
    Enums.hpp

INCLUDEPATH += .
