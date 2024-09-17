#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

// Function to compute the length of a string
int my_strlen(const char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

char* read_file(const char *filename) {
    int fd;
    ssize_t bytesRead;
    int totalSize = 0;
    char buffer[BUFFER_SIZE];
    char *fileContent = NULL;
    char *temp;

    // Open the file for reading
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the file content
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        // Allocate or reallocate memory for fileContent
        temp = (char *)malloc(totalSize + bytesRead + 1);
        if (temp == NULL) {
            perror("Error allocating memory");
            free(fileContent);
            close(fd);
            exit(EXIT_FAILURE);
        }

        if (fileContent != NULL) {
            // Copy existing content to temp
            for (int i = 0; i < totalSize; i++) {
                temp[i] = fileContent[i];
            }
            free(fileContent);
        }

        // Copy new content from buffer
        for (ssize_t i = 0; i < bytesRead; i++) {
            temp[totalSize + i] = buffer[i];
        }

        totalSize += bytesRead;
        fileContent = temp;
    }

    if (bytesRead < 0) {
        perror("Error reading file");
        free(fileContent);
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Null-terminate the string
    if (fileContent != NULL) {
        fileContent[totalSize] = '\0';
    }

    // Close the file
    close(fd);

    return fileContent;
}

// int main() {
//     const char *filename = "test.txt";
//     char *content = read_file(filename);

//     if (content != NULL) {
//         // Print the file content
//         int length = my_strlen(content);
//         write(STDOUT_FILENO, content, length);
//         // Free the allocated memory
//         free(content);
//     }

//     return 0;
// }
