// Counting sort in C programming

#include <stdio.h>
#include <time.h>

void countingSort(int array[], int size)
{
  int output[10];

  // Find the largest element of the array
  int max = array[0];
  for (int i = 1; i < size; i++)
  {
    if (array[i] > max)
      max = array[i];
  }

  // The size of count must be at least (max+1) but
  // we cannot declare it as int count(max+1) in C as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int count[10];

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i)
  {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++)
  {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++)
  {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--)
  {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++)
  {
    array[i] = output[i];
  }
}

// Function to print an array
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Driver code
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  char *filename = argv[1];
  FILE *file = fopen(filename, "r");

  if (!file)
  {
    printf("Error opening file '%s'\n", filename);
    return 1;
  }

  int array[500]; // Modify the size as needed
  int n = 0;
  while (fscanf(file, "%d", &array[n]) != EOF)
  {
    n++;
  }
  fclose(file);

  clock_t start_time, end_time;
  double cpu_time_used;

  printf("Unsorted Array\n");
  printArray(array, n);

  // Record the start time
  start_time = clock();

  countingSort(array, n);

  // Record the end time
  end_time = clock();

  printf("Sorted array in ascending order: \n");
  printArray(array, n);

  // Calculate the execution time in seconds
  cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  printf("Execution Time: %f seconds\n", cpu_time_used);
  return 0;
}