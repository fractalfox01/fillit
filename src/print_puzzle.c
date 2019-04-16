/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_puzzle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:45:45 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/16 16:46:29 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void	print_puzzle(char **block_arr)
{
	int	i;

	i = 0;
	while (ft_strcmp("_END_", block_arr[i]) != 0)
	{
		ft_putstr(block_arr[i]);
		ft_putchar('\n');
		i++;
	}
}
