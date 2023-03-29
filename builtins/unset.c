/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manvkhac <manvkhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:09:18 by manvkhac          #+#    #+#             */
/*   Updated: 2023/03/30 00:50:25 by manvkhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(t_addres *addres, t_env **env, char **cmd)
{
	int	i;

	i = 1;
	while (cmd && cmd[i])
	{
		if (env_key_handling(cmd[i]) == 0)
			remove_node(env, cmd[i]);
		else
		{
			perror("minishell: ");
			addres->exit_status = 1;
		}
		i++;
	}
}
