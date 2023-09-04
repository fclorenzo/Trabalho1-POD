// C program to generate n random numbers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    // Open the file for writing
    FILE *file = fopen("nRand.txt", "w");

    if (!file)
    {
        perror("Error opening file");
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate and write 'n' random numbers to the file
    for (int i = 0; i < n; i++)
    {
        int randomValue = rand();
        fprintf(file, "%d\n", randomValue);
    }

    // Close the file
    fclose(file);

    printf("%d random numbers have been generated and written to 'nRand.txt'.\n", n);

    return 0;
}
