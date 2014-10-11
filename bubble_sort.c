#include <stdio.h>

int rry[] = {5,2,3,6,4,1};
int len = 6;


void bubble();
void check();

int main()
{
  printf("bubble:   ");
  bubble(rry);
  check(rry);

  return 0;
}

void check()
{
  int ok = 1;
  for (int i = 0; i < len; i++)
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

void bubble()
{
  int temp;
  int i;
  for(i = 0; i < len - 1; i++)
  {
    int j;
    for(j = i + 1; j < len; j++)
    {
      if(rry[i] > rry[j])
      {
        temp = rry[j];
        rry[j] = rry[i];
        rry[i] = temp;
      }
    }
  }
}
