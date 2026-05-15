#pragma once

#include "nlohmann/json.hpp"
#include "../rails/railsParams.hpp"

#include <vector>

struct JSON {
    int grid_width;
    int grid_height;
    int origin;
    std::vector<std::array<int, 2>> path;

    RailsParams railsParams;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(JSON, grid_width, grid_height, origin, path, railsParams)
};