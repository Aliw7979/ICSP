#include<stdio.h>
int main() {
	int playagain;
	do {
		/* start with a numbered board */
		char square1 = '1', square2 = '2', square3 = '3', square4 = '4', square5 = '5', square6 = '6', square7 = '7', square8 = '8', square9 = '9';
		int choice;
		printf("Tic Tac Toe Game\n\n");
		printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


		printf("     |     |   \n");
		printf("  %c  |  %c  |  %c \n", square1, square2, square3);
		printf("_____|_____|_____\n");
		printf("     |     |     \n");
		printf("  %c  |  %c  |  %c \n", square4, square5, square6);
		printf("_____|_____|_____\n");
		printf("     |     |     \n");
		printf("  %c  |  %c  |  %c \n", square7, square8, square9);
		printf("     |     |     \n\n");

		for (int round = 1; round < 10; round++) {
			/*odd rounds are for player 1
			and even rounds are for player 2*/
			if (round % 2 == 1) {
				printf("Player 1 please enter a number...");
				scanf_s("%d", &choice);
				if (choice < 1 || choice>9) {
					printf("Invalid number , Please re-enter the number...\n");
					round--;
					continue;
				}
				/*check if players select a filled squares*/
				if ((choice == 1) && square1 != '1')
				{
					printf("selected square has been filled , Please re-enter the number...\n");
					round--;
					continue;
				}
				if ((choice == 2) && square2 != '2')
				{
					printf("selected square has been filled , Please re-enter the number...\n");
					round--;
					continue;
				}
				if ((choice == 3) && square3 != '3')
				{
					printf("selected square has been filled , Please re-enter the number...\n");
					round--;
					continue;
				}
				if ((choice == 4) && square4 != '4')
				{
					printf("selected square has been filled , Please re-enter the number...\n");
					round--;
					continue;
				}
				if ((choice == 5) && square5 != '5')
				{
					printf("selected square has been filled , Please re-enter the number...\n");
					round--;
					continue;
				}
				if ((choice == 6) && square6 != '6')
				{
					printf("selected square has been filled , Please re-enter the number...\n");
					round--;
					continue;
				}
				if ((choice == 7) && square7 != '7')
				{
					printf("selected square has been filled , Please re-enter the number...\n");
					round--;
					continue;
				}
				if ((choice == 8) && square8 != '8')
				{
					printf("selected square has been filled , Please re-enter the number...\n");
					round--;
					continue;
				}
				if ((choice == 9) && square9 != '9')
				{
					printf("selected square has been filled , Please re-enter the number...\n");
					round--;
					continue;
				}
				/*put 'X' in squares*/
				switch (choice)
				{
				case 1:
					square1 = 'X';
					break;
				case 2:
					square2 = 'X';
					break;
				case 3:
					square3 = 'X';
					break;
				case 4:
					square4 = 'X';
					break;
				case 5:
					square5 = 'X';
					break;
				case 6:
					square6 = 'X';
					break;
				case 7:
					square7 = 'X';
					break;
				case 8:
					square8 = 'X';
					break;
				case 9:
					square9 = 'X';
					break;
				default:
					break;
				}
				printf("     |     |     \n");
				printf("  %c  |  %c  |  %c \n", square1, square2, square3);
				printf("_____|_____|_____\n");
				printf("     |     |     \n");
				printf("  %c  |  %c  |  %c \n", square4, square5, square6);
				printf("_____|_____|_____\n");
				printf("     |     |     \n");
				printf("  %c  |  %c  |  %c \n", square7, square8, square9);
				printf("     |     |     \n\n");
			}
			else {
				printf("Player 2 please enter a number...");
				scanf_s("%d", &choice);
				if (choice < 1 || choice>9) {
					printf("Invalid number , Please re-enter the number...\n");
					round--;
					continue;
				}
				/*put 'O' in squares*/
				switch (choice)
				{
				case 1:
					square1 = 'O';
					break;
				case 2:
					square2 = 'O';
					break;
				case 3:
					square3 = 'O';
					break;
				case 4:
					square4 = 'O';
					break;
				case 5:
					square5 = 'O';
					break;
				case 6:
					square6 = 'O';
					break;
				case 7:
					square7 = 'O';
					break;
				case 8:
					square8 = 'O';
					break;
				case 9:
					square9 = 'O';
					break;
				default:
					break;
				}
				printf("     |     |     \n");
				printf("  %c  |  %c  |  %c \n", square1, square2, square3);
				printf("_____|_____|_____\n");
				printf("     |     |     \n");
				printf("  %c  |  %c  |  %c \n", square4, square5, square6);
				printf("_____|_____|_____\n");
				printf("     |     |     \n");
				printf("  %c  |  %c  |  %c \n", square7, square8, square9);
				printf("     |     |     \n\n");
			}
			/*check if game has winner*/
			if (square1 == square2 && square2 == square3) {
				if (round % 2 == 1)
					printf("player 1 wins\n");
				else
					printf("player 2 wins\n");
				break;
			}
			
			if (square4 == square5 && square5 == square6) {
				if (round % 2 == 1)
					printf("player 1 wins\n");
				else
					printf("player 1 wins\n");
				break;
			}
			if (square7 == square8 && square8 == square9) {
				if (round % 2 == 1)
					printf("player 1 wins\n");
				else
					printf("player 2 wins\n");
				break;
			}
			if (square1 == square4 && square4 == square7) {
				if (round % 2 == 1)
					printf("player 1 wins\n");
				else
					printf("player 2 wins\n");
				break;
			}
			if (square2 == square5 && square5 == square8) {
				if (round % 2 == 1)
					printf("player 1 wins\n");
				else
					printf("player 2 wins\n");
				break;
			}
			if (square3 == square6 && square6 == square9) {
				if (round % 2 == 1)
					printf("player 1 wins\n");
				else
					printf("player 2 wins\n");
				break;
			}
			if (square1 == square5 && square5 == square9) {
				if (round % 2 == 1)
					printf("player 1 wins\n");
				else
					printf("player 2 wins\n");
				break;
			}
			if (square3 == square5 && square5 == square7) {
				if (round % 2 == 1)
					printf("player 1 wins\n");
				else
					printf("player 2 wins\n");
				break;
			}
			if (round == 9) {
				printf("game tied!\n");
			}

		}
		/*check if game is tied*/
		printf("if you wanna play again enter number 1 otherwise enter another number\n");
		scanf_s("%d", &playagain);
	} while (playagain == 1);
}