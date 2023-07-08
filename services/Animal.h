#pragma once

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
};


