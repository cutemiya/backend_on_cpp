cmake_minimum_required(VERSION 3.16)
project(backend)

add_subdirectory(Crow)
set(CMAKE_CXX_STANDARD 17)

add_executable(backend main.cpp services/Animal.h services/Cat.cpp services/Dog.cpp services/Cow.cpp services/Fish.cpp mappers/animalRequestMapper.cpp services/GetAllAnimals.cpp sql/migrations/animals_migration.h handlers/cat_handler.cpp handlers/dog_handler.cpp handlers/cow_handler.cpp handlers/fish_handler.cpp sql/repo/animals_repo.cpp sql/repo/DatabaseRepoException.cpp sql/other_sql/animal_sqls.h lib/animals_lib.cpp handlers/get_all_animals_handler.cpp sql/repo/animalsRepo.h handlers/handlers.h lib/libs.h services/DeleteAllAnimals.cpp handlers/delete_all_animals_handler.cpp mappers/catalogMapper.cpp mappers/mappers.h)
target_link_libraries(backend PUBLIC Crow::Crow)
include_directories(/usr/include)
link_directories(/usr/lib)
target_link_libraries(backend PRIVATE sqlite3)