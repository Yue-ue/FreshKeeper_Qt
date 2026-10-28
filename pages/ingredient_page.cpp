#include "ingredient_page.h"

#include <QLabel>
#include <QVBoxLayout>

IngredientPage::IngredientPage(QWidget *parent)
    : BasePage(parent) {
    auto *layout = new QVBoxLayout(this);
    auto *title = new QLabel(QStringLiteral("食材管理"), this);
    title->setObjectName("pageTitle");
    auto *description = new QLabel(QStringLiteral("成员 B 在此实现食材的新增、编辑、删除、搜索与临期判断。"), this);
    description->setWordWrap(true);
    layout->addWidget(title);
    layout->addWidget(description);
    layout->addStretch();
}

void IngredientPage::refreshData() {
    // 成员 B 后续在此刷新食材表格。
}
