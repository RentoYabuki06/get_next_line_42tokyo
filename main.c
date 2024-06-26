#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    close(fd);
    char *line;

    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    if (line == NULL)
    {
        printf("get_next_line returned NULL as expected for an empty file.\n");
    }

	// printf("------------");
    return (0);
}


// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include "get_next_line.h"

// void run_test_case(int fd, const char *description)
// {
//     char *line = get_next_line(fd);
//     printf("%s: %s\n", description, line ? line : "NULL");
//     if (line)
//         free(line);
// }

// int main(void)
// {
//     // Test case 1: Invalid file descriptor 1000
//     printf("Test case 1: Invalid file descriptor 1000\n");
//     run_test_case(1000, "gnl(1000, NULL)");

//     // Test case 2: Invalid file descriptor -1
//     printf("Test case 2: Invalid file descriptor -1\n");
//     run_test_case(-1, "gnl(-1, NULL)");

//     // Test case 3: Valid file descriptor, then close and call gnl again
//     int fd = open("test.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return 1;
//     }
    
//     printf("Test case 3: Valid file descriptor, then close and call gnl again\n");
//     run_test_case(fd, "gnl(fd, NULL) before close");
//     close(fd);
//     run_test_case(fd, "gnl(fd, NULL) after close");

//     return 0;
// }
