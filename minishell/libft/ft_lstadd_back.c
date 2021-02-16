/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 19:08:03 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:52:54 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *i;

	i = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (i->next != NULL)
			i = i->next;
		i->next = new;
	}
	new->next = NULL;
}
