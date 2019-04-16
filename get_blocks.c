#include "fillit.h"

void    free_it(char **puzzle, char **tmp, char **piece)
{
	free(*puzzle);
	*puzzle = ft_strdup(*tmp);
	free(*tmp);
	free(*piece);
}

char ***get_blocks(char *file_name)
{
	int		fd;
	int		i;
	char 	*piece;
	char	*puzzle;
	char	**tmptab;
	char	***tab;
	int		flag;
	int		k;
	int		len;
	int		j;

	j = 1;
	i = 0;
	k = 0;
	flag = 1;
	fd = open(file_name, O_RDONLY);
	puzzle = ft_strnew(0);

	tab = (char ***)malloc(sizeof(char *) * 3);
	tmptab = (char **)malloc(sizeof(char ) * 255);
	tab[0] = tmptab;
	while (get_next_line(fd, &piece) == 1)
	{
		flag = 0;
		len = ft_strlen(piece);
		if ((len != 4 && len != 0) || (i != 0 && (j % 5 == 0 && len != 0)))
		{
			free(tmptab);
			free(tab);
			return (NULL);
		}
		if (len == 4)
		{
			tmptab[i] = ft_strdup(piece);
			ft_strdel(&piece);
			free(piece);
			i++;
		}
		j++;
	}
	close(fd);
	if (flag)
	{
		tmptab = ft_strsplit("invalid", ' ');
		return (tab);
	}
	tmptab[i] = ft_strdup("_END_");;
	return (tab);
}
