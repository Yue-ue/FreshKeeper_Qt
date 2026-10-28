#include "mainwindow.h"

#include <QButtonGroup>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "pages/home_page.h"
#include "pages/ingredient_page.h"
#include "pages/recipe_page.h"
#include "pages/record_page.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    buildUi();
    switchToPage(0);
    refreshAllPages();
}

void MainWindow::buildUi() {
    setWindowTitle(QStringLiteral("鲜存管家"));
    resize(1120, 720);
    setMinimumSize(900, 560);

    auto *central = new QWidget(this);
    auto *rootLayout = new QHBoxLayout(central);
    rootLayout->setContentsMargins(0, 0, 0, 0);
    rootLayout->setSpacing(0);

    auto *sideBar = new QFrame(central);
    sideBar->setObjectName("sideBar");
    sideBar->setFixedWidth(210);
    auto *sideLayout = new QVBoxLayout(sideBar);
    sideLayout->setContentsMargins(18, 24, 18, 18);
    sideLayout->setSpacing(10);

    auto *appName = new QLabel(QStringLiteral("鲜存管家"), sideBar);
    appName->setObjectName("appName");
    auto *appSubtitle = new QLabel(QStringLiteral("食材管理与反浪费助手"), sideBar);
    appSubtitle->setObjectName("appSubtitle");
    sideLayout->addWidget(appName);
    sideLayout->addWidget(appSubtitle);
    sideLayout->addSpacing(20);

    m_navigationGroup = new QButtonGroup(this);
    m_navigationGroup->setExclusive(true);
    const QStringList labels = {QStringLiteral("首页"), QStringLiteral("食材管理"),
                                QStringLiteral("菜谱推荐"), QStringLiteral("消耗记录")};
    for (int i = 0; i < labels.size(); ++i) {
        auto *button = new QPushButton(labels.at(i), sideBar);
        button->setObjectName("navButton");
        button->setCheckable(true);
        button->setMinimumHeight(42);
        m_navigationGroup->addButton(button, i);
        sideLayout->addWidget(button);
    }
    sideLayout->addStretch();
    auto *offlineHint = new QLabel(QStringLiteral("本地离线运行"), sideBar);
    offlineHint->setObjectName("offlineHint");
    sideLayout->addWidget(offlineHint);

    m_pageStack = new QStackedWidget(central);
    m_pageStack->setObjectName("pageStack");
    m_homePage = new HomePage(m_pageStack);
    m_ingredientPage = new IngredientPage(m_pageStack);
    m_recipePage = new RecipePage(m_pageStack);
    m_recordPage = new RecordPage(m_pageStack);
    m_pageStack->addWidget(m_homePage);
    m_pageStack->addWidget(m_ingredientPage);
    m_pageStack->addWidget(m_recipePage);
    m_pageStack->addWidget(m_recordPage);

    rootLayout->addWidget(sideBar);
    rootLayout->addWidget(m_pageStack, 1);
    setCentralWidget(central);

    connect(m_navigationGroup, &QButtonGroup::idClicked, this, &MainWindow::switchToPage);
    setStyleSheet(R"(
        QMainWindow { background: #f6f8f7; }
        #sideBar { background: #175c4b; }
        #appName { color: white; font-size: 23px; font-weight: 700; }
        #appSubtitle, #offlineHint { color: #cce2db; font-size: 12px; }
        #navButton { background: transparent; color: #eaf5f1; border: none; border-radius: 8px;
                     padding: 0 14px; text-align: left; font-size: 15px; }
        #navButton:hover { background: #28725f; }
        #navButton:checked { background: #f1b85b; color: #18382f; font-weight: 700; }
        #pageStack { background: white; margin: 18px; border-radius: 12px; }
        #pageTitle { color: #175c4b; font-size: 28px; font-weight: 700; }
    )");
}

void MainWindow::switchToPage(int index) {
    if (index < 0 || index >= m_pageStack->count()) {
        return;
    }
    m_pageStack->setCurrentIndex(index);
    if (auto *button = m_navigationGroup->button(index)) {
        button->setChecked(true);
    }
}

void MainWindow::refreshAllPages() {
    m_homePage->refreshData();
    m_ingredientPage->refreshData();
    m_recipePage->refreshData();
    m_recordPage->refreshData();
}
