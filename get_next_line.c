/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:16:53 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/26 13:53:26 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  // file control options (read, write, ...)
/* Read: attempts to read up to count bytes from file descriptor fd into the 
    buffer starting at buf. On success, the number of bytes read is returned 
    (zero indicates end of file), and the file position is advanced by this 
    number. If the file offset is at or past the end of file, no bytes are read, 
    and read() returns zero.*/

/* we have a string so nmemb = 1 and size = size of char */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
    size_t  mem;
    size_t  i;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (nmemb >= __SIZE_MAX__ || size >= __SIZE_MAX__)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
    mem = nmemb * size;
    i = 0;
    while (i < mem)
    {
        ((char *)ptr)[i] = 0;
        i++;
    }
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*(s + count) != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	dest = malloc(1 * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	if (dest == NULL)
		return (NULL);
	/*while (*(s1 + i) != 0)
	{
		*(dest + i) = *(s1 + i);
		i++;
	}*/
	while (*(s2 + j) != 0)
	{
		*(dest + i + j) = *(s2 + j);
		j++;
	}
	*(dest + i + j) = '\0';
	return (dest);
}

char    *get_next_line(int fd)
{
    char    *return_str;
    char    *buf;
    char    buffer[BUFFER_SIZE + 1];    // variable size vom buffer + 1 für Nullbyte
    int     bytes;

    buf = &buffer[0];
    return_str = ft_calloc(1, sizeof(char));
    /*if (fd == -1)
        exit(1);*/
    /* Loop von einem Index zum nächsten für eine Line aus File bis \n und dann printen mit strjoin??? */
    bytes = 1;
    while (bytes != 0)   // if bytes = zero -> end of file; bytes don't exsist anymore
    {
        bytes = read(fd, buf, BUFFER_SIZE); // jedes byte für eine Zeile wird durchgegangen.
        return_str = ft_strjoin(return_str, buf);  // Ein Buchstabe aus buf und ein Platz aus calloc kommt in return_str
        //printf("\nTest:%s\n", return_str);
    }

    buf[BUFFER_SIZE + 1] = '\0';
    return (return_str); // the line that was read
}

int main()
{
    int fd;

    fd = open("test1.txt", O_RDWR);         // hier wird der file geöffnet.
    printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    close(fd);                              // hier wird der file geschlossen, am Ende der gesamten Operation!
    return (0);
}
