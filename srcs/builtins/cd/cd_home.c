/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:49:39 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/30 16:49:40 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../ms_head.h"

void	cd_home(t_env *env, char *arg)
{
	t_env	*lst;
	char	*OLDPWD;
	char	*home;
	
	lst = env;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "HOME"))
		{
			if (chdir(lst->value))
			{
				printf("commad not found\n");
				return ;
			}
			home = lst->value;
			break ;
		}
		lst = lst->next;
	}
	if (!home)
	{
		printf("commad not found\n");
		return ;
	}
	lst = env;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "PWD"))
		{
			if (lst->value)
				OLDPWD = lst->value;
			lst->value = home;
			break ;
		}
		lst = lst->next;
	}
	if (!pwd(env, 0))
	{
		home = NULL;
		lst = ft_lstnew1("PWD", getcwd(home, 9999));
		ft_lstadd_back1(&env, lst);
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