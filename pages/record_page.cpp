#include "record_page.h"

#include <QLabel>
#include <QVBoxLayout>

RecordPage::RecordPage(QWidget *parent)
    : BasePage(parent) {
    auto *layout = new QVBoxLayout(this);
    auto *title = new QLabel(QStringLiteral("消耗记录"), this);
    title->setObjectName("pageTitle");
    auto *description = new QLabel(QStringLiteral("成员 C 在此实现正常消耗、丢弃记录及月度统计。"), this);
    description->setWordWrap(true);
    layout->addWidget(title);
    layout->addWidget(description);
    layout->addStretch();
}

void RecordPage::refreshData() {
    // 成员 C 后续在此刷新消耗记录与统计信息。
}
