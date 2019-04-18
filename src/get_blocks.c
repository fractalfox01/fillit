/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_blocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:50:46 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/17 18:19:09 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

/*void    free_it(char **puzzle, char **tmp, char **piece)
{
	free(*puzzle);
	*puzzle = ft_strdup(*tmp);
	free(*tmp);
	free(*piece);
}*/

int		check_horizonal(char *block)
{

}

int		check_vertical(char *block)
{

}

int		validate()
{
	
}

char	**bad_array(void)
{
	char	**bad_array;

	bad_array = ft_strsplit("invalid", ' ');
	return (bad_array);
}

char	**get_blocks(char *file_name)
{
	char	**block_array;
	int		fd;
	char	*buf;
	char	*tmp;
	int		i;
	int		j;
	int		n;
	int		b;

	fd = 0;
	i = 0;
	j = 0;
	n = 0;
	b = 0;
	block_array = (char **)malloc(sizeof(char *) * 500);
	if (file_name)
	{
		fd = open(file_name, O_RDONLY);
		if (fd)
		{
			tmp = ft_strnew(4);
			buf = ft_strnew(1);
			while (read(fd, buf, 1) > 0)
			{
				if (*buf == '.' || *buf == '#' || *buf == '\n')
				{
					if (*buf == '\n')
					{
						n++;
					}
					else if (j < 4)
					{
						if (*buf == '#')
							tmp[j++] = ('A' + b);
						else
							tmp[j++] = *buf;
					}
				}
				else
					return (bad_array());
				if (j == 4)
				{
					block_array[i] = ft_strdup(tmp);
					ft_bzero(tmp, 4);
					j = 0;
					i++;
				}
				if (n == 4)
				{
					n = -1;
					b++;
				}
			}
			block_array[i] = NULL;
		}
	}
	return (block_array);
}
