#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SWAP(x,y,z) (x=y, y=z, z=x)
void createRandomLine(int line[]) {
	int temp=0;
	printf("Line will be mixed through alghoritm, line will be reduce to 5 people to reach different results.");

	//Filling array with values
	for (int i = 0; i < 5; i++)
	{
		line[i] = i + 1;
	}

	//Shuffle the list with fisher-yates shuffle alghoritm
	for (int i = 0; i < 5; i++)
	{
		int random = rand() % 5;
		SWAP(temp, line[i], line[random]);
	}

	printf("Your random line is: \n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", line[i]);
	}
	printf("\n");
}
int createCustomLine(int line[], int maxArrayLength, int order[]) {
	printf("\nValues you will type will be sorted between each other and will use these versions");
	int quanty = 0;
	//Getting values until enter
	while (quanty < maxArrayLength && scanf_s("%d", &line[quanty]) == 1) {
		quanty++;

		if (getchar() == '\n') {
			break;
		}
	}

	printf("Your Line is:\n");
	for (int i = 0; i < quanty; i++) {
		printf("%d ", line[i]);
	}
	printf("\n\n");

	//Sorting 
	for (int i = 0; i < quanty; i++) {
		order[i] = 1; 
		for (int j = 0; j < quanty; j++) {
			if (line[j] < line[i]) {
				order[i]++;
			}
		}
	}

	printf("Your rank ordered line is:\n");
	for (int i = 0; i < quanty; i++) {
		printf("%d ", order[i]);
	}
	printf("\n\n");
	return quanty;
}
void checkBribe(int line[], int size) {
	int bribeCounter = 0;
	//If someone brired more than 2 at the same time end the function
	for (int i = 0; i < size; i++)
	{
		if (line[i] - (i + 1) > 2) {
			printf("\nToo chaotic\n");
			return 0;
		}
	}

	for (int i = 0; i < size-1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (line[i] > line[j]) {
				bribeCounter++;
			}
		}
	}

	if (bribeCounter > 2) {
		printf("\nToo chaotic: %d\n",bribeCounter);
	}

	else {
		printf("Your bribe is: %d", bribeCounter);
	}

}


int main() {
    int maxArrayLength = 10;
	int lineChooser;
	char menu= '0';
	srand(time(NULL));

    do {
		system("cls");
		int line[10];
		int order[10];
		memset(line, 0, sizeof(line));
		memset(order, 0, sizeof(order));
		int quanty;
		printf("1-Random line\n");
		printf("2-Custom line\n");
		printf("Choose which type of line you want to use: ");
		
		scanf_s("%d", &lineChooser);
		switch (lineChooser)
		{
		case 1:
			createRandomLine(line);
			checkBribe(line,5);
			break;
		case 2:
			quanty=createCustomLine(line, maxArrayLength, order);
			checkBribe(order,quanty);
			break;
		default:
			printf("You made wrong choice\n");
			break;
		}

		printf("\nTo exit, press 0, To create another line, please press 1: ");
		do {
			if (menu != '0' && menu != '1')
			{
				printf("\nYou made the wrong choice. Please type again: ");
			}
			scanf_s(" %c", &menu);
		} while (menu != '0' && menu != '1');

	} while (menu == '1');
    return 0;
}
