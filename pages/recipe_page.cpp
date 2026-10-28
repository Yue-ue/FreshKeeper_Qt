#include "recipe_page.h"

#include <QLabel>
#include <QVBoxLayout>

RecipePage::RecipePage(QWidget *parent)
    : BasePage(parent) {
    auto *layout = new QVBoxLayout(this);
    auto *title = new QLabel(QStringLiteral("菜谱推荐"), this);
    title->setObjectName("pageTitle");
    auto *description = new QLabel(QStringLiteral("成员 C 在此实现库存匹配和临期食材优先推荐。"), this);
    description->setWordWrap(true);
    layout->addWidget(title);
    layout->addWidget(description);
    layout->addStretch();
}

void RecipePage::refreshData() {
    // 成员 C 后续在此刷新菜谱推荐结果。
}
