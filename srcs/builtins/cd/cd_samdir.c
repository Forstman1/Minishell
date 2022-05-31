/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_samdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:20:30 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/31 16:20:30 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../ms_head.h"

void	cd_samdir(t_env *env, t_arg *arg)
{
	t_env	*lst;
	char	*OLDPWD;
	char	*current;

	lst = env;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "PWD"))
		{
			if (lst->value)
				OLDPWD = lst->value;
			break ;
		}
		lst = lst->next;
	}
	if (!pwd(env))
	{
		printf("commad not found\n");
		exit(0);
	}
	lst = env;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "OLDPWD"))
		{
			if (lst->value)
				current = lst->value;
			lst->value = OLDPWD;
			return ;
		}
		lst = lst->next;
	}
	lst = env;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "PWD"))
		{
			lst->value = current;
			break ;
		}
		lst = lst->next;
	}
}