// Counting sort in C programming

#include <stdio.h>
#include <time.h>

#define MAX 100000000

void countingSort(int array[], int size)
{
    int output[MAX];

    // Find the largest element of the array
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    int count[max + 1];

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

    int array[MAX]; // Modify the size as needed
    int n = 0;
    while (fscanf(file, "%d", &array[n]) != EOF)
    {
        n++;
    }
    fclose(file);

    countingSort(array, n);

    return 0;
}