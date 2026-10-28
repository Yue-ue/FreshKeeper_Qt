#pragma once

#include <QDate>
#include <QDateTime>
#include <QString>

struct Ingredient {
    int id = -1;
    QString name;
    QString category;
    double quantity = 0.0;
    QString unit;
    QDate expiryDate;
};

struct Recipe {
    int id = -1;
    QString name;
    QString description;
    QString steps;
};

struct RecipeItem {
    int id = -1;
    int recipeId = -1;
    QString ingredientName;
    double requiredQuantity = 0.0;
};

struct ConsumptionRecord {
    int id = -1;
    int ingredientId = -1;
    QString ingredientName;
    double quantity = 0.0;
    QString unit;
    QString type;
    QDateTime recordTime;
};
