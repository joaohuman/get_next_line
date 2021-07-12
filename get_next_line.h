/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:32:21 by jvictor-          #+#    #+#             */
/*   Updated: 2021/07/12 20:24:02 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/resource.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

# define GNL_ERROR -1
# define GNL_FOUND_LINEBREAK 1
# define GNL_FOUND_EOF 0
# define MAX_FILE_DESCRIPTOR RLIMIT_NOFILE
# define HAV_BRK_LINE 1
# define HAVNT_BRK_LINE 0
# define READ_AND_JOINED_OR_EOF 1
# define GNL_SUCCESSFULL 1

/**
 * @brief Allocates memory space by the number of elements (nmemb)
 * and size (size) in bytes erasing what was previously in that 
 * memory space.
 *  
 * @param nmemb Number of elements.
 * @param size Size in bytes. ex: (sizeof(int)).
 * @return void* The pointer to the allocated memory.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Scan the string (*s) for a charactere (c)
 * *BREAK LINE
 * 
 * @param s String to be scanned.
 * @param c Character fetched.
 * @return int HAV_BRK_LINE (1) or HAVNT_BRK_LINE (0)
 */
int		ft_strchr_GNL(char *s, char c);

/**
 * @brief Concatenates the strings (*s1) and (*s2) to a new String.
 * 
 * @param s1 First string to concatenate.
 * @param s2 Second string to concatenate.
 * @return char* The new string or NULL.
 */
char	*ft_strjoin(char*s1, char *s2);

/**
 * @brief Count the number of the characters in the (*str)
 * excepted the NULL byte.
 * 
 * @param str String to be counted.
 * @return size_t Number of characters of the (*str).
 */
int		ft_strlen(char *str);

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string (*s)
 * The substring begins at index (start) and is of maximum size (len).
 * 
 * @param s String source.
 * @param start Initial index .
 * @param len The maximum length of the substring.
 * @return char* The substring or Null if the allocation fails.
 */
char	*ft_substr(char *s, unsigned int start, size_t len);

int		get_next_line(int fd, char **line);

size_t	ft_strlcpy(char *dst, char *src, size_t size);

#endif