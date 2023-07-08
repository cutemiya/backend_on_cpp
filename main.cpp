#include "crow.h"
#include "handlers/handlers.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/cat").methods("POST"_method)(catHandler);
    CROW_ROUTE(app, "/dog").methods("POST"_method)(dogHandler);
    CROW_ROUTE(app, "/cow").methods("POST"_method)(cowHandler);
    CROW_ROUTE(app, "/fish").methods("POST"_method)(fishHandler);
    CROW_ROUTE(app, "/catalog")(getAllAnimalsHandler);
    CROW_ROUTE(app, "/catalog/delete")(deleteAllAnimalsHandler);

    app.port(18080).multithreaded().run();
}