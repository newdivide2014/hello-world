#include <stdio.h>
#include "add.h"

int main()
{
	int (*func)(int, int) = add;
	int num = func(1, 2);
	printf("num=%d\n", num);
	
	printf("hello world.\n");
	return 0;
}

