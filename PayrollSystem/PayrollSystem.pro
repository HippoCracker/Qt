#-------------------------------------------------
#
# Project created by QtCreator 2015-11-30T12:33:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PayrollSystem
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    person.cpp \
    employee.cpp \
    student.cpp \
    teacher.cpp \
    employeedirectory.cpp \
    useraccount.cpp \
    payroll.cpp \
    payrolldirectory.cpp \
    role.cpp \
    employeerole.cpp \
    adminrole.cpp \
    adminwindow.cpp \
    viewemployeedialog.cpp \
    exportdirectorydialog.cpp \
    employeewindow.cpp \
    logindialog.cpp

HEADERS  += mainwindow.h \
    person.h \
    employee.h \
    student.h \
    teacher.h \
    employeedirectory.h \
    useraccount.h \
    payroll.h \
    payrolldirectory.h \
    role.h \
    employeerole.h \
    adminrole.h \
    adminwindow.h \
    viewemployeedialog.h \
    exportdirectorydialog.h \
    employeewindow.h \
    logindialog.h

FORMS    += mainwindow.ui \
    adminwindow.ui \
    viewemployeedialog.ui \
    exportdirectorydialog.ui \
    employeewindow.ui \
    logindialog.ui
