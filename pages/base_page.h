#pragma once

#include <QWidget>

class BasePage : public QWidget {
    Q_OBJECT

public:
    explicit BasePage(QWidget *parent = nullptr);
    virtual void refreshData();
};
