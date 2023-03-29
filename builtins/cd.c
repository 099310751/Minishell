/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manvkhac <manvkhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:52:53 by manvkhac          #+#    #+#             */
/*   Updated: 2023/03/30 00:52:58 by manvkhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(char	**path, t_env *env)
{
	char	cwd[1024];
	char	*new_path;
	char	*old_pwd;

	if (path && (!path[1] || path[2]))
	{
		perror("cd: ");
		return ;
	}
	old_pwd = getcwd(cwd, sizeof(cwd));
	change_flag(&env, "OLDPWD", 0);
	change_value(&env, "OLDPWD", ft_strdup(old_pwd));
	if (chdir(path[1]) == 0)
	{
		new_path = getcwd(cwd, sizeof(cwd));
		change_value(&env, "PWD", ft_strdup(new_path));
	}
	else
		perror("cd: ");
}
