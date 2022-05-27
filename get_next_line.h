/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:28:45 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/27 14:57:35 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char        *get_next_line(int fd);
void        *ft_calloc(size_t nmemb, size_t size);
size_t      ft_strlen(const char *s);
char        *ft_strchr(const char *s, int c);
void        ft_bzero(void *s, size_t n);

#endif
