#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>

static void
display_mallinfo(void)
{
    struct mallinfo mi;
    mi = mallinfo();
    printf("Total non-mmapped bytes (arena):       %d\n", mi.arena);
    printf("# of free chunks (ordblks):            %d\n", mi.ordblks);
    printf("# of free fastbin blocks (smblks):     %d\n", mi.smblks);
    printf("# of mapped regions (hblks):           %d\n", mi.hblks);
    printf("Bytes in mapped regions (hblkhd):      %d\n", mi.hblkhd);
    printf("Max. total allocated space (usmblks):  %d\n", mi.usmblks);
    printf("Free bytes held in fastbins (fsmblks): %d\n", mi.fsmblks);
    printf("Total allocated space (uordblks):      %d\n", mi.uordblks);
    printf("Total free space (fordblks):           %d\n", mi.fordblks);                                               printf("Topmost releasable block (keepcost):   %d\n", mi.keepcost);
}


int main()
{  
#define total 10
	int *p;
    int *q;

    printf("============== Before allocating blocks ==============\n");
    display_mallinfo();
    
    p = (int *)malloc(sizeof(int)*total);
    printf("malloc");
    q = (int *)nvm_malloc(sizeof(int)*total);
    printf("nvm_malloc\n");

    int i;
    for(i = 0;i<total;i++)
    {
        p[i] = 9-i;
        q[i] = i;
    } 
    for(i = 0;i<total;i++)
    {
        printf("%d %d\n",p[i],q[i]);
    }
    printf("\n============== After allocating blocks ==============\n");
    display_mallinfo();

    free(p);
    free(q); 

    printf("\n============== After freeing blocks ==============\n");
    display_mallinfo();
    return 0;
}
