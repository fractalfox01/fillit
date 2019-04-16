/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:36:30 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/15 18:49:19 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_description(void)
{
	int		fd;
	int		a;
	char	*line;

	fd = open("description.txt", O_RDONLY);
	ft_putstr(FT_BLUE);
	while ((a = get_next_line(fd, &line)) == 1)
	{
		ft_putstr(line);
		ft_putstr("\n");
	}

}

void	fillit(char **av)
{
	char	***block_arr;
	int		i;

	i = 0;
	block_arr = get_blocks(av[1]);
	if (block_arr == NULL)
	{
		ft_putstr("bad blocks...\n");
		return ;
	}
	if (validate_tetrominoes(block_arr[0]) == 0)
	{
		ft_putstr("Invalid Tetromino");
		return ;
	}
	solve_block_array(&block_arr[0]);
	
//	make sure to free. hmm... think complete free needs to loop through till NULL while freeing along the way.	
	while (ft_strcmp("_END_", *block_arr[i]) != 0)
	{
		free(block_arr[i++]);
	}
	free(block_arr);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		fillit_description();
	}
	if (ac == 2)
	{
		fillit(av);
	}
	return (0);
}
