#pragma once

#include <QMainWindow>

class QButtonGroup;
class QStackedWidget;
class HomePage;
class IngredientPage;
class RecipePage;
class RecordPage;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void refreshAllPages();

private:
    void buildUi();
    void switchToPage(int index);

    QStackedWidget *m_pageStack = nullptr;
    QButtonGroup *m_navigationGroup = nullptr;
    HomePage *m_homePage = nullptr;
    IngredientPage *m_ingredientPage = nullptr;
    RecipePage *m_recipePage = nullptr;
    RecordPage *m_recordPage = nullptr;
};
