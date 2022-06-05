/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:49:19 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/31 15:49:20 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../ms_head.h"

void	cd_root(t_env *env, char *arg)
{
	t_env	*lst;
	char	*OLDPWD;

	lst = env;
	if (chdir("/"))
	{
		printf("commad not found\n");
		exit(0);
	}
	while (lst)
	{
		if (!ft_strcmp(lst->key, "PWD"))
		{
			if (lst->value)
				OLDPWD = lst->value;
			lst->value = "/";
			break ;
		}
		lst = lst->next;
	}
	if (!pwd(env, 0))
	{
		printf("commad not found\n");
		exit(0);
	}
	lst = env;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "OLDPWD"))
		{
			lst->value = OLDPWD;
			return ;
		}
		lst = lst->next;
	}
}
