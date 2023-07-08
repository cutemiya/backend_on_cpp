#include "mappers.h"

inline constexpr unsigned int stringToInt(const char* str, int h = 0) {
    return !str[h] ? 5831 : (stringToInt(str, h+1) * 33) ^ str[h];
}

std::vector<std::string> animalRequestMapper(const crow::json::rvalue& body) {
    std::vector<std::string> data{"none", "none", "none", "none"};

    for(const std::string& key: body.keys()) {
        switch (stringToInt(key.c_str())) {
            case stringToInt("url"):
                data[0] = static_cast<std::string>(body[key].s());
                break;
            case stringToInt("kind"):
                data[1] = static_cast<std::string>(body[key].s());
                break;
            case stringToInt("genus"):
                data[2] = static_cast<std::string>(body[key].s());
                break;
            case stringToInt("info"):
                data[3] = static_cast<std::string>(body[key].s());
                break;
        }
    }

    return data;
}
