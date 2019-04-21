/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:35:26 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/20 19:52:10 by tvandivi         ###   ########.fr       */
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

void	store_board(char *board, int s)
{
	int		size;
	t_board	n_board;

	size = s - (s * .1) / 4;
	n_board = new_board(size);
	n_board.tetri_count = size;
}

t_board	new_board(int size)
{
	t_board new_board;
	char	*blank_board;
	char	*tmp;
	int		i;

	i = 0;
	blank_board = (char *)malloc(sizeof(char) * 546);
	ft_bzero(blank_board, 545);
	// needs re-write to be a board to place pieces on. 5 x 5, 7 x 7, etc..
	while (i < 510 && i < ((size * 20) - 10))
	{
		tmp = ft_strdup(".... .... ");
		blank_board = ft_strjoin(blank_board, tmp);
		ft_bzero(tmp, 10);
		ft_strdel(&tmp);
		i += 10;
	}
	blank_board = ft_strjoin(blank_board, ".... ....");
	new_board.solved_board = ft_strsplit(blank_board, ' ');
	new_board.tmp_board = NULL;
	new_board.tetri_count = (size <= 26) ? size : 26;
	new_board.valid = 1;

	return (new_board);
}

t_board	read_file(char *file)
{
	int		fd;
	int		a;
	int		i;
	char	*buf;
	
	fd = open(file, O_RDONLY);
	a = 0;
	if (fd > 0)
	{
		if ((a = read(fd, buf, 546)) > 0)
		{
			store_board(buf, a);	
		}
		else
			return (error());
	}
	else
		return (error());
	return (new_board(42));
}

void	fillit(char *file)
{
	int		i;
	t_board	main_board;
	
	i = 0;
	if (file)
	{
		main_board = read_file(file);
		print_board(main_board.solved_board);
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
