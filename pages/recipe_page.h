#pragma once

#include "base_page.h"

class RecipePage : public BasePage {
    Q_OBJECT

public:
    explicit RecipePage(QWidget *parent = nullptr);
    void refreshData() override;
};
