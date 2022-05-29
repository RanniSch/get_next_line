/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:24:33 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/29 14:18:43 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dest_size;
	size_t	i;

	i = 0;
	src_size = ft_strlen(src);
	dest_size = 0;
	if (size == 0)
		return (src_size);
	while (dest_size < size && dest[dest_size])
		dest_size++;
	if (size <= dest_size)
		return (size + src_size);
	while (size && (--size - dest_size > 0) && src[i])
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (src_size + dest_size);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(num * size);
	if (!ptr)
		return (NULL);
	while (i < (num * size))
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(char *str, int ch)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == ch)
		{
			return ((char *)(str + i));
		}
		i--;
	}
	return (NULL);
}
