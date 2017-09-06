/**
********************************************************************************
* @file         player.h
* @brief        RPS player class definition
* @author       Maksym Koshel (maks.koshel@gmail.com)
* @date         Sep 02, 2017
********************************************************************************
*/

#ifndef _PLAYER_H_
#define _PLAYER_H_

/**
********************************************************************************
* @enum 		ARTIFACT
* @brief 		Definition of possible artifacts can be returned by Player
********************************************************************************
*/
typedef enum
{
	ARTIFACT_ROCK 		= 0,
	ARTIFACT_SCISORS 	= 1,
	ARTIFACT_PAPER 		= 2
} ARTIFACT;

/**
********************************************************************************
* @class 		Player
* @brief 		Player base class with pure virtual method to provide gesture
********************************************************************************
*/
class Player
{
public:
	/**
	****************************************************************************
	* @brief 	Interface to provide gesture
	* @return 	One of possible value from ARTIFACT enum
	****************************************************************************
	*/
	virtual ARTIFACT gesture(void) const = 0;
	virtual ~Player();

protected:
	Player();

private: // Blocked implementations
	Player(const Player& r) = delete;
	Player& operator=(const Player& r) = delete;
};

/**
********************************************************************************
* @class 		Machine
* @brief 		Machine player (AI) for RPS game
********************************************************************************
*/
class Machine : public Player
{
public:
	Machine();
	~Machine();

	/**
	****************************************************************************
	* @brief 	Provide one of ARTIFACT gestures from Machine player
	* @return 	One of possible value from ARTIFACT enum
	****************************************************************************
	*/
	ARTIFACT gesture(void) const;

private:
	Machine(const Machine& r) = delete;
	Machine& operator=(const Machine& r) = delete;
};

/**
********************************************************************************
* @class 		Human
* @brief 		Human player for RPS game
********************************************************************************
*/
class Human : public Player
{
public:
	Human();
	~Human();

	/**
	****************************************************************************
	* @brief 	Provide one of ARTIFACT gesture from Human player
	* @note 	This function reads input from stdin
	* @note 	This function throws exception in if user can't provide
	*			proper input from stdin
	* @return 	One of possible value from ARTIFACT enum
	****************************************************************************
	*/
	ARTIFACT gesture(void) const;
private:
	Human(const Human& r) = delete;
	Human& operator=(const Human& r) = delete;

private:
	static const int c_not = 3;	///< Number of tries to read from stdin
};

#endif /* !_PLAYER_H_ */
