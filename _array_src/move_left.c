/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:47:57 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/16 16:49:05 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int	move_left(char **block, int i)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	if (i < 1)
		i = 1;
	if (block[0] == '#' || block[4] == '#' || block[8] == '#' || block[12] == '#')
	{
		if (block[12] == '#' || block[8] == '#' || block[4] == '#')
		{
			if (block[0] == '#')
				return (0);
			if (block[4] == '#')
				k = 4;
			else if (block[8] == '#')
				k = 8;
			else
				k = 12;
			th(&block[0], k, 4);
			move_left(block, i);
			return (1);
		}
		else
			return (0);
	}
	th(&block[0], i, 1);
	return (1);
}
