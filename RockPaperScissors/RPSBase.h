#pragma once

#include <string>

#define CHOICE_ROCK		1
#define CHOICE_PAPER	2
#define CHOICE_SCISSORS	3

class CRPSBase
{
public:

	// 1 = Rock, 2 paper, 3 = scissors
	virtual unsigned char MakeChoice() = 0 ; 	
	virtual std::string GetName() =0 ; 

	virtual void Reset() {} ; 
	virtual void Result( unsigned char opponentChoice ) {} ; 
};

