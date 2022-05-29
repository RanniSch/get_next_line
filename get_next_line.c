/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:16:53 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/29 14:18:41 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <fcntl.h>  // file control options (read, write, ...)
/* Read: attempts to read up to count bytes from file descriptor fd into the 
    buffer starting at buf. On success, the number of bytes read is returned 
    (zero indicates end of file), and the file position is advanced by this 
    number. If the file offset is at or past the end of file, no bytes are read, 
    and read() returns zero.*/

static char	*when_n_exists(char *return_str, char *buff);
static char	*when_starts_with_new_line(char *return_str, char *buff, char *str);
static char	*done_reading(char *return_str, int read_out);
static char	*ft_strjoin(char *s1, char *s2);

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			read_out;
	char		*return_str;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	return_str = ft_calloc(1, sizeof(char));
	read_out = 1;
	while (read_out)
	{
		if (buff[0] != '\0')
		{
			return_str = ft_strjoin(return_str, buff);
			if (ft_strrchr(return_str, '\n'))
				return (when_n_exists(return_str, buff));
		}
		read_out = read(fd, buff, BUFFER_SIZE);
		return_str = ft_strjoin(return_str, buff);
		if (read_out > 0 && ft_strrchr(return_str, '\n'))
			return (when_n_exists(return_str, buff));
		if (read_out <= 0)
			return (done_reading(return_str, read_out));
	}
	return (return_str);
}

static char	*when_n_exists(char *return_str, char *buff)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	str = ft_calloc(ft_strlen(return_str) + 1, sizeof(char));
	if (return_str[0] == '\n')
		return (when_starts_with_new_line(return_str, buff, str));
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
		buff[j] = return_str[j + i];
		j++;
	}
	buff[j] = '\0';
	free (return_str);
	return (str);
}

static char	*when_starts_with_new_line(char *return_str, char *buff, char *str)
{
	int	i;

	i = 0;
	while (return_str[i + 1])
	{
		buff[i] = return_str[i + 1];
		i++;
	}
	while (buff[i])
	{
		buff[i] = '\0';
		i++;
	}
	str[0] = '\n';
	str[1] = '\0';
	free (return_str);
	return (str);
}

static char	*done_reading(char *return_str, int read_out)
{
	if (read_out < 0)
	{
		free (return_str);
		return (NULL);
	}
	if (read_out == 0)
	{	
		if (return_str[0])
			return (return_str);
		free (return_str);
		return (NULL);
	}
	return (NULL);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	char	*dst;
	int		len1;

	i = 0;
	len1 = ft_strlen(s1);
	len = len1 + ft_strlen(s2)+ 1;
	dst = ft_calloc(len, sizeof(char));
	while (i < (len1 + 1))
	{
		dst[i] = s1[i];
		i++;
	}
	ft_strlcat(dst, s2, len);
	ft_bzero(s2, ft_strlen(s2));
	if (s1)
		free (s1);
	return (dst);
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
