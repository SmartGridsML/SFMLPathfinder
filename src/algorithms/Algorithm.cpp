//
// Created by saad on 6/22/20.
//

#include "Algorithm.h"
#include <chrono>


// too big to type
inline auto now() {
    return std::chrono::high_resolution_clock::now();
}

template <class Time>
inline auto microseconds(Time then, Time now) {
    return std::chrono::duration_cast<std::chrono::microseconds>(now - then).count();
}

bool Algorithm::checkGrid(GridPanel &grid) {
    grid.clearAllPaths();
    beg = grid.startPoint;
    end = grid.endPoint;

    return !(beg == nullptr || end == nullptr);
}

bool Algorithm::runComplete(GridPanel &grid) {
    auto then = now();
    if (!init(grid))
        return false;

    while (!step(grid));
    bool ret = postRun(grid);
    timeUs = microseconds(then, now());

    return ret;
}

bool Algorithm::step(GridPanel &grid) {
    tiles++;
    return stepRun(grid);
}

bool Algorithm::init(GridPanel &grid) {
    tiles = 0;
    timeUs = 0;
    return preRun(grid);
}

Algorithm::~Algorithm() = default;

