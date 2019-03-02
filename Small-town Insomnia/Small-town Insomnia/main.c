#include <stdio.h>
#include <windows.h>

int main()
{
	char string[41];
	printf("Text here:");
	scanf("%s", string);
	printf("Does this work?\n");
	printf("%s\n", string);
	system("pause");
	return 0;
}