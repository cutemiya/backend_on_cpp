#include "mappers.h"

std::pair<int, int> catalogMapper(const crow::request& req) {
    int after_id = 0, count = 20;

    if (req.url_params.get("count") != nullptr) count = crow::utility::lexical_cast<int>(req.url_params.get("count"));
    if (req.url_params.get("after_id") != nullptr) after_id = crow::utility::lexical_cast<int>(req.url_params.get("after_id"));

    return std::make_pair(after_id, count);
}