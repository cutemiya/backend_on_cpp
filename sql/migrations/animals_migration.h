#pragma once
#include <string>

struct MigrationsConfig {
    std::string animals_migration =
            "create table if not exists animals("
            "_id            integer primary key autoincrement not null,"
            "type           text, "
            "url            text, "
            "kind           text, "
            "genus          text, "
            "info           text, "
            "say            text);";
};