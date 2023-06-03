#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char* exit_message = "EXIT\n";
    int assigned_to_buffer = 0;
    int buffer_size = 4;
    char *buffer = malloc(sizeof(char) * buffer_size);

    size_t assigned_to_new_buffer;
    char *newBuffer = malloc(sizeof(char) * 256);

    while (1) {
        fgets(newBuffer, 256, stdin);

        if (strcmp(newBuffer, exit_message) == 0) {
            printf("%s", buffer);
            break;
        }

        assigned_to_new_buffer = strlen(newBuffer);

        while (assigned_to_new_buffer > buffer_size - assigned_to_buffer) {
            buffer_size = buffer_size * 2;
            buffer = realloc(buffer, buffer_size);
            printf("Changed buffer size to %d\r\n", buffer_size);

            if (buffer == NULL) {
                printf("Could not allocate memory.");
                exit(EXIT_FAILURE);
            }
        }

        strcat(buffer, newBuffer);
        assigned_to_buffer += assigned_to_new_buffer;
    }

    printf("%s", buffer);
    printf("Buffer size: %d", buffer_size);

    return 0;
}