/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:55:24 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/08 18:55:27 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*tmp;
	void	*content;

	out = 0;
	if (!f)
		return (0);
	while (lst)
	{
		content = (*f)(lst->content);
		tmp = ft_lstnew(content);
		if (!content || !tmp)
		{
			ft_lstclear(&out, del);
			ft_lstclear(&tmp, del);
			del(content);
			return (0);
		}
		ft_lstadd_back(&out, tmp);
		lst = lst->next;
	}
	return (out);
}
