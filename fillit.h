#ifndef	FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/get_next_line.h"
# include "../libft/libft.h"

void	solve_block_array(char **block_arr);
void	print_puzzle(char **block_arr);
int		validate_tetrominoes(char **block);
int		move_left(char **block, int i);
char	**get_blocks(char *block);

#endif
