#pragma once

#include <QSqlDatabase>
#include <QString>

class DatabaseManager {
public:
    static bool initialize();
    static QSqlDatabase database();
    static QString lastError();
    static QString databasePath();

private:
    static bool createTables();
    static QString s_lastError;
    static QString s_databasePath;
};
