#include "database_manager.h"

#include <QDir>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>

QString DatabaseManager::s_lastError;
QString DatabaseManager::s_databasePath;

bool DatabaseManager::initialize() {
    constexpr auto connectionName = "fresh_keeper_connection";

    if (QSqlDatabase::contains(connectionName)) {
        return createTables();
    }

    const QString appDataDirectory =
        QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (!QDir().mkpath(appDataDirectory)) {
        s_lastError = QStringLiteral("无法创建应用数据目录：%1").arg(appDataDirectory);
        return false;
    }

    s_databasePath = QDir(appDataDirectory).filePath("fresh_keeper.db");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    db.setDatabaseName(s_databasePath);

    if (!db.open()) {
        s_lastError = db.lastError().text();
        return false;
    }

    return createTables();
}

QSqlDatabase DatabaseManager::database() {
    return QSqlDatabase::database("fresh_keeper_connection");
}

QString DatabaseManager::lastError() {
    return s_lastError;
}

QString DatabaseManager::databasePath() {
    return s_databasePath;
}

bool DatabaseManager::createTables() {
    const QStringList statements = {
        "CREATE TABLE IF NOT EXISTS ingredients ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, category TEXT NOT NULL, "
        "quantity REAL NOT NULL CHECK(quantity >= 0), "
        "unit TEXT NOT NULL, expiry_date TEXT NOT NULL)",

        "CREATE TABLE IF NOT EXISTS recipes ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, description TEXT, steps TEXT)",

        "CREATE TABLE IF NOT EXISTS recipe_items ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "recipe_id INTEGER NOT NULL, ingredient_name TEXT NOT NULL, "
        "required_quantity REAL NOT NULL CHECK(required_quantity > 0), "
        "FOREIGN KEY(recipe_id) REFERENCES recipes(id) ON DELETE CASCADE)",

        "CREATE TABLE IF NOT EXISTS consumption_records ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "ingredient_id INTEGER NOT NULL, ingredient_name TEXT NOT NULL, "
        "quantity REAL NOT NULL CHECK(quantity > 0), unit TEXT NOT NULL, "
        "type TEXT NOT NULL CHECK(type IN ('正常消耗', '丢弃')), "
        "record_time TEXT NOT NULL, "
        "FOREIGN KEY(ingredient_id) REFERENCES ingredients(id))"
    };

    QSqlQuery query(database());
    for (const QString &statement : statements) {
        if (!query.exec(statement)) {
            s_lastError = query.lastError().text();
            return false;
        }
    }
    return true;
}
