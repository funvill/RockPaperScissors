// RockPaperScissors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RPSServer.h"
#include "RPSRandom.h"
#include "RPSRock.h"
#include "RPSCopyCat.h"
#include "RPSHistory.h"
#include "RPSZee.h"

/**
 * Idea for this game came from http://www.rpscontest.com/leaderboard/23
 *
 * Other ideas for bots
 * - 
 */ 

int _tmain(int argc, _TCHAR* argv[])
{

	CRPSServer server;
	server.AddPlayer( new CRPSRandom() ); 
	server.AddPlayer( new CRPSRock() ); 
	server.AddPlayer( new CRPSCopyCat() ); 
	server.AddPlayer( new CRPSHistory() ); 
	server.AddPlayer( new CRPSZee() ); 

	
	server.RunTests(); 


	return 0;
}

