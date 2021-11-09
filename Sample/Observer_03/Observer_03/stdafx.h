#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "MiniEngine.h"

constexpr float MAP_SIZE_X = 2000.0f;
constexpr float MAP_SIZE_Z = 1900.0f;
constexpr float GRID_SIZE = 100.0f;
constexpr int NUM_GRID_X = static_cast<int>(MAP_SIZE_X / GRID_SIZE);
constexpr int NUM_GRID_Z = static_cast<int>(MAP_SIZE_Z / GRID_SIZE);