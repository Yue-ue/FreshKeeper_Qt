QT += widgets sql

CONFIG += c++17 warn_on
TEMPLATE = app
TARGET = FreshKeeper

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    database/database_manager.cpp \
    pages/base_page.cpp \
    pages/home_page.cpp \
    pages/ingredient_page.cpp \
    pages/recipe_page.cpp \
    pages/record_page.cpp

HEADERS += \
    mainwindow.h \
    database/database_manager.h \
    database/models.h \
    pages/base_page.h \
    pages/home_page.h \
    pages/ingredient_page.h \
    pages/recipe_page.h \
    pages/record_page.h

