/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:35:26 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/22 14:53:20 by tvandivi         ###   ########.fr       */
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
		ft_memset(tmp, '.', (size_t)(size));
		tmp[size] = 'Z';
		blank_board = ft_strjoin(blank_board, tmp);
		ft_bzero(tmp, size );
		ft_strdel(&tmp);
		i++;
	}
	new_board.solved_board = ft_strsplit(blank_board, 'Z');
	new_board.tmp_board = NULL;
	new_board.tetri_count = (size <= 26) ? size : 26;
	new_board.valid = 1;
	return (ret);
}
/*
void	store_board(char *board, int s, t_board *n_board)
{
	int		i;
	
	i = 0;
	n_board->tmp_board = (char **)malloc(sizeof(char *) * (4 * s));
	while (i < s)
	{
		n_board->tmp_board[i] = ft_strnew(5);
		ft_strncpy(n_board->tmp_board[i], (board + i), 5);
		i += 5;
	}
}*/

t_piece	*piece_lstnew(char *cont, size_t c_size, int idx)
{
	t_piece	*lst;

	lst = (t_piece *)malloc(sizeof(t_piece));
	if (!(lst))
		return (NULL);
	if (cont == NULL || c_size == 0)
	{
		lst->piece = NULL;
		lst->p_num = 0;
		lst->next = NULL;
		return (lst);
	}
	else
	{
		lst->piece = (char **)malloc((size_t)(c_size + 1));
		if (!(lst->piece))
			return (NULL);
		ft_memcpy((void *)(lst->piece), cont, c_size);
		lst->p_num = idx;
		lst->next = NULL;
		return (lst);
	}
	return (NULL);
}

int		read_file(char *file, t_board *n_board)
{
	int		fd;
	int		a;
	int		i;
	char	*buf;
	
	fd = open(file, O_RDONLY);
	a = 0;
	i = 0;
	buf = ft_strnew(21);
	if (fd > 0)
	{
		while ((a = read(fd, buf, 21)) > 0)
		{
			if (a == 20 || a == 21)
			{
				n_board->tmp_board = piece_lstnew(buf, a, i);
				i++;
			}
			else
				break ;
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
