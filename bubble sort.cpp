#include<stdio.h>

void main() 
{
    int i, n, j, temp, comp;
    int s[20];
    
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    
    for (i = 0; i < n ; i++) {
        for (j = 0; j < n -1-i; j++)
         { 
            if (s[j] > s[j + 1])
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
     {
        printf("%d ", s[i]);
    }
    printf("\n number of passes is %d\n",(n-1)) ;
    comp=n*(n-1) /2;
    printf("total number of comparison is%d",comp) ;
}
