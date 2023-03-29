/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:48:38 by manvkhac          #+#    #+#             */
/*   Updated: 2023/03/30 00:23:40 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		ft_putstr_fd(env[i], 1);
		write(1, "\n", 1);
	}
}

int	env_handling(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (ft_strcmp(s[i], "env") != 0)
			return (i);
	}
	return (-1);
}

void	ft_env(char **line, t_addres *cmd)
{
	int		i;
	char	**env;
	t_env	*temp;
	char	**get_line;

	i = 0;
	temp = cmd->env;
	get_line = line;
	if (env_handling(get_line) != -1)
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(get_line[env_handling(get_line)], 2);
		perror(": ");
		cmd->exit_status = 127;
	}
	else if (env_handling(get_line) == -1)
	{
		env = list_to_char(cmd);
		print_env(env);
		free_mtx(env);
		cmd->exit_status = 0;
	}
	temp = temp->next;
}
