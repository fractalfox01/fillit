/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:36:05 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/15 18:51:37 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_vertical(int i, int j, char **block)
{
	int	count;
	int	b;
	int	k;

	count = 0;
	b = 0;
	k = 0;
	if (i % 4 == 0)
	{
		b = i + 4;
		i++;
		if (block[i][j] == '#' && i < b)
		{
			count++;
		}
		return (count);
	}
	if (i % 4 == 3)
	{
		b = i - 4;
		i--;
		if (block[i][j] == '#' && i > b)
		{
			count++;
		}
		return (count);
	}
	k = i;
	if (k % 4 != 0)
	{
		k++;
		if (block[k][j] == '#')
			count++;
	}
	if (i >= 0 && i % 4 != 3)
	{
		i--;
		if (block[i][j] == '#')
			count++;
	}
	return (count);
}

int	check_horizonal(int i, int j, char **block)
{
	int count = 0;
/*
** range limits 0 - 103
**start index is 0, 4, 8, 12
*/
	if (j == 0)
	{
		if (block[i][j + 1] == '#')
			return (1);
		else
			return (0);
	}
	if (j == 3)
	{
		if (block[i][j - 1] == '#')
			return (1);
		else
			return (0);
	}
	if (block[i][j - 1] == '#')
		count++;
	if (block[i][j + 1] == '#')
		count++;
	return (count);
}

int	validate_tetrominoes(char **block)
{
	int	i;
	int	j;
	int	k;
	int	hash;
	int	dot;
	int	count;

	i = 0;
	j = 0;
	k = 0;
	hash = 0;
	dot = 0;
	count = 0;
	while (ft_strcmp("_END_", block[i]) != 0 && i <= 103)
	{
		while (j < 4)
		{
			if (block[i][j] == '#' || block[i][j] == '.')
			{
				if (block[i][j] == '#')
				{
					count += check_vertical(i, j, block);
					count += check_horizonal(i, j, block);
					hash++;
				}
				else
					dot++;
			}
			else
			{
				printf("ret 0: 1\n");
				return (0);
			}
			j++;
			k++;
		}
		if ((((i + 1) % 4) == 0) && (dot != 12 || hash != 4))
		{
			printf("ret 0: 2\n");
			return (0);
		}
		if (((i + 1) % 4) == 0 && (count != 6 && count != 8))
		{
			printf("ret 0: 3\n");
			return (0);
		}
		if ((((i + 1) % 4) == 0) && (dot == 12 || hash == 4))
		{
			if (count == 6 || count == 8)
			{
				count = 0;
				hash = 0;
				dot = 0;
			}
			else
			{
				printf("ret 0: 1\n");
				return (0);
			}
		}
		j = 0;
		i++;
	}
	return (1);
}
