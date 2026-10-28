#include "home_page.h"

#include <QLabel>
#include <QVBoxLayout>

HomePage::HomePage(QWidget *parent)
    : BasePage(parent) {
    auto *layout = new QVBoxLayout(this);
    auto *title = new QLabel(QStringLiteral("鲜存管家"), this);
    title->setObjectName("pageTitle");
    auto *description = new QLabel(QStringLiteral("库存概览、临期提醒和推荐入口将由成员 A 在此页面完成。"), this);
    description->setWordWrap(true);
    layout->addWidget(title);
    layout->addWidget(description);
    layout->addStretch();
}

void HomePage::refreshData() {
    // 成员 A 后续读取库存与临期数据后，在这里刷新首页。
}
