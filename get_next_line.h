/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:28:45 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/29 14:18:37 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_calloc(size_t num, size_t size);
size_t	ft_strlen(const char *c);
char	*ft_strrchr(char *str, int ch);

#endif
