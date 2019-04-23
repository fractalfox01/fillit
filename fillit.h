/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:25:17 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/23 13:09:25 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/get_next_line.h"
# include "../libft/libft.h"

typedef struct			s_tetfile
{
	char				**piece;
	int					p_num;
	struct s_tetfile	*next;
}						t_piece;

typedef struct			s_board
{
	char				**solved_board;
	t_piece				*tmp_board;
	int					tetra_count;
	int					valid;
}						t_board;

void					solve_block_array(char **block_arr);
void					print_puzzle(char **block_arr);
int						validate_tetrominoes(char **block);
int						move_left(char **block, int i);
char					**get_blocks(char *block);

#endif
