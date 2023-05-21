/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:21:31 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/21 20:04:56 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_putchar(char c)
{
	write(2, &c, 1);
}

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	throw_error(char *msg)
{
	write(2, "Error\n", 6);
	ft_putstr(msg);
	exit(EXIT_FAILURE);
}

void	throw_msg(char c)
{
	if (c == 'E')
		ft_printf("Success\n");
	else if (c == 'V')
		ft_printf("You died\n");
	exit(0);
}
