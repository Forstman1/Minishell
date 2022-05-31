/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:42:35 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/12 09:42:37 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *key, char *value)
{
	t_list	*n1;

	n1 = NULL;
	n1 = (t_list *)malloc(sizeof(t_list));
	if (n1 == NULL)
		return (NULL);
	n1->key = key;
	n1->value = value;
	n1->next = NULL;
	return (n1);
}
