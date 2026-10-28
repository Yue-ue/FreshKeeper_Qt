#pragma once

#include "base_page.h"

class HomePage : public BasePage {
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    void refreshData() override;
};
