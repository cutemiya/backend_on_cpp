#include "handlers.h"

crow::response deleteAllAnimalsHandler() {
    return cli_do(DeleteAllAnimals::deleteAll);
}