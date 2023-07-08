#include "animalsRepo.h"

AnimalsSqlConfig animalsSqlConfig;
MigrationsConfig migrationsConfig;

sqlite::database connect(const std::string &addr) {
    sqlite::database db(addr);
    db << migrationsConfig.animals_migration;
    return db;
}

std::string writeToDatabase(
        sqlite::database &db,
        const std::string &type,
        const std::string &url,
        const std::string &kind,
        const std::string &genus,
        const std::string &info,
        const std::string &say) {
    try {
        db << animalsSqlConfig.write_to_db_sql
           << type
           << url
           << kind
           << genus
           << info
           << say;

        return "success";
    } catch (const std::exception &error) {
        return error.what();
    }
}

int getAnimalsCount(sqlite::database &db, int after_id) {
    int count;
    db << animalsSqlConfig.get_animals_count_sql
       << after_id
       >> count;
    return count;
}

std::vector<std::pair<std::vector<std::string>, int>> getAll(sqlite::database &db, int after_id) {
    std::vector<std::pair<std::vector<std::string>, int>> data;
    int id = after_id;

    db << animalsSqlConfig.get_all_animals_sql
       << id
       >> [&](
               int _id,
               const std::string &type,
               const std::string &url,
               const std::string &kind,
               const std::string &genus,
               const std::string &info,
               const std::string &say
       ) {
           std::vector<std::string> row{type, url, kind, genus, info, say};
           data.emplace_back(std::make_pair(row, _id));
           id = _id;
       };

    return data;
}

std::string deleteAllAnimals(sqlite::database &db) {
    try {
        db << animalsSqlConfig.delete_all_animals_sql;
        return "success";
    } catch (std::exception &error) {
        return error.what();
    }
}








