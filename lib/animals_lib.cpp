#include "libs.h"

crow::response cli_do(const std::function<std::string()>& do_function) {
    std::string status = do_function();

    if (status == "success") {
        return crow::response{crow::json::wvalue({{"status", "200"}, {"message", status}})};
    } else {
        return crow::response{crow::json::wvalue({{"status", "400"}, {"message", status}})};
    }
}



