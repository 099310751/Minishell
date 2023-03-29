/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manvkhac <manvkhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:54:06 by manvkhac          #+#    #+#             */
/*   Updated: 2023/03/30 00:54:07 by manvkhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_key_handling(char *s)
{
	int	i;

	i = -1;
	if (s && *s && (*s == '_' || (*s >= 'a' && *s <= 'z') || \
	(*s >= 'A' && *s <= 'Z')))
	{	
		while (s && s[++i])
			if (!(s[i] == '_' || (s[i] >= 'a' && s[i] <= 'z') || \
			(s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')))
				return (-1);
	}
	else
		return (-1);
	return (0);
}

void	remove_needle_node(t_env **tmp, char *key)
{
	t_env	*ptr;

	while (tmp && *tmp)
	{
		ptr = (*tmp);
		(*tmp) = (*tmp)->next;
		if ((*tmp) && !ft_strcmp((*tmp)->key, key) && (*tmp)->flag == 0)
		{
			ptr->next = (*tmp)->next;
			free((*tmp)->key);
			free((*tmp)->value);
			free((*tmp));
			break ;
		}
	}
}

void	remove_node(t_env **env, char *key)
{
	t_env	*tmp;

	tmp = *env;
	if (!ft_strcmp(tmp->key, key) && tmp->flag == 0)
	{
		*env = tmp->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	else
		remove_needle_node(&tmp, key);
}

char	*fill_key(char *str)
{
	char	*key;
	int		len;

	len = lenght_until(str, '=');
	key = (char *)malloc(sizeof(char) * (len + 1));
	key[len] = '\0';
	ft_memmove(key, str, len);
	return (key);
}

char	*fill_value(char *str)
{
	char	*value;
	int		len;
	int		lenstr;

	value = NULL;
	lenstr = ft_strlen(str);
	len = lenstr - lenght_until(str, '=') - 1;
	value = (char *)malloc(sizeof(char) * (len + 1));
	value[len] = '\0';
	while (--len >= 0)
		value[len] = str[--lenstr];
	return (value);
}
