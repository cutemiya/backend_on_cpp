#pragma once

#include <crow.h>

crow::response cli_do(const std::function<std::string()>& do_function);