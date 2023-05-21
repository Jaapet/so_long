/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:14:32 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/21 19:38:43 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		len;

	len = ft_strlen((char *)src);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (0);
	dup[len] = '\0';
	while (len > 0)
	{
		len--;
		dup[len] = src[len];
	}
	return (dup);
}

char	**ft_free(char **list, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

int	is_valid_char(char c)
{
	if (c != '0' && c != '1' && c != 'V')
		return (0);
	return (1);
}
