#include <string>

#include "Animal.h"
#include "../sql/repo/animalsRepo.h"

class Cat: Animal {
public:
    Cat(std::string k, std::string g, std::string i, std::string u) {
        this->kind = k;
        this->genus = g;
        this->info = i;
        this->photo.setUrl(u);
    }

    std::string whatIsSay() override {
        return "Meow";
    }

    std::string writeToBd() override {
        try {
            auto db = connect("database.db");

            if (writeToDatabase(
                    db,
                    "cat",
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
private:
    class Photo {
    public:
        void setUrl(std::string& u) {
            this->url = u;
        }
        std::string getUrl() {
            return this->url;
        }

    private:
        std::string url;
    };

    Photo photo;
};