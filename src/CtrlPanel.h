//
// Created by saad on 6/20/20.
//

#ifndef SFMLPATHFINDER_CTRLPANEL_H
#define SFMLPATHFINDER_CTRLPANEL_H

#include <string>
#include <iostream>
#include <imgui-SFML.h>
#include <imgui.h>
#include "GridPanel.h"
#include "RectType.h"

struct CtrlPanel {
    // the associated grid
    GridPanel& grid;

    // the font to use
    ImFont *font = nullptr;

    // the size and pos of panel
    // in the window
    ImVec2 size, pos;

    CtrlPanel(GridPanel &grid, ImVec2 size, ImVec2 pos);

    /*
     * setup the ImGui backend
     */
    void init(sf::RenderWindow &window, const char *fileName, bool lightTheme = true);

    /*
     * update states
     */
    void loop(sf::Time clockTime, sf::RenderWindow &window) const;

    /*
     * draw
     */
    static void draw(sf::RenderWindow &window) ;
};


#endif //SFMLPATHFINDER_CTRLPANEL_H
