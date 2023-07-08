#pragma once
#include "../sqlite_modern_cpp/hdr/sqlite_modern_cpp.h"

#include "../migrations/animals_migration.h"
#include "../other_sql/animal_sqls.h"

class DatabaseRepoException: std::exception {
private:
    std::string resultError;
public:
    explicit DatabaseRepoException(std::string error): resultError{std::move( error )} {}

    [[nodiscard]] const char* getError() const;
};

sqlite::database connect(const std::string &addr);
std::string writeToDatabase(
        sqlite::database &db,
        const std::string &type,
        const std::string &url,
        const std::string &kind,
        const std::string &genus,
        const std::string &info,
        const std::string &say);
int getAnimalsCount(sqlite::database& db, int);
std::vector<std::pair<std::vector<std::string>, int>> getAll(sqlite::database &, int);
std::string deleteAllAnimals(sqlite::database& db);