#include <stdlib.h>
#include <malloc.h>
int main()
{
	int *p;
	p = (int*)nvm_malloc(sizeof(int)*128);
	return 0;
}