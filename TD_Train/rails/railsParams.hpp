#pragma once 

#include "nlohmann/json.hpp"

struct RailsParams {
    float rail_size { 0.5f };
    float posRailOne { 3.f };
    float posRailTwo { 7.f };

    float balastRayons { 0.3f };
    float balastX1 { 2.f };
    float balastX2 { 8.f };

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(RailsParams, rail_size, posRailOne, posRailTwo, balastRayons, balastX1, balastX2)
};