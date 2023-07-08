#include "handlers.h"
#include "../mappers/mappers.h"

crow::response catHandler(const crow::request &req) {
    crow::json::rvalue res = crow::json::load(req.body);
    if (!res) {
        return crow::response(crow::status::BAD_REQUEST); // same as crow::response(400)
    }

    auto data = animalRequestMapper(res);

    if (data[1] == "none" or data[2] == "none" or data[3] == "none") {
        return crow::response(crow::status::BAD_REQUEST);
    } else {
        if (data[0] == "none") {
            Cat cat(
                    data[1],
                    data[2],
                    data[3],
                    "https://cdn1.iconfinder.com/data/icons/animals-13/100/20150728-02-512.png"
                    );

            std::function<std::string()> fn = std::bind(&Cat::writeToBd, cat);
            return cli_do(fn);
        } else {
            Cat cat(
                    data[1],
                    data[2],
                    data[3],
                    data[0]
                    );
            std::function<std::string()> fn = std::bind(&Cat::writeToBd, cat);
            return cli_do(fn);
        }
    }
}