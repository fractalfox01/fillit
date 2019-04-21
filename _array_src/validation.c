/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:36:05 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/17 18:19:14 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

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
		if (ft_isalpha(block[i][j]) == 1 && i < b)
		{
			count++;
		}
		return (count);
	}
	if (i % 4 == 3)
	{
		b = i - 4;
		i--;
		if (ft_isalpha(block[i][j]) == 1 && i > b)
		{
			count++;
		}
		return (count);
	}
	k = i;
	if (k % 4 != 0)
	{
		k++;
		if (ft_isalpha(block[i][j]) == 1)
			count++;
	}
	if (i >= 0 && i % 4 != 3)
	{
		i--;
		if (ft_isalpha(block[i][j]) == 1)
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
		if (ft_isalpha(block[i][j + 1]) == 1)
			return (1);
		else
			return (0);
	}
	if (j == 3)
	{
		if (ft_isalpha(block[i][j - 1]) == 1)
			return (1);
		else
			return (0);
	}
	if (ft_isalpha(block[i][j - 1]) == 1)
		count++;
	if (ft_isalpha(block[i][j + 1]) == 1)
		count++;
	return (count);
}

int	validate_tetrominoes(char **block)
{
	int	i;

	i = 0;
	while (block[i])
	{
		while (block[i][j] == '.')
			j++;
		if (ft_isalpha(block[i][j]) == 1)
		{
			// validate horizonal and vertical
		}
		else if (block[i][j] == '\n')
			i++;
	}
}
