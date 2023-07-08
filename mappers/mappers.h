#pragma once

#include <vector>
#include <string>

#include "crow.h"

std::vector<std::string> animalRequestMapper(const crow::json::rvalue& body);
std::pair<int, int> catalogMapper(const crow::request& req);