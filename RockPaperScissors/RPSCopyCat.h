#pragma once
class CRPSCopyCat  : public CRPSBase
{
	private:
		unsigned char m_choice; 

	public:
		unsigned char MakeChoice() {
			return this->m_choice ; 
		}

		std::string GetName() { return "CopyCat"; }

		void Reset() {
			this->m_choice =  (unsigned char) rand() % 3 + 1; // Start with a random choice 
		} 

		void Result( unsigned char opponentChoice ) {
			this->m_choice = opponentChoice ; 
		} 


};

