#include"othelloPlacer.h"
#include"othelloBoard.h"
int main() {
	char a[8][8];//meqdar dahi be array 8 dar 8 az noe char 
	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= 7; j++)
			a[i][j] = '.';
	}
	a[3][3] = 'w';
	a[3][4] = 'b';
	a[4][3] = 'b';
	a[4][4] = 'w';
	board(a);
	placer(a);



}
void board(char square[8][8]) {
	int countb = 0;
	int countw = 0;
	for (int i = 0; i <= 7; i++) {//neshan dadane tedade mohre haye siah va sefid dar kenare board
		for (int j = 0; j <= 7; j++)
			if (square[i][j] == 'b')
				countb++;
			else if (square[i][j] == 'w')
				countw++;
	}
	int col = 0;
	printf("   1 2 3 4 5 6 7 8[b=%d w=%d]\n", countb, countw);//chape board
	for (int h = 0; h <= 7; h++) {
		col = col + 10;
		printf("%d ", col);
		for (int p = 0; p <= 7; p++) {
			printf("%c ", square[h][p]);
		}
		printf("\n");
	}


}
void placer(char a[8][8]) {//taeene nobat gereftane meqdar va jay gozari 
	int round = 1;
	for (round; round; round++) {//round haye fard braye player Black
		if (round % 2 == 1)
		{
			int playerb;
			int satr;
			int soton;
			printf("player black turn...");
			scanf("%d", &playerb);
			satr = (playerb / 10) - 1;
			soton = (playerb % 10) - 1;
			if (a[satr][soton] != '.') {
				printf("invalid choice.Enter another number\n");
				round--;
				continue;
			}
			if (satr > 7 || satr < 0 || soton > 7 || soton < 0) {
				printf("invalid choice.Enter another number \n");
				round--;
				continue;
			}
			if (doerb(a, satr, soton) == 0) {
				printf("invalid choice.Enter another number \n");
				round--;
				continue;
			}
			else {
				a[satr][soton] = 'b';
			}
		}
		else if (round % 2 != 1)////round haye zoj braye player White
		{
			int playerw;
			int satr;
			int soton;
			printf("player white turn...");
			scanf("%d", &playerw);
			satr = (playerw / 10) - 1;
			soton = (playerw % 10) - 1;
			if (a[satr][soton] != '.') {
				printf("invalid choice.Enter another number\n");
				round--;
				continue;
			}
			if ((satr > 7) || (satr < 0) || (soton > 7) || (soton < 0)) {
				printf("invalid choice.Enter another number\n");
				round--;
				continue;
			}
			if (doerw(a, satr, soton) == 0) {
				printf("invalid choice.Enter another number \n");
				round--;
				continue;
			}
			else {
				a[satr][soton] = 'w';
			}

		}
		board(a);
		int satr1 = 0, soton1 = 0;
		int round1 = 64;
		for (satr1, soton1; (satr1 < 8) && (soton1 < 8); satr1++, soton1++) {
			if (a[satr1][soton1] != '.') {
				round1--;
			}
		}
		if (round1 == 0) {
			if (checkwin(a) == 1) {//check kardane baraye taeene barande
				printf("black won\n");
				break;
			}
			else if (checkwin(a) == 1) {
				printf("white won\n");
				break;
			}
			else {
				printf("game tied!\n");
				break;
			}
		}
	}
}
int doerb(char a[8][8], int satr, int soton) {//jay gozarie mohre haye siah va bargardandane mohre haye sefid
	int lay = 0;
	int satravalie = satr;
	int sotonavalie = soton;
	if (a[satravalie][sotonavalie + 1] == 'w') {
		for (soton++; soton < 9; soton++) {
			if (a[satr][soton] == 'b') {
				for (soton--; soton > sotonavalie; soton--) {
					if (a[satr][soton] == 'w') {
						lay++;
						a[satr][soton] = 'b';
					}
				}
				break;
			}
		}
	}
	satr = satravalie;
	soton = sotonavalie;
	if (a[satravalie][sotonavalie - 1] == 'w') {
		for (soton--; soton > 0; soton--) {
			if (a[satr][soton] == 'b') {
				for (soton++; soton < sotonavalie; soton++) {
					if (a[satr][soton] == 'w') {
						lay++;
						a[satr][soton] = 'b';
					}
				}
				break;
			}
		}
	}
	satr = satravalie;
	soton = sotonavalie;
	if (a[satravalie - 1][sotonavalie] == 'w') {
		for (satr--; satr > 0; satr--) {
			if (a[satr][soton] == 'b') {
				for (satr++; satr < satravalie; satr++) {
					if (a[satr][soton] == 'w') {
						lay++;
						a[satr][soton] = 'b';
					}
				}
				break;
			}
		}
	}
	satr = satravalie;
	soton = sotonavalie;
	if (a[satravalie + 1][sotonavalie] == 'w') {
		for (satr++; satr < 9; satr++) {
			if (a[satr][soton] == 'b') {
				for (satr--; satr > satravalie; satr--) {
					if (a[satr][soton] == 'w') {
						lay++;
						a[satr][soton] = 'b';
					}
				}
				break;
			}
		}
	}
	satr = satravalie;
	soton = sotonavalie;
	if (a[satravalie + 1][sotonavalie + 1] == 'w') {
		if ((satr != 7) && (soton != 7)) {
			for (satr++, soton++; satr < 9 || soton < 9; satr++, soton++) {
				if (a[satr][soton] == 'b') {
					for (satr--, soton--; satr > satravalie || soton > sotonavalie; satr--, soton--) {
						if (a[satr][soton] == 'w') {
							lay++;
							a[satr][soton] = 'b';
						}
					}
					break;
				}
			}
		}
	}
	satr = satravalie;
	soton = sotonavalie;
	if (a[satravalie - 1][sotonavalie - 1] == 'w') {
		for (satr--, soton--; satr > 0 || soton > 0; satr--, soton--) {
			if (a[satr][soton] == 'b') {
				for (satr++, soton++; satr < satravalie || soton < sotonavalie; satr++, soton++) {
					if (a[satr][soton] == 'w') {
						lay++;
						a[satr][soton] = 'b';
					}
				}
				break;
			}
		}
	}
	satr = satravalie;
	soton = sotonavalie;
	if (a[satravalie - 1][sotonavalie + 1] == 'w') {
		if ((satr != 7) && (soton != 7)) {
			for (satr--, soton++; satr > 0 || soton < 9; satr--, soton++) {
				if (a[satr][soton] == 'b') {
					for (satr++, soton--; satr < satravalie || soton > sotonavalie; satr++, soton--) {
						if (a[satr][soton] == 'w') {
							lay++;
							a[satr][soton] = 'b';
						}
					}
					break;
				}

			}
		}
	}
	satr = satravalie;
	soton = sotonavalie;
	if (a[satravalie + 1][sotonavalie - 1] == 'w') {
		if ((satr != 0) && (soton != 0)) {
			for (satr++, soton--; satr < 8 || soton > -1; satr++, soton--) {
				if (a[satr][soton] == 'b') {
					for (satr--, soton++; satr > satravalie || soton < sotonavalie; satr--, soton++) {
						if (a[satr][soton] == 'w') {
							lay++;
							a[satr][soton] = 'b';
						}
					}
					break;
				}
			}
		}
	}
	int count = 0;
	if ((a[satr + 1][soton] != 'b') && (a[satr + 1][soton] != 'w')) {
		count++;
	}
	if ((a[satr - 1][soton] != 'b') && (a[satr - 1][soton] != 'w')) {
		count++;
	}
	if ((a[satr][soton + 1] != 'b') && (a[satr][soton + 1] != 'w')) {
		count++;
	}
	if ((a[satr][soton - 1] != 'b') && (a[satr][soton - 1] != 'w')) {
		count++;
	}
	if ((a[satr + 1][soton + 1] != 'b') && (a[satr + 1][soton + 1] != 'w')) {
		count++;
	}
	if ((a[satr - 1][soton - 1] != 'b') && (a[satr - 1][soton - 1] != 'w')) {
		count++;
	}
	if ((a[satr - 1][soton + 1] != 'b') && (a[satr - 1][soton + 1] != 'w')) {
		count++;
	}
	if ((a[satr + 1][soton - 1] != 'b') && (a[satr + 1][soton - 1] != 'w')) {
		count++;
	}
	if (count == 8) {
		return 0;
	}
	else if (lay > 0) {
		return 1;
	}
	else if (lay == 0) {
		return 0;
	}
	return 99;
}

int doerw(char a[8][8], int satr, int soton) {//jay gozarie mohre haye sefid va bargardandane mohre haye siah
	int lay = 0;
	int satravalie = satr;
	int sotonavalie = soton;
	if (a[satravalie][sotonavalie + 1] == 'b') {
		for (soton++; soton < 9; soton++) {
			if (a[satr][soton] == 'w') {
				for (soton--; soton > sotonavalie; soton--) {
					if (a[satr][soton] == 'b') {
						lay++;
						a[satr][soton] = 'w';
					}
				}
				break;
			}
		}
	}
	printf("62 is %c\n", a[5][1]);
	satr = satravalie;
	soton = sotonavalie;
	if (a[satravalie][sotonavalie - 1] == 'b') {
		for (soton--; soton > 0; soton--) {
			if (a[satr][soton] == 'w') {
				for (soton++; soton < sotonavalie; soton++) {
					if (a[satr][soton] == 'b') {
						lay++;
						a[satr][soton] = 'w';
					}
				}
				break;
			}
		}
	}
	satr = satravalie;
	soton = sotonavalie;
	if (a[satravalie - 1][sotonavalie] == 'b') {
		for (satr--; satr > 0; satr--) {
			if (a[satr][soton] == 'w') {
				for (satr++; satr < satravalie; satr++) {
					if (a[satr][soton] == 'b') {
						lay++;
						a[satr][soton] = 'w';
					}
				}
				break;
			}
		}
	}
	satr = satravalie;
	soton = sotonavalie;
	if (a[satravalie + 1][sotonavalie] == 'b') {
		for (satr++; satr < 9; satr++) {
			if (a[satr][soton] == 'w') {
				for (satr--; satr > satravalie; satr--) {
					if (a[satr][soton] == 'b') {
						lay++;
						a[satr][soton] = 'w';
					}
				}
				break;
			}
		}
	}
	satr = satravalie;
	soton = sotonavalie;
	if (a[satravalie + 1][sotonavalie + 1] == 'b') {
		if ((satr != 7) && (soton != 7)) {
			for (satr++, soton++; satr < 9 || soton < 9; satr++, soton++) {
				if (a[satr][soton] == 'w') {
					for (satr--, soton--; satr > satravalie || soton > sotonavalie; satr--, soton--) {
						if (a[satr][soton] == 'b') {
							lay++;
							a[satr][soton] = 'w';
						}
					}
					break;
				}
			}
		}
	}
	satr = satravalie;
	soton = sotonavalie;
	if (a[satravalie - 1][sotonavalie - 1] == 'b') {
		for (satr--, soton--; satr > 0 || soton > 0; satr--, soton--) {
			if (a[satr][soton] == 'w') {
				for (satr++, soton++; satr < satravalie || soton < sotonavalie; satr++, soton++) {
					if (a[satr][soton] == 'b') {
						lay++;
						a[satr][soton] = 'w';
					}
				}
				break;
			}
		}
	}
	satr = satravalie;
	soton = sotonavalie;
	if (a[satravalie - 1][sotonavalie + 1] == 'b') {
		if ((satr != 7) && (soton != 7)) {
			for (satr--, soton++; satr > 0 || soton < 9; satr--, soton++) {
				if (a[satr][soton] == 'w') {
					for (satr++, soton--; satr < satravalie || soton > sotonavalie; satr++, soton--) {
						if (a[satr][soton] == 'b') {
							lay++;
							a[satr][soton] = 'w';
						}
					}
					break;
				}

			}
		}
	}
	satr = satravalie;
	soton = sotonavalie;
	if (a[satravalie + 1][sotonavalie - 1] == 'b') {
		if ((satr != 0) && (soton != 0)) {
			for (satr++, soton--; satr < 8 || soton > -1; satr++, soton--) {
				if (a[satr][soton] == 'w') {
					for (satr--, soton++; satr > satravalie || soton < sotonavalie; satr--, soton++) {
						if (a[satr][soton] == 'b') {
							lay++;
							a[satr][soton] = 'w';
						}
					}
					break;
				}
			}
		}
	}
	int count = 0;
	if ((a[satr + 1][soton] != 'b') && (a[satr + 1][soton] != 'w')) {
		count++;
	}
	if ((a[satr - 1][soton] != 'b') && (a[satr - 1][soton] != 'w')) {
		count++;
	}
	if ((a[satr][soton + 1] != 'b') && (a[satr][soton + 1] != 'w')) {
		count++;
	}
	if ((a[satr][soton - 1] != 'b') && (a[satr][soton - 1] != 'w')) {
		count++;
	}
	if ((a[satr + 1][soton + 1] != 'b') && (a[satr + 1][soton + 1] != 'w')) {
		count++;
	}
	if ((a[satr - 1][soton - 1] != 'b') && (a[satr - 1][soton - 1] != 'w')) {
		count++;
	}
	if ((a[satr - 1][soton + 1] != 'b') && (a[satr - 1][soton + 1] != 'w')) {
		count++;
	}
	if ((a[satr + 1][soton - 1] != 'b') && (a[satr + 1][soton - 1] != 'w')) {
		count++;
	}
	if (count == 8) {
		return 0;
	}
	else if (lay > 0) {
		return 1;
	}
	else if (lay == 0) {
		return 0;
	}
	return 99;
}
int checkwin(char a[8][8]) {//taeene barande
	int satr = 0, soton = 0, countb = 0, countw = 0;

	for (satr; satr < 8; satr++) {
		for (soton; soton < 8; soton++)
			if (a[satr][soton] == 'b') {
				countb++;
			}
	}
	for (satr; satr < 8; satr++) {
		for (soton; soton < 8; soton++)
			if (a[satr][soton] == 'w') {
				countw++;
			}
	}
	if (countb > countw) {
		return 1;
	}
	else if (countb < countw) {
		return 2;
	}
	else
	{
		return 0;
	}
}






