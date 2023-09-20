// Quick sort in C

#include <stdio.h>
#include <time.h>

// function to swap elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high)
{

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

// function to print array elements
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

// main function
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

    int data[500]; // Modify the size as needed
    int n = 0;
    while (fscanf(file, "%d", &data[n]) != EOF)
    {
        n++;
    }
    fclose(file);

    clock_t start_time, end_time;
    double cpu_time_used;

    printf("Unsorted Array\n");
    printArray(data, n);

    // Record the start time
    start_time = (double)clock();

    // perform quicksort on data
    quickSort(data, 0, n - 1);

    // Record the end time
    end_time = (double)clock();

    printf("Sorted array in ascending order: \n");
    printArray(data, n);

    // Calculate the execution time in milliseconds
    cpu_time_used = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000.0;
    printf("Execution Time: %.4f milliseconds\n", cpu_time_used);

    // Write the sorted data to "quickSorted.txt"
    FILE *outputFile = fopen("quickSorted.txt", "w");
    if (!outputFile)
    {
        printf("Error opening file 'quickSorted.txt' for writing.\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(outputFile, "%d\n", data[i]);
    }

    // Write the execution time to the file
    fprintf(outputFile, "Execution Time: %.4f milliseconds\n", cpu_time_used);
    fclose(outputFile);

    return 0;
}