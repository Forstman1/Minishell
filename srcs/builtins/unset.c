/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:05:20 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/29 16:05:22 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../ms_head.h"

void	unset_env(t_env **env, char *find)
{
	t_env *lst;
	t_env *tmp;

	lst = *env;
	while (lst)
	{
		if (!ft_strncmp(lst->key, find, ft_strlen(lst->key)))
		{
			if (!tmp)
			{
				tmp = lst->next;
				free(lst);
				env = &tmp;
			}
			tmp->next = lst->next;
			free(lst);
		}
		tmp = lst;
		lst = lst->next;
	}
}
