#include <stdio.h>

/*quick_sort is a divide and conquer algorithm
   - as a first step it divides the array into 2 halfs 
     and then give the smaller elments to the left side and bigger to the right.
   - as the second step it conquers the partitions like step one.
*/

//--------------------------------------------------------
//@param arr[]: needs the array for printing the content
//@param size: needs the size of the array
void display(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);

  printf(" ");
}

//--------------------------------------------------------
//@param arr[]: needs the array for swapping the content
//@param left: needs the first element of the array
//@param right: needs the last element of the array
void quickSort(int arr[], int left, int right)
{
  int i = left;                                    
  int j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];              //needs the middle of the array, called pivot
                                                    //needed later on to sort all elements, which are bigger 
                                                    //than the middle all smaller and makes it half/half for the first
                                                    //sorting
  while (i <= j)
  {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j)                                     //swapping
    {
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
      i++;
      j--;
    }
    if (left < j)                                   //sorts the partition left
      quickSort(arr, left, j);
    if (i < right)                                  //sorts the partition right
      quickSort(arr, i, right);
    
  }
}


int main()
{
  int A[] = { 3, 2, 5, 9, 1, 7, 8 };
  int len = 7;

  printf("Unsorted array: \n");
  display(A, len);

  printf("\n\nSorted array: \n");
  quickSort(A, 0, len-1);
  display(A, len);


  getchar();
  return 0;
}
