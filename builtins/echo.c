/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manvkhac <manvkhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:51:38 by manvkhac          #+#    #+#             */
/*   Updated: 2023/03/30 00:53:45 by manvkhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_nl(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (1);
	while (str[++i] == 'n')
		;
	if (str && str[i])
		return (0);
	return (1);
}

void	echo(char **args)
{
	int	option;
	int	i;

	if (args && !args[1])
	{
		ft_putstr_fd("\n", 1);
		return ;
	}
	option = is_nl(args[1]);
	i = option;
	while (args[++i])
	{
		if (i - option > 1)
			ft_putstr_fd(" ", 1);
		ft_putstr_fd(args[i], 1);
	}
	if (option == 0)
		ft_putstr_fd("\n", 1);
}
