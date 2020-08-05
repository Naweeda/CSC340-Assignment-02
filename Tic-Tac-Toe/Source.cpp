#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int main() {


	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

		return 0;

	}
bool isWon(char userInput, char board[][3])
{   
	//Loop for checking the rows and columns of the board
	for (int i = 0; i < 3; i++)
	{
		//Condition to check if the first character of the row is the current player, if it is then return true
		if (board[0][0] == userInput && board[0][1] == userInput && board[0][2] == userInput)
			return true;
		if (board[1][0] == userInput && board[1][1] == userInput && board[1][2] == userInput)
			return true;
		if (board[2][0] == userInput && board[2][1] == userInput && board[2][2] == userInput)
			return true;
		if (board[0][0] == userInput && board[1][0] == userInput && board[2][0] == userInput)
			return true;
		if (board[0][1] == userInput && board[1][1] == userInput && board[2][1] == userInput)
			return true;
		if (board[0][2] == userInput && board[1][2] == userInput && board[2][2] == userInput)
			return true;
		if (board[2][0] == userInput && board[1][1] == userInput && board[0][2] == userInput)
			return true;

	}
	return false;
}
//Method to check the board 
bool isDraw(char board[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
				return false;
		}
	}
	return true;
}
//Method for displaying the grid of the game
void displayBoard(char board[][3])
{

	cout << "\n--------\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << "|";
		}
		cout << "\n--------\n";
	}
}
//Method for asking the user to make a move, if the spot if already taken it won't work.
void makeAMove(char board[][3], char userInput)
{

	int gridRow, gridCol;
	
	while (true)
	{
		while (true) {
			cout << "Which row do you want to make move? " << userInput << endl;
			cin >> gridRow;
			   if (gridRow <= 2 && gridRow >= 0) {
				  break;
				}
			   else {
				 cout << "Invalid row position, re-enter." << endl;
		 }
	}//while invalid row
	    while (true) {
		    cout << "Which column do you want to make move? " << userInput << endl;
		    cin >> gridCol;
		       if (gridCol <= 2 && gridCol >= 0) {
			      break;
		        }
		       else {
			      cout << "Invalid column position, re-enter." << endl;
		}
	}//while invalid column

		if (board[gridRow][gridCol] == ' ') {
			board[gridRow][gridCol] = userInput;
			return;
		}//if: the space is empty
		else {
			cout << "The grid position is already taken." << endl;
		}//position is already taken

   }//while(true)

}

