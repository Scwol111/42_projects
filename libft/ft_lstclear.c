/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 19:24:50 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:53:04 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *bg;
	t_list *nx;

	bg = *lst;
	while (bg != NULL)
	{
		nx = bg->next;
		del(bg->content);
		free(bg);
		bg = nx;
	}
	*lst = NULL;
}
