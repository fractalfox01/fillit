/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:36:30 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/17 18:19:12 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../fillit.h"

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
	char	**block_arr;
	int		i;

	i = 0;
	block_arr = get_blocks(av[1]);
	if (block_arr == NULL)
	{
		ft_putstr("bad blocks...\n");
		return ;
	}
//	if (validate_tetrominoes(block_arr) == 0)
//	{
//		ft_putstr("Invalid Tetromino");
//		return ;
//	}
//	solve_block_array(block_arr);
	print_puzzle(block_arr);

//	make sure to free. hmm... think complete free needs to loop through till NULL while freeing along the way.	
	while (block_arr[i] != NULL)
	{
		free(block_arr[i++]);
		if (!(block_arr[i]))
			break ;
	}
	if (block_arr != NULL)
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
