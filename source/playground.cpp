/**
********************************************************************************
* @file         playground.cpp
* @brief        RPS playground class implementation
* @author       Maksym Koshel (maks.koshel@gmail.com)
* @date         Sep 02, 2017
********************************************************************************
*/

// Include header
#include "playground.h"

// Global includes
#include <iostream>

// Local includes
#include "player.h"

/*
********************************************************************************
*
********************************************************************************
*/
Playground::Playground(int number)
    : m_nog(number)
{

}

/*
********************************************************************************
*
********************************************************************************
*/
Playground::~Playground()
{

}

/**
********************************************************************************
* @brief        Source table RSP results which in simple words can be resulted
*               into followig formulas:
*               P1 = !x2!x1x0!y2y1!y0 + !x2x1!x0y2!y1!y0 + x2!x1!x0!y2!y1y0
*               P2 = !x2!x1x0y2!y1!y0 + !x2x1!x0!y2!y1y0 + x2!x1!x0!y2y1!y0
*               T  = !x2!x1x0!y2!y1y0 + !x2x1!x0!y2y1!y0 + x2!x1!x0y2!y1!y0
* @details      Source table below represents possible combinations of 2 users
*               marked by x signals (Player 1) and y signals(Player 2), where
*               outputs shown as 1, 2, T (1 - Player 1, 2 - Player 2, T - Tie).
*               Bit indexes (0 - Rock, 1 - Scisors, 2 - Paper):
*                    P  S  R  P  S  R
*                   x2 x1 x0 y2 y1 y0| 1 2 T
*                   0  0  0  0  0  0 | - - -
*                   0  0  0  0  0  1 | - - -
*                   0  0  0  0  1  0 | - - -
*                   0  0  0  0  1  1 | - - -
*                   0  0  0  1  0  0 | - - -
*                   0  0  0  1  0  1 | - - -
*                   0  0  0  1  1  0 | - - -
*                   0  0  0  1  1  1 | - - -
*                   0  0  1  0  0  0 | - - -
*                   0  0  1  0  0  1 | 0 0 1
*                   0  0  1  0  1  0 | 1 0 0
*                   0  0  1  0  1  1 | - - -
*                   0  0  1  1  0  0 | 0 1 0
*                   0  0  1  1  0  1 | - - -
*                   0  0  1  1  1  0 | - - -
*                   0  0  1  1  1  1 | - - -
*                   0  1  0  0  0  0 | - - -
*                   0  1  0  0  0  1 | 0 1 0
*                   0  1  0  0  1  0 | 0 0 1
*                   0  1  0  0  1  1 | - - -
*                   0  1  0  1  0  0 | 1 0 0
*                   0  1  0  1  0  1 | - - -
*                   0  1  0  1  1  0 | - - -
*                   0  1  0  1  1  1 | - - -
*                   0  1  1  0  0  0 | - - -
*                   0  1  1  0  0  1 | - - -
*                   0  1  1  0  1  0 | - - -
*                   0  1  1  0  1  1 | - - -
*                   0  1  1  1  0  0 | - - -
*                   0  1  1  1  0  1 | - - -
*                   0  1  1  1  1  0 | - - -
*                   0  1  1  1  1  1 | - - -
*                   1  0  0  0  0  0 | - - -
*                   1  0  0  0  0  1 | 1 0 0
*                   1  0  0  0  1  0 | 0 1 0
*                   1  0  0  0  1  1 | - - -
*                   1  0  0  1  0  0 | 0 0 1
*                   1  0  0  1  0  1 | - - -
*                   1  0  0  1  1  0 | - - -
*                   1  0  0  1  1  1 | - - -
*                   1  0  1  0  0  0 | - - -
*                   1  0  1  0  0  1 | - - -
*                   1  0  1  0  1  0 | - - -
*                   1  0  1  0  1  1 | - - -
*                   1  0  1  1  0  0 | - - -
*                   1  0  1  1  0  1 | - - -
*                   1  0  1  1  1  0 | - - -
*                   1  0  1  1  1  1 | - - -
*                   1  1  0  0  0  0 | - - -
*                   1  1  0  0  0  1 | - - -
*                   1  1  0  0  1  0 | - - -
*                   1  1  0  0  1  1 | - - -
*                   1  1  0  1  0  0 | - - -
*                   1  1  0  1  0  1 | - - -
*                   1  1  0  1  1  0 | - - -
*                   1  1  0  1  1  1 | - - -
*                   1  1  1  0  0  0 | - - -
*                   1  1  1  0  0  1 | - - -
*                   1  1  1  0  1  0 | - - -
*                   1  1  1  0  1  1 | - - -
*                   1  1  1  1  0  0 | - - -
*                   1  1  1  1  0  1 | - - -
*                   1  1  1  1  1  0 | - - -
*                   1  1  1  1  1  1 | - - -
********************************************************************************
*/
static const uint8_t c_source_table[64] = 
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 4, 0, 2, 0, 0, 0,
    0, 2, 1, 0, 4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 4, 2, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

/**
********************************************************************************
* @brief        Mapping from ARTIFAC enum to source table entries
* @waring       Indexes of this aray dependent on ARTIFACT enum, so be carefull
*               in case you change one of them
* @see          Look at ARTIFACT enum for more details
********************************************************************************
*/
static const uint8_t c_gesture[3] = 
{
    1,  ///< Rock
    2,  ///< Scisors
    4   ///< Paper
};

/**
********************************************************************************
*
********************************************************************************
*/
static const char* c_str_gesture[3] = 
{
    "Rock",
    "Scisors",
    "Paper"
};

/**
********************************************************************************
* @brief        Mapping of winner string literals
* @note         This can be std::map as well, but array gives constant
*               complexity on access where std::map logarithmic.
*               Might be replaced for std::vector
********************************************************************************
*/
static const char* c_winner_name[] = 
{
    "unknown",
    "Tie",
    "Player 2",
    "unknown",
    "Player 1"
};

/*
********************************************************************************
*
********************************************************************************
*/
void Playground::play(const Player& p1, const Player& p2)
{
    // in 8 bit 00xxxyyy where x is First player and y is Second Player
    static const uint8_t p1_mask = 0x3f;    ///< First player bitmask
    static const uint8_t p2_mask = 0x07;    ///< Second player bitmask

    for (int i = 0; i < m_nog; i++)
    {
        std::cout << "Round: " << (i + 1) << std::endl;

        ARTIFACT g1 = p1.gesture();
        ARTIFACT g2 = p2.gesture();

        std::cout << "Playground: " << c_str_gesture[g1] << " vs "
                  << c_str_gesture[g2] << std::endl;

        /**
        ************************************************************************
        * @internal
        * @brief    Represents value in c_source_table 
        * @note     c_gesture[g1] represents 1, 2 or 4. In order to make binary
        *           combination it is shifted right for 3 bits (because 4 is
        *           100) then 'or' it with c_gesturep[g2]. c_gesture is
        *           translation table between user input and source table
        *           expectations.
        ************************************************************************
        */
        uint8_t comb = ((c_gesture[g1] << 3) & p1_mask)
                        | (c_gesture[g2] & p2_mask);
        uint8_t result = c_source_table[comb];
        std::cout << "Winner: " << c_winner_name[result] << std::endl;
    }
}