#include "stdio.h"


  int main()
{
  int A[] = { 3, 1, 4, 2, 5 };
 
  for(int i = 1; i < 5; i++) //array starts at the 0. element
  {
    int h = A[i]; 
    int j = i;
    
    while (j > 0 && A[j-1] > h)
    {
      A[j] = A[j - 1];
      j = j - 1;
    }
    A[j] = h;
  }

  
  for (int i = 0; i < 5; i++)
  {
    printf("%d ", A[i]);
  }
  
  getchar();
  
  return 0;
}
