/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:24:33 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/27 14:57:11 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*void	*ft_calloc(size_t nmemb, size_t size)
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
}*/

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		*(p + i) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

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
	ft_bzero(ptr, nmemb * size);
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

/* Locates character in string. Returns a pointer to the first occurrence of 
	the matched character c in string s or NULL if the character is not found. 
	The terminating null byte is considered part of the string. */
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = ft_strlen(s);
	while (count >= 0)
	{
		if (*(s + count) == (char)c)
		{
			return ((char *)(s + count));
		}
		count--;
	}
	return (NULL);
}*/