#pragma once

#include "base_page.h"

class RecordPage : public BasePage {
    Q_OBJECT

public:
    explicit RecordPage(QWidget *parent = nullptr);
    void refreshData() override;
};
