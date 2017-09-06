/**
********************************************************************************
* @file         playground.h
* @brief        RPS playground class definition
* @author       Maksym Koshel (maks.koshel@gmail.com)
* @date         Sep 02, 2017
********************************************************************************
*/

#ifndef _PLAYGROUND_H_
#define _PLAYGROUND_H_

// Forward declaration
class Player;

/**
********************************************************************************
* @class 		Playground
* @brief		Defines interfaces and placeholder for RPS flow
* @note 		Implementation of the RPS game based on simplified version of
*				abstract finite state machine (Moore or Mealy, depends on
*				preference). The most obvious implementaiton would be
*				if-else-if-else but I just prefer approach implemented inside.
********************************************************************************
*/
class Playground
{
public:
	/**
	****************************************************************************
	* @brief 	The only allowed constructor for this object
	* @param 	[in] number 	Number of games will be played
	****************************************************************************
	*/
	Playground(int number);
	~Playground();

	/**
	****************************************************************************
	* @brief 	Play RPS game
	* @param 	[in] p1 	First player
	* @param 	[in] p2 	Second player
	* @retrun 	void
	****************************************************************************
	*/
	void play(const Player& p1, const Player& p2);

private:
	Playground() = delete;
	Playground(const Playground& r) = delete;
	Playground& operator=(const Playground& r) = delete;

private:
	int m_nog;	///< Number of games
};

#endif	/* !_PLAYGROUND_H_ */
