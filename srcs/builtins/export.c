/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:05:59 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/29 16:06:00 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../ms_head.h"


void	sorted_env(t_env *lst, t_arg *arg)
{
	t_env	*sort;
	char	*tmp;
	char	**keys;
	int		i;
	int		j;

	i = 0;
	sort = lst;
	keys = NULL;
	tmp = NULL;
	while (sort)
	{
		i++;
		sort = sort->next;
	}
	keys = (char**)malloc(sizeof(char*) * (i + 1));
	sort = lst;
	i = 0;
	while (sort)
	{
		if (sort->key != NULL)
			keys[i] = ft_strdup(sort->key);
		else
			keys[i] = NULL;
		i++;
		sort = sort->next;
	}
	keys[i] = NULL;
	i = 0;
	while (keys[i] != NULL)
	{
		j = 0;
		while (keys[j] != NULL)
		{
			if (ft_strcmp2(keys[j], keys[i]) > 0)
			{
				tmp = keys[i];
				keys[i] = keys[j];
				keys[j] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (keys[i])
	{
		sort = lst;
		while (sort)
		{
			if (!ft_strcmp(keys[i], sort->key))
			{
				if (sort->value == NULL)
					printf("declare -x %s\n", keys[i]);
				else
					printf("declare -x %s=\"%s\"\n", keys[i], sort->value);
				break ;
			}
			sort = sort->next;
		}
		i++;
	}
	i = 0;
	while (keys[i])
	{
		free(keys[i]);
		i++;
	}
	free(keys);
}

int	check_keys(t_env *lst, char *str)
{
	int i;

	i = 0;
	if (ft_isalpha(str[0]) || str[0] == '_')
		return (0);
	ft_putstr_fd("error", 2);
	return (1);
}


void	export_things(t_env *env, char	*find, t_arg *arg)
{
	int		i;
	int		j;
	t_env	*lst;
	t_env	*lst1;
	char	*tmp;
	char	*key;
	char	*value;

	i = 0;
	j = 0;
	key = NULL;
	lst1 = NULL;
	value = NULL;
	lst = env;
	if (check_keys(lst, find))
		return ;
	else
	{
		while (find[i])
		{
			if (find[i] == '=')
			{
				if (find[i - 1] == '+' && find[i - 2] != '+')
					j = 1;
				else if (find[i - 1] == '-')
				{
					ft_putstr_fd("Error\n", 2);
					return ;
				}
				break ;
			}
			i++;
		}
		if (i == ft_strlen(find))
		{
			lst1 = NULL;
			lst1 = ft_lstnew1(find, NULL);
			ft_lstadd_back1(&env, lst1);
			return ;
		}
		while (lst)
		{
			if (!ft_strncmp(lst->key, find, ft_strlen(lst->key)))
			{
				if (j == 1)
				{
					tmp = lst->value;
					lst->value = ft_strjoin(lst->value, ft_strchr(find, '=') + 1);
					if (tmp != NULL)
						free(tmp);
				}
				else
					lst->value = ft_strchr(find, '=') + 1;
				if (!lst->value)
					lst->value = NULL;
				return ;
			}
			lst = lst->next;
		}
		lst = env;
		value = ft_strdup(ft_strchr(find, '=') + 1);
		key = ft_strdup(get_keys(find, '='));
		if (j == 1)
			key = get_keys(key, '+');
		i = 0;
		while (key[i])
		{
			if (key[i] == '+' || key[i] == '-')
			{
				ft_putstr_fd("error\n", 2);
				free(key);
				free(value);
				return ;
			}
			i++;
		}
		lst1 = NULL;
		lst1 = ft_lstnew1(key, value);
		ft_lstadd_back1(&env, lst1);
	}
}

void	export_env(t_env **env, t_arg *arg, char **find)
{
	t_env	*lst;
	char	*key;
	char	*value;
	int		i;
	int		j;

	i = 1;
	j = 0;
	lst = *env;
	if (!find[1])
	{
		sorted_env(lst, arg);
		return ;
	}
	else
	{
		while (find[i])
		{
			export_things(lst, find[i], arg);
			i++;
		}
	}
}
