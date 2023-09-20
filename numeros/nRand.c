#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    // Create the output file name
    char filename[20];
    sprintf(filename, "%dnRand.txt", n);

    // Open the file for writing
    FILE *file = fopen(filename, "w");

    if (!file)
    {
        perror("Error opening file");
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate and write 'n' random numbers to the file, respecting the limit
    for (int i = 0; i < n; i++)
    {
        int randomValue = rand() % (limit + 1); // Ensure the generated number is <= limit
        fprintf(file, "%d\n", randomValue);
    }

    // Close the file
    fclose(file);

    printf("%d random numbers (<= %d) have been generated and written to '%s'.\n", n, limit, filename);

    return 0;
}
