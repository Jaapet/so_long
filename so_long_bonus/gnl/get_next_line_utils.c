/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:39:51 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/23 13:45:32 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// allocates memory for 'nmemb' elements of 'size' size
// assigns 0 to all the allocated memory
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*a;
	size_t	i;

	if ((size == SIZE_MAX && nmemb > 1) || (nmemb == SIZE_MAX && size > 1))
		return (NULL);
	a = malloc(size * nmemb);
	if (!a)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		a[i] = 0;
		i++;
	}
	return (a);
}

// assigns 0 to the 1st 'n' elements in a void*
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

// returns the index of the 1st occurence of a char in a char*
// if nothing is found, it returns the size of the char*
int	ft_strchri(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (i);
}

// concatenates char* 'src' in char* 'dst'
static size_t	ft_strlcat_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	dstlen = ft_strchri(dst, '\0');
	if (dstsize <= dstlen)
		return (ft_strchri(src, '\0') + dstsize);
	while (src[i] && dstlen + i < dstsize - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + ft_strchri(src, '\0'));
}

// concatenates 2 char* in a new char*
// frees the args and returns the new char*
char	*ft_strjoin_bufs(char *s1, char const *s2)
{
	char	*str;
	size_t	len;

	len = ft_strchri(s1, '\0') + ft_strchri(s2, '\0');
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	*str = '\0';
	ft_strlcat_gnl(str, s1, len + 1);
	ft_strlcat_gnl(str, s2, len + 1);
	free(s1);
	return (str);
}
