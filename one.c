#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

char board[3][3];             // our 2d array
int moves_no;                 // moves' counter to be able to determine when a tie occur
char choice;                  // user's input character to decide which player to start with

void ResetBoard();
int ChoosePlayer(char c);
void Player1sTurn();
void Player2sTurn();
char WhoWon();
void GameLayout();

int main() {
	char enter = ' ';
	char gameResult;
	moves_no = 0;

	printf("Let's play X-O game!\n\n");
	printf("Rules: \n");
	printf("This game is for 2 players  \n");
	printf("Player 1 will play with X  \n");
	printf("Player 2 will play with O \n\n");
	printf("Press enter to start the game :) \n");
	scanf("%c", &enter);


	system("cls");          // to clear the console so as not to be crammed with messages

	ResetBoard();           // start Game    
	GameLayout();

	printf("Press X or O to decide which player you want to be.\n");
	scanf("%c", &choice);

	if (&choice != 'x'|| &choice != 'X') {
		while (ChoosePlayer(choice) == 0) {
			printf("Invalid choice. Please press X or O to start the game!\n");
			scanf("%c", &choice);
		}
	}

	gameResult = WhoWon();
	
	while (gameResult == ' ' && moves_no<9) {


		Player1sTurn();
		GameLayout();
		gameResult = WhoWon();
		moves_no++;
		if (moves_no == 9) break;

		if (gameResult == 'X' || gameResult == 'O')
			break;

		Player2sTurn();
		GameLayout();
		gameResult = WhoWon();
		moves_no++;
	}
	if (gameResult == 'X') {
		printf("\n\n%c wins the game!", gameResult);
		printf("\nO loses the game :(");
	}
	else if (gameResult == 'O') {
		printf("\n\n%c wins the game!", gameResult);
		printf("\nX loses the game :(");
	}

	else
		printf("\n\nThat's a tie -_-"); 
	


	return 0;
}

// initialize board (2d array) with empty spaces
void ResetBoard() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}

}

// choose player X or player O
int ChoosePlayer(char c) {
	if (c == 'O' || c == 'o') {
		Player2sTurn();
		GameLayout();
		moves_no++;
		return 1;
	}
	else if (c == 'x' || c == 'X')
		return 1;
	else
		return 0;
}

//Each time it is player one's turn, this function is called to scan the input and display it on screen
void Player1sTurn() {
	int x, y;

	printf("Player1, please enter your coordinates: \n");
	scanf("%d %d", &x, &y);

	// decrement coordinates as indices in 2d array are 0, 1, 2 not 1, 2, 3
	x--;
	y--;

	//check the cell is empty before entering player 1's letter in the 2d array and on screen
	if (board[x][y] == ' ')
		board[x][y] = 'X';

	else {
		printf("\nInvalid coordinates. Please try again.\n\n");
		Player1sTurn();
	}
}

//Each time it is player one's turn, this function is called to scan the input and display it on screen
void Player2sTurn() {
	int x, y;
	printf("Player2, now is your turn. Enter your coordinates: \n");
	scanf("%d %d", &x, &y);

	x--;
	y--;

	if (board[x][y] == ' ')
		board[x][y] = 'O';

	else {
		printf("\nInvalid coordinates. Please try again.\n\n");
		Player2sTurn();
	}
}


// print the game's borders and layout of game for the user
void GameLayout() {

	system("cls");

	printf("--X/O Game--\n");
	printf("\n");

	for (int i = 0; i < 3; i++) {

		printf("%c | %c | %c", board[i][0], board[i][1], board[i][2]);

		if (i != 2)                                     /*Board is not yet complete so there is still a next line
														that needs a border between it& previous line*/
			printf("\n--|---|--\n");
	}

	printf("\n\n");
}


//check all possible places (rows, columns, diagonals) for a win then return the winning letter
char WhoWon() {
	for (int i = 0; i < 3; i++) {

		// review the 3 rows
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
			return board[i][0];

		// review the 3 columns
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return board[0][i];
	}
	// review the 2 diagonals
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
		return board[0][0];

	if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return board[0][2];

	//if no one won then the 2 players are still playing
	return ' ';
}