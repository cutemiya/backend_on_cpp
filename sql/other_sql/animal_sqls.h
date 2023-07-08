#pragma once
#include <string>

struct AnimalsSqlConfig {
    std::string write_to_db_sql = "insert into animals (type,url,kind,genus,info,say) values (?,?,?,?,?,?);";
    std::string get_all_animals_sql = "select * from animals where _id > ? ;";
    std::string get_animals_count_sql = "select count(*) from animals where _id > ?;";
    std::string delete_all_animals_sql = "drop table animals;";
};