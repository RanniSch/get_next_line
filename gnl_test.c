#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  // file control options (read, write, ...)

char    *get_next_line(int fd)
{
    char    *buf;
    char    buffer[BUFFER_SIZE + 1];    // variable size vom buffer + 1 für Nullbyte
    int     bytes;
    int     i;

    buf = &buffer[0];
    i = 0;
    bytes = 1;
    while (bytes)
    {
        while (buf[i] != '\n')
        {
            bytes = read(fd, buf, 1);
            i++;
            printf("bytes: %d\n", bytes);
            return (buf);
        }
    }
    
    buf[BUFFER_SIZE + 1] = '\0';
    return (buf); // the line that was read
}

int main()
{
    int fd;

    fd = open("test1.txt", O_RDWR);         // hier wird der file geöffnet.
    printf("%s", get_next_line(fd));
    close(fd);                              // hier wird der file geschlossen, am Ende der gesamten Operation!
    return (0);
}
