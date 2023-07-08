#include "animalsRepo.h"

[[nodiscard]] const char* DatabaseRepoException::getError() const {
    return resultError.c_str();
}