cmake_minimum_required(VERSION 3.13)

if(${CMAKE_VERSION} VERSION_LESS 3.13)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(TestLinx VERSION 1.0
                 DESCRIPTION "Backend Engineer Test for Linx."
                 LANGUAGES CXX)


find_package(Boost 1.65 REQUIRED)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(3rdparty/json EXCLUDE_FROM_ALL)

add_executable(processador src/main.cpp src/Utils.hpp
                           src/InvertedIndex.cpp src/InvertedIndex.hpp
                           src/Similarity.hpp src/Product.hpp
                           src/ProductList.cpp src/ProductList.hpp)

target_compile_features(processador PUBLIC cxx_std_17)

target_link_libraries(processador PRIVATE nlohmann_json::nlohmann_json
                                          Boost::boost
                                          readline)
