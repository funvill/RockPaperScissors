#pragma once

#include "RPSBase.h"

/**
 * If the plays rock, then the oppisite of that would be paper so select scissors instead. Zee Game
 * in other words, based off what the last one the oppoent used select what would have killed you. 
 */ 
class CRPSZee  : public CRPSBase
{
	private:
		unsigned char m_choice; 

	public:
		unsigned char MakeChoice() {
			return this->m_choice ; 
		}

		std::string GetName() { return "Zee"; }

		void Reset() {
			this->m_choice =  (unsigned char) rand() % 3 + 1; // Start with a random choice 
		} 

		void Result( unsigned char opponentChoice ) {

			switch( opponentChoice ) {
				case CHOICE_ROCK: {
					this->m_choice = CHOICE_SCISSORS ; 
					break; 
				}
				case CHOICE_PAPER: {
					this->m_choice = CHOICE_ROCK ; 
					break; 
				}
				case CHOICE_SCISSORS: {
					this->m_choice = CHOICE_PAPER ; 
					break; 
				}
			}
		} 


};

