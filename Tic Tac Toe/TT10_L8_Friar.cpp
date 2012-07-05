// Author:                      <Kenneth Friar>
// Assignment Number:           Programming Assignment "HW Ch08"
// File Name:                   TT10_L8_Friar.cpp
// Course/Section:              COSC 1320 Section <34171>
// Due Date:                    <10-13-11>
// Instructor:                  <Paul Thayer> 

/*
This program allows 2 players to compete in Tic Tac Toe.  It is possible to play
up to 100 games at the moment.  A menu is displayed.  Users have 3 options: play
a game, view results of games played so far in the current session, and quit.  
The game has been optimized to play with the keypad.  Each object in the array
keeps a record of its conclusion so that they may be retrieved by option 2.
*/

#include <iostream>
using namespace std;

void displayMenu();

class Board
{
	private:
		char game[3][3];
		int keypad[3][3];
		char playerSymbol;
		int move, moveCount, player, playerType, 
			player1Win, player2Win, draw, gameResult;
		
	public:
		int getMoveCount()
		{	return moveCount;	}
		
		int getPlayer()
		{	return player;	}
		
		int getGameResult()
		{	return gameResult;	}
		
		int getPlayer1Win()
		{	return player1Win;	}
		
		int getPlayer2Win()
		{	return player2Win;	}
		
		int getDraw()
		{	return draw;	}
		
		char getPlayerSymbol()
		{	return playerSymbol;	}
			
		void setPlayer()
		{
			playerType = ((moveCount + 1) % 2);
			switch (playerType)
			{
				case 0:
					player = 2;
					playerSymbol = 'O';
					break;
				case 1:
					player = 1;
					playerSymbol = 'X';
					break;
			}
		}	//end of setPlayer
		
		void showBoard()
		{	
			for (int row = 0; row < 3; row++)
			{
				for (int col = 0; col < 3; col++)
					cout << game[row][col];
				cout << endl;
			}
			cout << endl;	
		}	//end of showBoard
		
		void setMove(int Move)
		{
			int col, row;
			bool invalidInput;
			for (row = 0; row < 3; row++)
			{
				for (col = 0; col < 3; col++)
				{
					cout << keypad[row][col];
				}
				cout << endl;
			}
			invalidInput = true;
			while (invalidInput)
			{	
				cout << "Player " << player <<  " enter the number for your move: ";
				cin >> move;
				switch (move)
				{
					case 1:	row = 2; col = 0; break;
					case 2:	row = 2; col = 1; break;
					case 3:	row = 2; col = 2; break;
					case 4:	row = 1; col = 0; break;
					case 5:	row = 1; col = 1; break;
					case 6:	row = 1; col = 2; break;
					case 7:	row = 0; col = 0; break;
					case 8:	row = 0; col = 1; break;
					case 9:	row = 0; col = 2; break;
				}		
				if (move > 0 && move < 10 && game[row][col] == '*')
				{
					game[row][col] = playerSymbol;
					invalidInput = false;
				}
				else
					cout << "Invalid move." << endl;
			}
			system ("cls");
		}	//end of setMove
		
		void incMoveCount()
		{	moveCount++;	}
		
		bool checkGameEnd()
		{
			gameResult = 0;
			if	(	(game[0][0] == 'X' && game[0][1] == 'X' && game[0][2] == 'X') ||
					(game[1][0] == 'X' && game[1][1] == 'X' && game[1][2] == 'X') ||
					(game[2][0] == 'X' && game[2][1] == 'X' && game[2][2] == 'X') ||
					(game[0][0] == 'X' && game[1][0] == 'X' && game[2][0] == 'X') ||
					(game[0][1] == 'X' && game[1][1] == 'X' && game[2][1] == 'X') ||
					(game[0][2] == 'X' && game[1][2] == 'X' && game[2][2] == 'X') ||
					(game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == 'X') ||
					(game[2][0] == 'X' && game[1][1] == 'X' && game[0][2] == 'X')	)
						gameResult = 1;
				
			else 
			if	(	(game[0][0] == 'O' && game[0][1] == 'O' && game[0][2] == 'O') ||
					(game[1][0] == 'O' && game[1][1] == 'O' && game[1][2] == 'O') ||
					(game[2][0] == 'O' && game[2][1] == 'O' && game[2][2] == 'O') ||
					(game[0][0] == 'O' && game[1][0] == 'O' && game[2][0] == 'O') ||
					(game[0][1] == 'O' && game[1][1] == 'O' && game[2][1] == 'O') ||
					(game[0][2] == 'O' && game[1][2] == 'O' && game[2][2] == 'O') ||
					(game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == 'O') ||
					(game[2][0] == 'O' && game[1][1] == 'O' && game[0][2] == 'O')	)
						gameResult = 2;
				
			else if (moveCount == 9)
				gameResult = 3;
			
			switch (gameResult)
			{
				case 1:
					system ("cls");
					cout << "Player 1 wins." << endl;
					player1Win = 1;
					return true;
					break;
				case 2:
					system ("cls");
					cout << "Player 2 wins." << endl;
					player2Win = 1;					
					return true;
					break;
				case 3:
					system ("cls");
					cout << "Game ended in a draw." << endl;
					draw = 1;					
					return true;
					break;
				default:
					return false;
			}	//end switch
		}	//end checkGameEnd
		
		Board()		//default constructor
		{	
			move = moveCount = player = player1Win = player2Win = draw = 0;
			keypad[0][0] = 7; keypad[0][1] = 8; keypad[0][2] = 9;
			keypad[1][0] = 4; keypad[1][1] = 5; keypad[1][2] = 6;
			keypad[2][0] = 1; keypad[2][1] = 2; keypad[2][2] = 3;
			
			for (int row = 0; row < 3; row++)
			{
				for (int col = 0; col < 3; col++)
					game[row][col] = '*';
			}	
		}
		
};
	
int main()
{
	Board board[100];
	int Move, gameCount, userInput, play1Wins, play2Wins, draws, subscript;
	gameCount, userInput, play1Wins, play2Wins, draws, subscript = 0;
	bool running = false;
	
	for (gameCount = 0; gameCount < 100; gameCount++)
	{
		displayMenu();
		cin >> userInput;
		system ("cls");
		switch (userInput)
		{
			case 1:
				running = true;
				break;
			case 2:
				while (subscript < gameCount)
				{
					play1Wins += board[subscript].getPlayer1Win();
					play2Wins += board[subscript].getPlayer2Win();
					draws += board[subscript].getDraw();
					subscript++;
				}
				cout << "Player 1 has won " << play1Wins << " games." << endl;
				cout << "Player 2 has won " << play2Wins << " games." << endl;
				cout << "There have been " << draws << " draws." << endl << endl;
				break;
		}	//end switch
		if (userInput == 3)
			break;
			
		while (running)
		{	
			board[gameCount].setPlayer();
			board[gameCount].setMove(Move);
			board[gameCount].incMoveCount();
			running = !(board[gameCount].checkGameEnd());
			board[gameCount].showBoard();
		}	//end while
	}	//end gameCount for loop
	
	system("pause");
	return 0;
}	//end of main
	
void displayMenu()
{
	cout << "What would you like to do?" << endl;
	cout << "(1) New game of Tic Tac Toe." << endl;
	cout << "(2) View results." << endl;
	cout << "(3) Quit playing." << endl;
	cout << "Enter 1, 2, or 3: ";
}
/* Output

Initial			What would you like to do?
Prompt			(1) New game of Tic Tac Toe.
				(2) View results.
				(3) Quit playing.
				Enter 1, 2, or 3: 1
----------------------------------------------------------------
During			***
Game			O**
				OXX
				
				789
				456
				123
				Player 1 enter the number for your move:
----------------------------------------------------------------
End Game		Player 2 wins.
Screen			X*O
				OOX
				OXX
				
				What would you like to do?
				(1) New game of Tic Tac Toe.
				(2) View results.
				(3) Quit playing.
				Enter 1, 2, or 3: 2
---------------------------------------------------------------
Results			Player 1 has won 1 games.
Screen			Player 2 has won 1 games.
				There have been 0 draws.
				
				What would you like to do?
				(1) New game of Tic Tac Toe.
				(2) View results.
				(3) Quit playing.
				Enter 1, 2, or 3:

*/

