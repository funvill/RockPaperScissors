#pragma once

class CRPSHistory : public CRPSBase 
{
	private:
		unsigned int m_opponetRock; 
		unsigned int m_opponetPaper; 
		unsigned int m_opponetScissors; 

	public:
		unsigned char MakeChoice() {

			if( m_opponetRock > m_opponetPaper && m_opponetRock > m_opponetScissors ) {
				// He likes his rock, counter with paper 
				return CHOICE_PAPER ; 
			}
			else if( m_opponetPaper > m_opponetRock && m_opponetPaper > m_opponetScissors ) {
				// He likes his paper, counter with Scissors 
				return CHOICE_SCISSORS ; 
			}
			else if( m_opponetScissors > m_opponetRock && m_opponetScissors > m_opponetPaper ) {
				// He likes his scissors, counter with rock 
				return CHOICE_ROCK ; 
			} else {
				// We are all tied up, return random. 
				return (unsigned char) rand() % 3 + 1; 
			}
		}

		std::string GetName() { return "History"; }

		void Reset() {
			this->m_opponetRock		= 0 ; 
			this->m_opponetPaper	= 0 ; 
			this->m_opponetScissors	= 0 ; 
		} 

		void Result( unsigned char opponentChoice ) {
			switch( opponentChoice ) {
				case CHOICE_ROCK: {
					this->m_opponetRock++; 
					break; 
				}
				case CHOICE_PAPER: {
					this->m_opponetPaper++; 
					break; 
				}
				case CHOICE_SCISSORS: {
					this->m_opponetScissors++; 
					break; 
				}
			}
		} 

};

