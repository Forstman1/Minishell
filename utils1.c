/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:46:42 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/28 17:46:44 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ms_head.h"

// void	free_all(t_env *env)
// {
// 	t_env	*tmp;
// 	t_env	*lst;
// 	int		i;

// 	lst = *philo;
// 	i = 1;
// 	while (i <= lst->rules->nb_philo)
// 	{
// 		tmp = lst->next;
// 		free(lst);
// 		lst = NULL;
// 		if (tmp)
// 			lst = tmp;
// 		i++;
// 	}
// }

void	ft_lstadd_back1(t_env **lst, t_env *new)
{
	t_env	*root;

	root = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (root->next != NULL)
			root = root->next;
		root->next = new;
	}
}

t_env	*ft_lstnew1(char *key, char *value)
{
	t_env	*n1;

	n1 = NULL;
	n1 = (t_env *)malloc(sizeof(t_env));
	if (n1 == NULL)
		return (NULL);
	n1->key = key;
	n1->value = value;
	n1->next = NULL;
	return (n1);
}

char	*get_keys(char *str, int c)
{
	char	*h;
	char	a;
	int		j;

	h = (char *)str;
	j = 0;
	a = (char) c;
	while (h[j] != a)
		j++;
	if (h[j] + 2 == 0)
		return (str);
	else
	{
		h[j] = 0;
		return (h);
	}
	return (0);
}
