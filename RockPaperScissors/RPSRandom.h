#pragma once
#include "RPSBase.h"
#include <string>

class CRPSRandom : public CRPSBase
{
public:

	unsigned char MakeChoice() { return (unsigned char) rand() % 3 + 1; }
	std::string GetName() { return "Random"; } 

};

