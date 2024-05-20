include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread


SOURCES += \
        main.cpp         tst_test_sets.cpp \
        tst_testplace_sets.cpp
