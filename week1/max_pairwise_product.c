#include <stdlib.h>
#include <stdbool.h>

long long int maxPairwiseProduct(int numbers[], int n)
{
    int maxIndex1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] > numbers[maxIndex1])
        {
            maxIndex1 = i;
        }
    }
    int maxIndex2 = (maxIndex1 == 0)? 1 : 0;
    for (int j = 0; j < n; j++)
    {
        if ((numbers[j] > numbers[maxIndex2]) && (j != maxIndex1))
        {
            maxIndex2 = j;
        }
    }
    return ((long long int)numbers[maxIndex1]) * numbers[maxIndex2]; 
}

int main(int argc, char** argv) 
{
    int n;    
    scanf("%d", &n); 
  
    int numbers[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }
    
    printf("%lld\n", maxPairwiseProduct(numbers, n)); 

    return (EXIT_SUCCESS);
}
