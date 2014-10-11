#include <stdio.h>




//--------------------------------------------------------
//Function bubble()
void bubble(int rry[], int size)
{
  int temp;
  int i;
  for (i = 0; i < size - 1; i++)
  {
    int j;
    for (j = i + 1; j < size; j++)
    {
      if (rry[i] > rry[j])
      {
        temp = rry[j];
        rry[j] = rry[i];
        rry[i] = temp;
      }
    }
  }
}

//--------------------------------------------------------
//Function check()
//prints the test result
void check(int rry[], int size)
{
  int ok = 1;
  for (int i = 0; i < size; i++)
  {
    printf("%d", rry[i]);

    if (rry[i] != (i + 1))
      ok = 0;
  }

  if (ok)
    printf(" PASS\n");
  else
    printf(" FAIL\n");
}

int main()
{
  int A[] = { 5, 2, 3, 6, 4, 1 };                              // also srand possible for random numbers
  int len = 6;
  printf("bubble:   ");
  bubble(A, len);
  check(A, len);

  getchar();
  return 0;
}
