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

void	export_env(t_env **env, char *str, char *find)
{
	t_env	*lst;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	lst = *env;
	if (!find)
	{
		while (lst)
		{
			printf("declare -x %s=%s\n", lst->key, lst->value);
			lst = lst->next;
		}
		return ;
	}
	else
	{
		while (find[i])
		{
			if (find[i] == '=')
				break ;
			i++;
		}
		if (i == ft_strlen(find))
			return ;
		while (lst)
		{
			if (!ft_strncmp(lst->key, find, ft_strlen(lst->key)))
			{
				lst->value = ft_strchr(find, '=') + 1;
				if (!lst->value)
					lst->value = NULL;
				return ;
			}
			lst = lst->next;
		}
		value = ft_strdup(ft_strchr(find, '=') + 1);
		key = ft_strdup(get_keys(find, '='));
		lst = ft_lstnew1(key, value);
		ft_lstadd_back1(env, lst);
	}
}
