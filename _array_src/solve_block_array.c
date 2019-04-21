/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_block_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:50:26 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/17 12:01:59 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void	th(char *block, int i, int minus)
{
	while (i <= 15)
	{
		// shift block one space to the left.
		if (block[i] == '#')
		{
			block[i - minus] = '#';
			if (block[i + 1] != '#')
			{
				block[i] = '.';
				i++;
			}
			else if (minus == 4)
				block[i] = '.';
		}
		i++;
	}
}

void	solve_block_array(char **block_arr)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (block_arr[i])
	{
		i++;
		if (!(block_arr[i]))
			break ;
	}
	while (k < i)
	{
		while (j < 4)
		{
//			if (move_left(block_arr[0][j], 0) == 1)
			j++;
//			else
//				break ;
		}
		k++;
	}
	print_puzzle(block_arr);
}
