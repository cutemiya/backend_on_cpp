#include "Animal.h"
#include "../sql/repo/animalsRepo.h"

class Dog: Animal {
public:
    Dog(std::string k, std::string g, std::string i, std::string u) {
        this->kind = std::move(k);
        this->genus = std::move(g);
        this->info = std::move(i);
        this->photo.setUrl(u);
    }

    std::string whatIsSay() override {
        return "Gaw-gaw";
    }

    std::string writeToBd() override {
        try {
            auto db = connect("database.db");

            if (writeToDatabase(
                    db,
                    "dog",
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