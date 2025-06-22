#include <stdio.h>
#include <stdlib.h>

// Function to create and write data to a file
void createAndWriteFile() {
    FILE *fp;
    char filename[100], data[1000];

    printf("Enter the filename to create and write: ");
    scanf("%s", filename);
    getchar(); // Clear newline character from buffer

    fp = fopen(filename, "w"); // Open file in write mode (creates or overwrites)
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter data to write into the file:\n");
    fgets(data, sizeof(data), stdin);
    fprintf(fp, "%s", data);

    fclose(fp);
    printf("File '%s' created and data written successfully.\n", filename);
}

// Function to read data from a file
void readFile() {
    FILE *fp;
    char filename[100], ch;

    printf("Enter the filename to read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r"); // Open file in read mode
    if (fp == NULL) {
        printf("Error opening file or file does not exist!\n");
        return;
    }

    printf("Contents of '%s':\n", filename);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
}

// Function to append data to a file
void appendToFile() {
    FILE *fp;
    char filename[100], data[1000];

    printf("Enter the filename to append data to: ");
    scanf("%s", filename);
    getchar(); // Clear newline character

    fp = fopen(filename, "a"); // Open file in append mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter data to append to the file:\n");
    fgets(data, sizeof(data), stdin);
    fprintf(fp, "%s", data);

    fclose(fp);
    printf("Data appended to '%s' successfully.\n", filename);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== File Operations Menu =====\n");
        printf("1. Create and Write to a File\n");
        printf("2. Read a File\n");
        printf("3. Append Data to a File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character

        switch (choice) {
            case 1:
                createAndWriteFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                appendToFile();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
