#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *infile = fopen("input.txt", "r");
    FILE *outfile = fopen("output.txt", "w");

    if (infile == NULL || outfile == NULL) {
        perror("Error opening files");
        return EXIT_FAILURE;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), infile) != NULL) {
        // Process data (Example: writing directly to output)
        fprintf(outfile, "Processed: %s", buffer);
    }

    fclose(infile);
    fclose(outfile);
    printf("File processing complete.\n");
    return EXIT_SUCCESS;
}
