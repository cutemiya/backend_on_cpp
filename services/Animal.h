#pragma once

#include <string>
#include <vector>

class Animal {
public:
    Animal() = default;
    ~Animal() = default;

    virtual std::string whatIsSay() = 0;
    virtual std::string writeToBd() = 0;
protected:
    std::string kind;
    std::string info;
    std::string genus;

    std::vector<std::string> data{kind, info, genus};

    // composition class
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


