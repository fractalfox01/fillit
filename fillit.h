#ifndef	FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/get_next_line.h"
# include "../libft/libft.h"

void	solve_block_array(char ***block_arr);
char	***get_blocks(char *block);
int		validate_tetrominoes(char **block);

#endif
