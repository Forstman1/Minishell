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

void	cd_samdir(t_env *env, char *arg)
{
	t_env	*lst;
	char	*OLDPWD;
	char	*current;
	char	*value;
	char	*key;
	int		i;

	lst = env;
	i = 0;
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
			if (lst->value)
				current = lst->value;
			lst->value = OLDPWD;
			i = 2;
			break ;
		}
		lst = lst->next;
	}
	if (i != 2)
	{
		lst = NULL;
		value = ft_strdup(OLDPWD);
		key = ft_strdup("OLDPWD");
		lst = ft_lstnew1(key, value);
		ft_lstadd_back1(&env, lst);
	}
}