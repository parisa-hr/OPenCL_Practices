######################################################################
# Automatically generated by qmake (3.1) Mon Sep 25 13:41:53 2023
######################################################################

TEMPLATE = app
TARGET = OCL_19_1
INCLUDEPATH += .

INCLUDEPATH +=/usr/include/CL

LIBS +=-lOpenCL

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += SimpleOpenCL/utility.h
SOURCES += \
            SimpleOpenCL/utility.cpp \
#           SimpleOpenCL/utility.cpp \
           Solutions/Ex1/main_solution_ex1.cpp
#           Solutions/Ex2/main_solution_ex2.cpp \
#           Solutions/Ex3/main_solution_ex3.cpp
#SimpleOpenCL/main.cpp \
