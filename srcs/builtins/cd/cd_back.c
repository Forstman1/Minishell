/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_back.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:41:42 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/30 16:41:43 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../ms_head.h"

void	cd_back(t_env *env, char *arg)
{
	t_env	*lst;
	char	*current_pwd;
	char	*OLDPWD;
	
	lst = env;
	current_pwd = ft_strdup(pwd(env, 0));
	current_pwd = ft_strrchr1(current_pwd, '/');
	if (chdir(current_pwd))
	{
		free(current_pwd);
		printf("no sush file or directory %s\n", current_pwd);
		return ;
	}
	while (lst)
	{
		if (!ft_strcmp(lst->key, "PWD"))
		{
			if (lst->value)
				OLDPWD = lst->value;
			lst->value = current_pwd;
			break ;
		}
		lst = lst->next;
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


