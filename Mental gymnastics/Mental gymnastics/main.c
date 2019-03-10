#include <stdio.h>
#include <windows.h>
#include <math.h>

/*For a list of numbers, find the longest contiguous subsequence such that the
difference of any two consecutive elements is a prime number. (Eg. 1 1 6 8 9 => 1 6 8)*/

typedef struct {
	int length, numbers[101];
}vector;

int isPrime(int number) {
	if (number < 2 || number>2 && number % 2 == 0)
		return 0;
	for (int divisor = 3; divisor*divisor <= number; divisor += 2)
		if (number%divisor == 0)
			return 0;
	return 1;
}

vector readListSecond() {
	vector myVector; //userInput instead 
	myVector.length = 0;
	char inputCharacter;
	scanf("%d%c", &myVector.numbers[myVector.length++], &inputCharacter);
	while (inputCharacter != '\n') {
		scanf("%d%c", &myVector.numbers[myVector.length++], &inputCharacter);
	}
	return myVector;
}

void printList(int start, int finish, vector myVector) {
	for (int index = start; index <= finish; index++) {
		printf("%d ", myVector.numbers[index]);
	}
}

//computeLongestPrimeNumbersDifferenceSequence()

void computeSequence(vector myVector, int *start, int *finish){

	int currentLength = 0, maxLength = 0;
	*start = 0;
	*finish = 0;
	for (int index = 0; index < myVector.length - 1; index++) {
		if (isPrime(abs(myVector.numbers[index + 1] - myVector.numbers[index]))) {
			currentLength++;

		}
		else {
			if (currentLength > maxLength) {
				maxLength = currentLength; 
				*start = index - maxLength;
				*finish = index ;
			}
			currentLength = 0;
		}

	}
	if (currentLength > maxLength) {
		maxLength = currentLength;
		*start = myVector.length - maxLength;
		*finish = myVector.length - 1;
	}
}
int main() {
	vector myVector = readListSecond();
	int start, finish; 
	computeSequence(myVector, &start, &finish);
	printList(start, finish, myVector);
	return 0;
}