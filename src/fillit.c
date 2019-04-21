/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:35:26 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/20 18:12:51 by tvandivi         ###   ########.fr       */
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

void	store_piece(t_board main_board, int i, char c)
{
	ft_putstr(main_board.board[i]);
	ft_putstr("\n");
	ft_putnbr(c);
	ft_putstr("\n");
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
	while (i < 510)
	{
		tmp = ft_strdup(".... .... ");
		blank_board = ft_strjoin(blank_board, tmp);
		ft_bzero(tmp, 10);
		ft_strdel(&tmp);
		i += 10;
		if (i >= ((size * 20) - 10))
			break ;
	}
	blank_board = ft_strjoin(blank_board, ".... ....");
	new_board.board = ft_strsplit(blank_board, ' ');
	new_board.tetri_count = size;
	new_board.valid = 1;

	return (new_board);
}

t_board	read_file(char *file)
{
//	int		fd;
//	int		a;
//	int		i;
//	char	*buf;
	
/*	fd = open(fd, O_RDONLY);
	a = 0;
	if (fd > 0)
	{
		while (a = read(fd, buf, 546) > 0)
		{
			if (a == 546)
			{
				return (error());
			}
			if ((a = is_valid_char(buf)) > 0)
			{
				store_piece(main_board, i, buf);
				i++;
			}
		}
	}
	else
		return (error());
*/
	if (file)
		;
	return (new_board(7));
}

void	fillit(char *file)
{
	int		i;
	t_board	main_board;
	
	i = 0;
	if (file)
	{
		main_board = read_file(file);
		while (i < (main_board.tetri_count * 4))
		{
			ft_putstr(main_board.board[i++]);
			ft_putchar('\n');
			if (i % 4 == 0)
				ft_putstr("\n");
		}
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
