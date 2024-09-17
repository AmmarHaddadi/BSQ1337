#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define OUTPUT_BUFFER_SIZE 50

void writeInt(int value) {
    char buffer[12];
    int length = 0;
    int temp = value;

    if (temp < 0) {
        buffer[length++] = '-';
        temp = -temp;
    }

    char rev[11];
    int revIndex = 0;
    do {
        rev[revIndex++] = (temp % 10) + '0';
        temp /= 10;
    } while (temp > 0);

    for (int i = revIndex - 1; i >= 0; --i) {
        buffer[length++] = rev[i];
    }

    buffer[length++] = '\n';

    write(1, buffer, length);
}

void writeChar(char value) {
    char buffer[2] = {value, '\n'};
    write(1, buffer, 2);
}

void readMapFile(const char* filename, int* numLines, char* emptyChar, char* obstacleChar, char* fullChar) {
    int fd = open(filename, 0);
    if (fd < 0) {
        write(2, "Error opening file\n", 20);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead < 0) {
        write(2, "Error reading file\n", 19);
        close(fd);
        exit(EXIT_FAILURE);
    }

    buffer[bytesRead] = '\0';

    char* ptr = buffer;
    *numLines = 0;
    while (*ptr >= '0' && *ptr <= '9') {
        *numLines = (*numLines * 10) + (*ptr - '0');
        ptr++;
    }
    *emptyChar = *ptr++;
    *obstacleChar = *ptr++;
    *fullChar = *ptr;

    if (close(fd) < 0) {
        write(2, "Error closing file\n", 19);
        exit(EXIT_FAILURE);
    }
}
