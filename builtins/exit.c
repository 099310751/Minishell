/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:57:04 by manvkhac          #+#    #+#             */
/*   Updated: 2023/03/29 23:59:52 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 43 || str[i] == 45)
		i++;
	if (!str[i])
		return (-1);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i])
		return (-1);
	return (0);
}

void	num_req(char *line, t_addres *cmd)
{
	if (ft_strcmp(line, "9223372036854775807") > 0)
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(line, 2);
		perror(": ");
		cmd->exit_status = 255;
		exit (cmd->exit_status);
	}
}

int	ft_abs(long double n)
{
	if (n < 0)
		n *= (-1);
	return (n);
}

int	my_exit(char **cmd, t_addres *addres)
{
	if (is_digit(cmd[1]) == 0 && !cmd[2])
	{
		num_req(cmd[1], addres);
		if (cmd[1][0] != '-' || cmd[1][0] == '+')
			addres->exit_status = ft_atoi(cmd[1]) % 256;
		else
			addres->exit_status = 256 - ft_abs(ft_atoi(cmd[1]) % 256);
	}
	else if (is_digit(cmd[1]) != 0)
	{
		perror("minishell: ");
		exit(255);
	}
	else if (cmd[2])
	{
		perror("minishell: ");
		addres->exit_status = 1;
		return (-1);
	}
	return (0);
}

void	ft_exit(char **line, t_addres *addres)
{
	if (!line[1])
	{
		ft_putstr_fd("exit\n", 2);
		exit(addres->exit_status);
	}
	if (my_exit(line, addres) == -1)
		return ;
	num_req(line[1], addres);
	change_value(&(addres->env), "?", ft_itoa(addres->exit_status));
	exit (addres->exit_status);
}
