#include "handlers.h"
#include "../mappers/mappers.h"

crow::json::wvalue getAllAnimalsHandler(const crow::request& req) {
    std::pair<int, int> params = catalogMapper(req);

    auto data = GetAllAnimals::getData(params.first, params.second);
    crow::json::wvalue res;
    res["count"] = data.first;

    for(int i = 0; i < data.first; i++) {
        auto row = data.second[i];
        res[std::to_string(row.second)] = row.first;
    }

    return res;
}