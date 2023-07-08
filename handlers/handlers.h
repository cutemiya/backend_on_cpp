#pragma once
#include <crow.h>
#include <string>

#include "../services/Cat.cpp"
#include "../services/Dog.cpp"
#include "../services/Cow.cpp"
#include "../services/Fish.cpp"
#include "../lib/libs.h"
#include "../services/GetAllAnimals.cpp"
#include "../services/DeleteAllAnimals.cpp"

crow::response catHandler(const crow::request &req);
crow::response dogHandler(const crow::request &req);
crow::response cowHandler(const crow::request &req);
crow::response fishHandler(const crow::request &req);
crow::json::wvalue getAllAnimalsHandler(const crow::request& req);
crow::response deleteAllAnimalsHandler();