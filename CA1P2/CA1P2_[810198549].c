#include<stdio.h>
int turn(int pick);
void board(char *square);
int checker(int choice);
int placechecker(int choice, char *square);
void placer1(int place, char *square);
void placer2(int place, char *square);
int checkwin(int l, char *square);
int main() {
	int playagain;
	do{
	char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int choice;
	//display the board
	board(square);
	/*odd rounds are for player 1
	and even rounds are for player 2*/
	for (int round = 1; round < 10; round++) {
		if (round % 2 == 1) {
			printf("Player 1 please enter a number...");
			scanf_s("%d", &choice);
			int x = choice;
			if (checker(x) == 0) {
				printf("Invalid number , Please re-enter the number...\n");
				round--;
				continue;
			}
			/*check if players select a filled squares*/
			int z =placechecker(choice, square);
			if (z == 0) {
				round--;
				printf("selected square has been filled , Please re-enter the number...\n");
				continue;
			}
			/*place player 1's choice into square
			put 'X' in squares*/
			placer1(choice, square);
			board(square);
		}
		else {
			printf("Player 2 please enter a number...");
			scanf_s("%d", &choice);
			int z = choice;
			if (checker(z) == 0) {
				printf("Invalid number , Please re-enter the number...\n");
				round--;
				continue;
			}
			/*check if players select a filled squares*/
			int f =placechecker(choice, square);
			if (f == 0) {
				round--;
				printf("selected square has been filled , Please re-enter the number...\n");
				
				continue;
			}
			/*place player 2's choice into square
			put 'O' in squares*/
			placer2(choice, square);
			board(square);
		}
		/*check if game has winner*/
		int winner=checkwin(round, square);
		if (winner == 21) {
			printf("player 1 wins\n");
			break;
		}
		else if (winner == 22) {
			printf("player 2 wins\n");
			break;
		}
		else if (winner == 20) {
			printf("game tied up!\n");
			break;
		}
	}
	printf("if you wanna play again enter number 1 otherwise enter another number\n");
	scanf_s("%d", &playagain);
	} while (playagain == 1);
}
	

void board(char *square) {
	printf("Tic Tac Toe Game\n\n");
	printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

	printf("     |     |   \n");
	printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);
	printf("     |     |     \n\n");

}

int checker(int choice) {
	if (choice < 1 || choice>9) {
		return 0;
	}
	else {
		return 1;
	}
}
int placechecker(int choice, char *square) {
	if ((choice == 1) && square[1] != '1')
	{
		return 0;
	}
	if ((choice == 2) && square[2] != '2')
	{
		return 0;
	}
	if ((choice == 3) && square[3] != '3')
	{
		return 0;
	}
	if ((choice == 4) && square[4] != '4')
	{
		return 0;
	}
	if ((choice == 5) && square[5] != '5')
	{
		return 0;
	}
	if ((choice == 6) && square[6] != '6')
	{
		return 0;
	}
	if ((choice == 7) && square[7] != '7')
	{
		return 0;
	}
	if ((choice == 8) && square[8] != '8')
	{
		return 0;
	}
	if ((choice == 9) && square[9] != '9')
	{
		return 0;
	}
	return 1;
}

void placer1(int place, char *square) {
	switch (place)
	{
	case 1:
		square[1] = 'X';
		break;
	case 2:
		square[2] = 'X';
		break;
	case 3:
		square[3] = 'X';
		break;
	case 4:
		square[4] = 'X';
		break;
	case 5:
		square[5] = 'X';
		break;
	case 6:
		square[6] = 'X';
		break;
	case 7:
		square[7] = 'X';
		break;
	case 8:
		square[8] = 'X';
		break;
	case 9:
		square[9] = 'X';
		break;
	default:
		break;
	}
}

void placer2(int place, char *square) {
	switch (place)
	{
	case 1:
		square[1] = 'O';
		break;
	case 2:
		square[2] = 'O';
		break;
	case 3:
		square[3] = 'O';
		break;
	case 4:
		square[4] = 'O';
		break;
	case 5:
		square[5] = 'O';
		break;
	case 6:
		square[6] = 'O';
		break;
	case 7:
		square[7] = 'O';
		break;
	case 8:
		square[8] = 'O';
		break;
	case 9:
		square[9] = 'O';
		break;
	default:
		break;
	}
}

int checkwin(int l, char *square) {
	if (square[1] == square[2] && square[2] == square[3]) {
		if (l % 2 == 1)
			return 21;

		else
			return 22;

	}

	if (square[4] == square[5] && square[5] == square[6]) {
		if (l % 2 == 1)
			return 21;

		else
			return 22;

	}
	if (square[7] == square[8] && square[8] == square[9]) {
		if (l % 2 == 1)
			return 21;

		else
			return 22;

	}
	if (square[1] == square[4] && square[4] == square[7]) {
		if (l % 2 == 1)
			return 21;

		else
			return 22;

	}
	if (square[2] == square[5] && square[5] == square[8]) {
		if (l % 2 == 1)
			return 21;

		else
			return 22;

	}
	if (square[3] == square[6] && square[6] == square[9]) {
		if (l % 2 == 1)
			return 21;

		else
			return 22;

	}
	if (square[1] == square[5] && square[5] == square[9]) {
		if (l % 2 == 1)
			return 21;

		else
			return 22;

	}
	if (square[3] == square[5] && square[5] == square[7]) {
		if (l % 2 == 1)
			return 21;

		else
			return 22;

	}
	if (l == 9) {
		return 20;
	}
	return 0;
}