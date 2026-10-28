#pragma once

#include "base_page.h"

class IngredientPage : public BasePage {
    Q_OBJECT

public:
    explicit IngredientPage(QWidget *parent = nullptr);
    void refreshData() override;
};
