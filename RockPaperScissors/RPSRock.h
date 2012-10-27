#pragma once

#include "RPSBase.h"

class CRPSRock : public CRPSBase
{
public:

	unsigned char MakeChoice() { return CHOICE_ROCK;  }
	std::string GetName() { return "Rock"; } 

};

