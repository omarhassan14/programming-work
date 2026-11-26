// ACTIVITY 4: ROBUST CSV PARSER IN C
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *file = fopen("students.csv", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not find students.csv!\n");
        return 1;
    }

    char line[256];
    printf("--- Processing Student Records ---\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        char name[40] = {0};
        char scoreStr1[16] = {0};
        char scoreStr2[16] = {0};
        char scoreStr3[16] = {0};
        int s1, s2, s3;
        char extra;

        if (line[0] == '\n' || line[0] == '\0') {
            continue;
        }

        // Read four CSV fields and reject extra trailing fields.
        int itemsRead = sscanf(line, " %39[^,],%15[^,],%15[^,],%15[^,\r\n] %c",
                               name, scoreStr1, scoreStr2, scoreStr3, &extra);

        if (itemsRead != 4) {
            printf("WARNING: Skipping malformed line format: %s", line);
            continue;
        }

        // %d%n lets us ensure each score contains only an integer.
        int n1 = 0, n2 = 0, n3 = 0;
        if (sscanf(scoreStr1, " %d %n", &s1, &n1) != 1 ||
            scoreStr1[n1] != '\0' ||
            sscanf(scoreStr2, " %d %n", &s2, &n2) != 1 ||
            scoreStr2[n2] != '\0' ||
            sscanf(scoreStr3, " %d %n", &s3, &n3) != 1 ||
            scoreStr3[n3] != '\0' ||
            s1 < 0 || s1 > 100 || s2 < 0 || s2 > 100 ||
            s3 < 0 || s3 > 100) {
            printf("WARNING: Skipping malformed record for %s (Invalid score data).\n", name);
            continue;
        }

        double average = (s1 + s2 + s3) / 3.0;
        printf("%s -> Average: %.2f\n", name, average);
    }

    if (ferror(file)) {
        fprintf(stderr, "Error while reading students.csv\n");
        fclose(file);
        return 1;
    }

    fclose(file);
    printf("\n--- Processing Complete ---\n");
    return 0;
}
