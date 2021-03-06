//
// Created by saad on 6/20/20.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include <cassert>
#include "RectType.h"

struct GridPanel {
    // helper to create a 2D vector
    using Rect      = std::pair<sf::RectangleShape, RectType>;
    using RowVector = std::vector<Rect>;
    using Idx       = std::pair<unsigned int, unsigned int>;

    // all rects in this vector will be drawn
    std::vector<RowVector> rects;

    // the previous rect mouse was hovering on
    // for outlining purposes
    sf::RectangleShape *oldRect = nullptr;

    // allow only one start and end point
    Rect *startPoint    = nullptr;
    Rect *endPoint      = nullptr;

    // old focus point
    Rect *oldFocus      = nullptr;

    // grid dimensions
    unsigned nRows, nCols;

    // size of each rect
    sf::Vector2f size;

    // the window size info
    sf::VideoMode vidMode;

    // origin of the grid
    // this acts as the (0,0)
    sf::Vector2f origin;

    // these are input from the control panel
    // these control the color of the rect which is
    // clicked
    RectType rectType = RectType::start;

    /*
     * Create a grid of specified rows and cols divided evenly in a window of size
     * windowDim and starting position origin
     */
    GridPanel(unsigned nRows, unsigned nCols, sf::VideoMode windowDim, sf::Vector2f origin = sf::Vector2f(0, 0));

    /*
     * Increase row and cols by given amount
     * put -ve values to decrease
     */
    void changeRC(unsigned deltaR, unsigned deltaC);

    /*
     * Increment cols by 1
     */
    void incCols();

    /*
     * Increment rows by 1
     */
    void incRows();

    /*
     * decrement cols by 1
     */
    void decCols();

    /*
     * decrement rows by 1
     */
    void decRows();

    /*
     * resize the rects to fit in new size.
     */
    void resize(const sf::VideoMode &newSize);

    /*
     * Draw all rects to the render window
     */
    void draw(sf::RenderWindow& window);

    /*
     * Toggle rect color against selected type in
     * the control panel
     */
    void toggleRect(Rect &rect, RectType to);

    /*
     * change rect type and color accordingly
     */
    void changeRect(Rect &rect, RectType to);

    /*
     * clear all rects who are of type path
     */
    void clearAllPaths();

    /*
     * clear all rects to space
     */
    void clearAll();

    /*
     * Handle mouse in the window
     */
    void mouseHandle(sf::RenderWindow &window);

    /*
     * Handle keyboard key release event
     */
    void kbKeyRelHandle(sf::Event &e);

    /*
     * Find the index of the rect
     */
    static Idx rectToIdx(Rect *rect);

    /*
     * return the neighbour rect
     * 0 -> north
     * 1 -> east
     * 2 -> south
     * 3 -> west
     */
    Rect* findNeighbour(Rect *src, int dir);

    /*
     * change the rect outline to cyan. And change the previous one
     * to normal
     */
    void putInFocus(Rect *rect);

    /*
     * clear the focus. Clear the rect outline
     */
    void clearFocus();
};

