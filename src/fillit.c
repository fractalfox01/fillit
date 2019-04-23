/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:35:26 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/23 15:14:50 by tvandivi         ###   ########.fr       */
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

void	print_board(t_board *main_board)
{
	int	i;

	i = 0;
	while (i < main_board->tetra_count)
	{
		ft_putstr(main_board->solved_board[i++]);
	}
}

void	print_pieces(t_board *mst)
{
	int		i;
	t_piece	*tmp;
	t_piece	*nxt;

	i = 0;
	tmp = mst->tmp_board;
	while (tmp)
	{
		if (!(tmp->piece))
			break ;
		nxt = tmp->next;
		while (i < 4)
		{
			ft_putstr(tmp->piece[i++]);
			ft_putchar('\n');
		}
		ft_putnbr(tmp->p_num);
		ft_putchar('\n');
		i = 0;
		tmp = nxt;
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
		ft_memset(tmp, '.', (size_t)(size));
		tmp[size] = 'Z';
		blank_board = ft_strjoin(blank_board, tmp);
		ft_bzero(tmp, size );
		ft_strdel(&tmp);
		i++;
	}
	new_board.solved_board = ft_strsplit(blank_board, 'Z');
	new_board.tmp_board = NULL;
	new_board.tetra_count = (size <= 26) ? size : 26;
	new_board.valid = 1;
	return (ret);
}

int		read_file(char *file, t_board *n_board)
{
	int		fd;
	int		a;
	t_piece	*tmp;
	t_piece	*nxt;
	char	*buf;
	int		i;
	
	fd = open(file, O_RDONLY);
	a = 0;
	i = 0;
	buf = ft_strnew(21);
	if (fd > 0)
	{
		n_board->tmp_board = (t_piece *)malloc(sizeof(t_piece) * 1);
		tmp = n_board->tmp_board;
		while ((a = read(fd, buf, 21)) > 0)
		{
			if (a == 20 || a == 21)
			{
				tmp->next = (t_piece *)malloc(sizeof(t_piece) * 1);
				nxt = tmp->next;
				tmp->piece = &*ft_strsplit(buf, '\n');
				tmp->p_num = i++;
				tmp = nxt;
				ft_bzero(buf, a);
			}
			else
				return (0);
		}
/*		if ((a = read(fd, buf, 546)) > 0 && a < 546)
		{
			n_board = new_board(((a * .1) / 4));
			n_board->tetri_count = ((a * .1) / 4);
			store_board(buf, a, n_board);
		}
*/	}
	if (!(!(n_board->tmp_board)))
		return (1);
	return (0);
}

void	set_length(t_board *main_board)
{
	t_piece	*tmp;
	t_piece	*nxt;
	int		i;

	i = -1;
	tmp = main_board->tmp_board;
	while (tmp)
	{
		nxt = tmp->next;
		i++;
		tmp = nxt;
	}
	main_board->tetra_count = i;
}

int	c_chk(int k, int i, int j, char **block)
{
	int	count;

	count = 0;
	if (k % 4 != 0)
	{
		k++;
		if (ft_isalpha(block[i][j]) == 1)
			count++;
	}
	if (i >= 0 && i % 4 != 3)
	{
		if (ft_isalpha(block[i--][j]) == 1)
			count++;
	}
	return (count);
}

int	check_vertical(int i, int j, char **block)
{
	int	count;
	int	b;
	int	k;
	int dir;

	count = 0;
	b = 0;
	k = 0;
	if (i % 4 == 0 || i % 4 == 3)
	{
		if (i % 4 == 0)
			dir = 1;
		else
			dir = -1;
		b = i + 4;
		i += dir;
		if (ft_isalpha(block[i][j]) == 1 && i < b)
			count++;
		return (count);
	}
	k = i;
	return (c_chk(k, i, j, block));
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

int		verify_tetra(char **tab, int i, int j, int hash)
{
	int	count;

	count = 0;
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (tab[i][j] == '.' || tab[i][j] == '#')
			{
				if (tab[i][j] == '#')
				{
					count += check_vertical(i, j, tab);
					count += check_horizonal(i, j, tab);
					hash++;
				}
			}
			else
				return (0);
		}
		j = -1;
	}
	if ((count == 6 || count == 8) && hash == 4)
		return (1);
	return (0);
}

int		verify_file(t_board *main_board)
{
	t_piece *tmp;
	t_piece *nxt;
	int		i;

	i = 0;
	tmp = main_board->tmp_board;
	while (tmp)
	{
		nxt = tmp->next;
		if (verify_tetra(tmp->piece, -1, -1, 0) == 0)
			return (0);
		ft_putstr("Tetra is good\n");
	}
	return (1);
}

void	make_board(t_board *main_board)
{
	if (main_board)
		return ;
}

void	fillit(char *file)
{
	int		i;
	t_board	*main_board;
	
	i = 0;
	main_board = (t_board *)malloc(sizeof(t_board) * 1);
	if (file)
	{
		if(read_file(file, main_board) == 1)
		{
			set_length(main_board);
			verify_file(main_board);
			ft_putnbr(main_board->tetra_count);
			ft_putstr("\n");
		//	make_board(main_board);
		//	print_pieces(main_board);
		//	print_board(main_board);
		}
		else
			ft_putstr("What exactly are you trying to do?\n");
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
