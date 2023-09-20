#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Shell Sort with gaps
void shellSort(int arr[], int n)
{
    int gaps[8] = {701, 301, 132, 57, 23, 10, 4, 2};

    for (int gapIndex = 0; gapIndex < 8; gapIndex++)
    {
        int gap = gaps[gapIndex];

        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <number_of_values> <limit>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int limit = atoi(argv[2]);

    if (n <= 0 || limit <= 0)
    {
        printf("Please enter valid positive integers for the number of values and the limit.\n");
        return 1;
    }

    int *arr = malloc(sizeof(int) * n);

    if (!arr)
    {
        perror("Memory allocation error");
        return 1;
    }

    srand(time(NULL));

    // Generate 'n' partially sorted random numbers within the specified limit
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (limit + 1); // Ensure the generated number is <= limit
    }

    // Perform partial sorting using Shell Sort with gaps
    shellSort(arr, n);

    // Create the output file name
    char filename[20];
    sprintf(filename, "%dnPartRand.txt", n);

    // Open the file for writing
    FILE *file = fopen(filename, "w");

    if (!file)
    {
        perror("Error opening file");
        return 1;
    }

    // Write the partially sorted random numbers to the file
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d\n", arr[i]);
    }

    // Close the file
    fclose(file);

    printf("%d partially sorted random numbers (<= %d) have been generated and written to '%s'.\n", n, limit, filename);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
