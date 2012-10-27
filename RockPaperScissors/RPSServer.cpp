#include "stdafx.h"
#include "RPSServer.h"


std::string ToString( unsigned int val ) {
	std::stringstream st;
	st << val;
	return st.str();
}


bool CRPSServer::AddPlayer( CRPSBase * player ) {
	if( player == NULL ) {
		return false; 
	}

	this->m_players.push_back( player ); 
	return true ; 
}

void CRPSServer::RunTests() {

	size_t playerCount = this->m_players.size() ; 
	printf( "Rock Paper Scissors game between %d players over %d rounds.\n", playerCount, MAX_TURN_COUNT ); 
	printf( "Higher values are better\n\n");


	printf( "Per round\n"); 
	// Loop though all the different players. 
	for( std::vector<CRPSBase *>::iterator playerOneOffset = this->m_players.begin(); playerOneOffset != this->m_players.end(); playerOneOffset++ ) {
		// We don't need to run the same test twice. 
		for( std::vector<CRPSBase *>::iterator playerTwoOffset = (playerOneOffset+1); playerTwoOffset != this->m_players.end(); playerTwoOffset++ ) {
			this->RunTest( (*playerOneOffset), (*playerTwoOffset), MAX_TURN_COUNT );
		}
	}
}

void CRPSServer::RunTest( CRPSBase * playerOne, CRPSBase * playerTwo, unsigned int turnCount ) {

	if( playerOne == NULL || playerTwo == NULL ) {
		printf( "Error: Player One or Two never got init. \n");
		return ; 
	}

	// Reset any internal counters. 
	playerOne->Reset(); 
	playerTwo->Reset(); 

	// A counter for each player to test how much time they will serve 
	unsigned int playerOneScore	= 0 ; 
	unsigned int playerTwoScore	= 0 ; 

	// Do the tests. 
	for( int turn = 0 ; turn < turnCount ; turn++ ) {

		// Get the choices from each player 
		unsigned char playerOnesChoice = playerOne->MakeChoice( ) ; 
		unsigned char playerTwosChoice = playerTwo->MakeChoice( ) ; 

		// Update the history variables. 
		playerOne->Result( playerTwosChoice ) ; 
		playerTwo->Result( playerOnesChoice ); 

		// Score the results. 		
		playerOneScore += ScoreTest( playerOnesChoice, playerTwosChoice ); 
		playerTwoScore += ScoreTest( playerTwosChoice, playerOnesChoice ); 

		// printf( "playerOnesChoice=[%d] (%d), playerTwosChoice=[%d] (%d)\n", playerOnesChoice, playerOneScore, playerTwosChoice, playerTwoScore ); 

		this->m_stats[ std::string( "PlayerOne.Choice.") + ToString( (unsigned int) playerOnesChoice ) ] ++; 
		this->m_stats[ std::string( "PlayerTwo.Choice.") + ToString( (unsigned int) playerTwosChoice ) ] ++; 

		if( playerOnesChoice == playerTwosChoice ) {
			this->m_stats[ std::string( "Results.ties") ] ++; 
		}

	}

	// Print the results 
	printf( "%13s (%4d) Vs %13s (%4d) - Total: %4d - ", playerOne->GetName().c_str(), playerOneScore, playerTwo->GetName().c_str(), playerTwoScore, playerOneScore + playerTwoScore ); 
	if( playerOneScore == playerTwoScore ) {
		printf( "Tied ! "); 
	} else if( playerOneScore > playerTwoScore ) {
		printf( "%s Wins",  playerOne->GetName().c_str() ); 
	} else {
		printf( "%s Wins",  playerTwo->GetName().c_str() ); 
	}		
	printf( "\n");

	// Print the stats 
	/*
	printf( "Stats: \n");
	for( std::map<std::string, unsigned long>::iterator it = this->m_stats.begin() ; it != this->m_stats.end(); it++ ) {
		printf( "%s=[%d]\n", (*it).first.c_str(),  (*it).second ); 
	}
	*/
}



int CRPSServer::ScoreTest( unsigned char PlayerA, unsigned char PlayerB) {
	if( PlayerA > 3 || PlayerA < 1 ||
		PlayerB > 3 || PlayerB < 1 ) 
	{
		return 0; // Invalid response 
	}

	if( PlayerA == PlayerB ) {
		// Tie 
		return 0; 
	}
	if( PlayerA == CHOICE_ROCK ) 
	{
		if( PlayerB == CHOICE_SCISSORS ) {
			return 1; // Win 
		} else {
			return 0; // Lose 
		}
	}

	if( PlayerA == CHOICE_PAPER ) 
	{
		if( PlayerB == CHOICE_ROCK ) {
			return 1; // Win 
		} else {
			return 0; // Lose 
		}
	}

	if( PlayerA == CHOICE_SCISSORS ) 
	{
		if( PlayerB == CHOICE_PAPER ) {
			return 1; // Win 
		} else {
			return 0; // Lose 
		}
	}

	// Unreachable code. 
	return 0 ; 
}