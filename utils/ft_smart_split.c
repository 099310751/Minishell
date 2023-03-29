/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:04:32 by suhovhan          #+#    #+#             */
/*   Updated: 2023/03/30 00:22:55 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	getwordcount(char *s, char c)
{
	int	count;
	int	i;
	int	len;

	i = -1;
	count = 1;
	len = ft_strlen(s);
	while (s[++i] && s[i] == c)
		;
	while (s[--len] && s[len] == c && i < len)
		;
	if (i == (int)ft_strlen(s))
		return (0);
	while (s[i] && i < len)
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	return (count);
}

char	*fillword(char *s, int start_index, int len)
{
	char	*word;
	int		i;

	i = -1;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (++i < len && s[i] != '\0')
		word[i] = s[start_index + i];
	word[i] = '\0';
	return (word);
}

char	**ft_smart_split(char *s)
{
	int		start;
	int		end;
	int		i;
	int		count;
	char	**res;

	start = 0;
	i = -1;
	count = getwordcount(s, '|');
	res = (char **)malloc(sizeof(char *) * count + 1);
	while (++i < count)
	{
		while (s[start] && s[start] == '|')
			start++;
		end = start;
		while (s[end] != '\0' && s[end] != '|')
			end++;
		res[i] = fillword(s, start, end - start);
		start = end;
	}
	res[i] = 0;
	return (res);
}

int	list_size(t_env *env)
{
	int	count;

	count = 0;
	if (!env)
		return (0);
	while (env)
	{
		if (env->flag == 0)
			count++;
		env = env->next;
	}
	return (count);
}

char	**list_to_char(t_addres *address)
{
	t_env	*temp;
	char	**envp;
	int		i;
	char	*ptr;

	envp = malloc(sizeof(char **) * (list_size(address->env) + 1));
	i = 0;
	temp = address->env;
	while (temp)
	{
		if (temp->flag == 0)
		{
			envp[i] = ft_strjoin(temp->key, "=");
			ptr = envp[i];
			envp[i] = ft_strjoin(envp[i], temp->value);
			free(ptr);
			i++;
		}
		temp = temp->next;
	}
	envp[i] = NULL;
	return (envp);
}
