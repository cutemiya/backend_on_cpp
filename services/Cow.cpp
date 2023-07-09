#include "Animal.h"
#include "../sql/repo/animalsRepo.h"

class Cow: Animal {
public:
    Cow(std::string k, std::string g, std::string i, std::string u) {
        this->kind = std::move(k);
        this->genus = std::move(g);
        this->info = std::move(i);
        this->photo.setUrl(u);
    }

    std::string whatIsSay() override {
        return "Moo-moo";
    }

    std::string writeToBd() override {
        try {
            auto db = connect("database.db");

            if (writeToDatabase(
                    db,
                    "cow",
                    this->photo.getUrl(),
                    this->kind,
                    this->genus,
                    this->info,
                    this->whatIsSay()) != "success") {
                throw DatabaseRepoException("Error writing to the database");
            }

            return "success";
        }
        catch (const DatabaseRepoException& error) {
            return error.getError();
        }
    }
};