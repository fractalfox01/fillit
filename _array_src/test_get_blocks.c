/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_blocks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:56:23 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/16 16:56:27 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h" 

int	main(int ac, char **av)
{
	char	***ret;
	int		i;

	i = 0;
	if (ac == 2)
	{
		ret = get_blocks(av[1]);
		
		if (ret != NULL)
		{
			while (ret[0][i] != NULL)
			{
				if (i % 4 == 0)
					ft_putstr("\n");
				ft_putstr(ret[0][i]);
				ft_putstr("\n");
				i++;
			}
			free(ret[0]);
			free(ret);
		}
		else
			printf("Bad fillit file.\n");
	}
	else
	{
		printf("Takes a file of suffix .fillit\n");
	}
	return (0);
}
