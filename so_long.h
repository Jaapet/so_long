/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:05:00 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/19 14:23:10 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/*------INSTANCE_STRUCTURE------*/
typedef struct s_game
{
	char	**map;
	int		height;
	int		width;
}	t_instance;

/*------PARSING------*/
int		get_height(char *file);
int		get_width(char *file);
char	**parse_map(char *file, int size);

/*------CHECKING------*/
int		is_ber(char *file);

/*------GNL------*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_strchri(const char *s, int c);
char	*ft_strjoin_bufs(char *s1, char const *s2);

/*------ERROR------*/
void	throw_error(void);

#endif