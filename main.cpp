#include <QApplication>
#include <QMessageBox>

#include "database/database_manager.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationName(QStringLiteral("鲜存管家"));
    app.setOrganizationName(QStringLiteral("FreshKeeperTeam"));

    if (!DatabaseManager::initialize()) {
        QMessageBox::critical(nullptr,
                              QStringLiteral("数据库初始化失败"),
                              DatabaseManager::lastError());
        return 1;
    }

    MainWindow window;
    window.show();
    return app.exec();
}
