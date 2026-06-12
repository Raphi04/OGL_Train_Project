#pragma once

#include "../cow/cow.hpp"
#include "../rails/railsParams.hpp"
#include "nlohmann/json.hpp"

#include <vector>

struct JSON {
    int grid_width;
    int grid_height;
    std::array<int, 2> train;
    std::array<int, 3> gare;
    std::vector<std::array<int, 2>> path;
    std::vector<std::array<int, 3>> cows;

    RailsParams railsParams;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(JSON, grid_width, grid_height, train, gare, path, cows, railsParams)
};