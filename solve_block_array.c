#include "fillit.h"

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

/*int		move_left(char **block, int i)
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
*/
void	solve_block_array(char ***block_arr)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (ft_strcmp("_END_", *block_arr[i]) != 0)
	{
		i++;
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
	print_puzzle(block_arr[0]);
}
