#include "../sql/repo/animalsRepo.h"

class GetAllAnimals {
public:
    static auto getData(int after_id, int count) {
        auto db = connect("database.db");
        auto data = getAll(db, after_id);

        count = data.size() < count ? data.size() : count;

        return std::make_pair(count, data);
    }
};