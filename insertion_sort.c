#include "stdio.h"
/*
  Insertion Sort
  The for loop goes over the whole array. 
  The inner loop (while) checks if the previous value of i is bigger, if
  yes, then it shifts it to the left and checks it everytime.
  After that the for loop increases one and it starts from the beginning
*/
int main()
{
  int A[] = { 3, 1, 4, 2, 5 };
  //--------------------------------------------------------
  //bubblesort algorithm
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
  
  //--------------------------------------------------------
  //prints the result
  for (int i = 0; i < 5; i++)
  {
    printf("%d ", A[i]);
  }
  
  getchar();
  return 0;
}
