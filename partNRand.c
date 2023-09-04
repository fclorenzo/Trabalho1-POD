#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Shell Sort with gaps
void shellSortWithGaps(int arr[], int n)
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
    if (argc != 2)
    {
        printf("Usage: %s <number_of_values>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    if (n <= 0)
    {
        printf("Please enter a valid positive integer for the number of values.\n");
        return 1;
    }

    int *arr = malloc(sizeof(int) * n);

    if (!arr)
    {
        perror("Memory allocation error");
        return 1;
    }

    srand(time(NULL));

    // Generate 'n' random numbers
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }

    // Perform partial sorting using Shell Sort with gaps
    shellSortWithGaps(arr, n);

    // Open the file for writing
    FILE *file = fopen("partNRand.txt", "w");

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

    printf("%d partially sorted random numbers have been generated and written to 'partNRand.txt'.\n", n);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
