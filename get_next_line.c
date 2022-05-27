/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:16:53 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/27 14:53:43 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <fcntl.h>  // file control options (read, write, ...)
/* Read: attempts to read up to count bytes from file descriptor fd into the 
    buffer starting at buf. On success, the number of bytes read is returned 
    (zero indicates end of file), and the file position is advanced by this 
    number. If the file offset is at or past the end of file, no bytes are read, 
    and read() returns zero.*/

/* we have a string so nmemb = 1 and size = size of char */

static char	*string_to_n(char *return_str, char *buff);
static char	*newline_after_n(char *return_str, char *buff, char *str);
static char	*done_reading(char *return_str, int read_out);
static char	*ft_strjoin_gnl(char *s1, char *s2);

static char	*ft_strjoin_gnl(char *s1, char *s2)
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
	while (*(s1 + i) != 0)
	{
		*(dest + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j) != 0)
	{
		*(dest + i + j) = *(s2 + j);
		j++;
	}
	*(dest + i + j) = '\0';
	return (dest);
}

static char    *string_to_n(char *return_str, char *buf)
{
    int		i;
	char	*str;
	int		j;

	i = 0;
	str = ft_calloc(ft_strlen(return_str) + 1, sizeof(char));
	if (return_str[0] == '\n')
		return (newline_after_n(return_str, buf, str));
    while (return_str[i] != '\n')
	{
		str[i] = return_str[i];
		i++;
	}
	str[i] = '\n';
	i++;
	j = 0;
	while (return_str[j + i])
	{
		buf[j] = return_str[j + i];
		j++;
	}
	buf[j] = '\0';
	free (return_str);
	return (str);
}

static char    *newline_after_n(char *return_str, char *buf, char *str)
{
    int	i;

	i = 0;
	while (return_str[i + 1])
	{
		buf[i] = return_str[i + 1];
		i++;
	}
	while (buf[i])
	{
		buf[i] = '\0';
		i++;
	}
	str[0] = '\n';
	str[1] = '\0';
	free (return_str);
	return (str);
}

static char	*done_reading(char *return_str, int bytes)
{
	if (bytes < 0)
	{
		free (return_str);
		return (NULL);
	}
	if (bytes == 0)
	{	
		if (return_str[0])
			return (return_str);
		free (return_str);
		return (NULL);
	}
	return (NULL);
}

char    *get_next_line(int fd)
{
    char    *return_str;
    char    *buf;
    static char    buffer[BUFFER_SIZE + 1];    // variable size vom buffer + 1 für Nullbyte
    int     bytes;

    if (fd < 0 || fd >= 4096)
        return (NULL);
    buf = &buffer[0];
    return_str = ft_calloc(1, sizeof(char));
    bytes = 1;
    while (bytes)   // if bytes = zero -> end of file; bytes don't exsist anymore
    {
        if (buf[0] != '\0')
		{
			return_str = ft_strjoin_gnl(return_str, buf);
			if (ft_strchr(return_str, '\n'))
				return (string_to_n(return_str, buf));
		}
        bytes = read(fd, buf, BUFFER_SIZE);  // jedes byte inkl. \n wird gezählt bis \0 (das dann nicht mehr); bytes = -1 error (z.B. kein File gefunden); bytes = 0 (End of File is reached)
        printf("bytes: %d", bytes);
        return_str = ft_strjoin_gnl(return_str, buf);  // Ein Buchstabe aus buf und ein Platz aus calloc kommt in return_str
        if (bytes > 0 && ft_strchr(return_str, '\n'))
            return(string_to_n(return_str, buf));
        if (bytes <= 0)
            return (done_reading(return_str, bytes));
    }
    return (return_str); // the line that was read
}

/*int main()
{
    int fd;

    fd = open("test1.txt", O_RDWR);         // hier wird der file geöffnet.
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    close(fd);                              // hier wird der file geschlossen, am Ende der gesamten Operation!
    return (0);
}*/
