#pragma once

#include "RPSBase.h"
#include <vector>
#include <map>
#include <sstream>

#define MAX_TURN_COUNT 1000 



class CRPSServer
{

private:
	std::vector<CRPSBase *> m_players; 

	std::map<std::string, unsigned long> m_stats; 

	void RunTest( CRPSBase * playerOne, CRPSBase * playerTwo, unsigned int turnCount ) ; 
	int ScoreTest( unsigned char PlayerA, unsigned char PlayerB) ; 

public:

	bool AddPlayer( CRPSBase * player ) ; 
	void RunTests(); 
};

