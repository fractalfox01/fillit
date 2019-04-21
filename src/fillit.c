/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:35:26 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/21 14:05:02 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"


/*
** Bad character found: creates and returns an 'invalid' array. 
*/
char	**error(void)
{
	char	**bad_board;

	bad_board = ft_strsplit("invalid", ' ');
	return (bad_board);
}

/*
** Checks if the character read from file is a valid fillit character.
*/
int		is_valid_char(char c)
{
	if (c == '.')
		return (1);
	if (c == '#')
		return (2);
	if (c == '\n')
		return (3);
	return (0);
}

void	print_board(char **board)
{
	int	i;

	i = 0;
	while (!(!(board[i])))
	{
		ft_putstr(board[i++]);
		ft_putchar('\n');
		if (i % 4 == 0 && !(!(board[i + 1])))
			ft_putchar('\n');
	}
}

t_board	*new_board(int size)
{
	t_board new_board;
	t_board *ret;
	char	*blank_board;
	char	*tmp;
	int		i;

	i = 0;
	ret = &new_board;
	blank_board = (char *)malloc(sizeof(char) * 546);
	ft_bzero(blank_board, 545);
	// needs re-write to be a board to place pieces on. 5 x 5, 7 x 7, etc..
	while (i < size)
	{
		tmp = ft_strnew(size + 1);
		ft_memset(tmp, '.', sizeof(tmp));
		tmp[size] = '\n';
		blank_board = ft_strjoin(blank_board, tmp);
		ft_bzero(tmp, size );
		ft_strdel(&tmp);
		i++;
	}
	new_board.solved_board = ft_strsplit(blank_board, '\n');
	new_board.tmp_board = NULL;
	new_board.tetri_count = (size <= 26) ? size : 26;
	new_board.valid = 1;
	return (ret);
}

void	store_board(char *board, int s, t_board n_board)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = 0;
	j = 0;
	k = 0;
	tmp = ft_strnew(4);
	while (i < s)
	{
		if (is_valid_char(board[i]) > 0)
		{
			tmp[k] = board[j];
			if (is_valid_char(board[i]) == 3)
			{
				n_board.tmp_board[j] = tmp;
				ft_bzero(tmp, 4);
				j++;
				k = 0;
			}
			k++;
		}
		i++;
	}
}

int		read_file(char *file, t_board *n_board)
{
	int		fd;
	int		a;
	char	*buf;
	
	fd = open(file, O_RDONLY);
	a = 0;
	buf = ft_strnew(546);
	if (fd > 0)
	{
		if ((a = read(fd, buf, 546)) > 0)
		{
			n_board = new_board(((a * .1) / 4));
			n_board->tetri_count = ((a * .1) / 4);
			store_board(buf, a, *n_board);
		}
	}
	if (!(!(n_board->tmp_board)))
		return (1);
	return (0);
}

void	fillit(char *file)
{
	int		i;
	t_board	*main_board;
	
	i = 0;
	main_board = NULL;
	if (file)
	{
		if(read_file(file, main_board) == 1)
			print_board(main_board->solved_board);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		fillit(av[1]);
	}
	return (0);
}
