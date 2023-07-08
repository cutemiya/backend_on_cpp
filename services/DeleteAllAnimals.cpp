#include "../sql/repo/animalsRepo.h"

class DeleteAllAnimals {
public:
    std::string static deleteAll() {
        try {
            auto db = connect("database.db");
            if (deleteAllAnimals(db) != "success") {
                throw DatabaseRepoException("Error deleting data on database");
            }

            return "success";
        } catch (DatabaseRepoException& error) {
            return error.getError();
        }
    }
};