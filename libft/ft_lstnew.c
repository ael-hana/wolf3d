/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:56:43 by ael-hana          #+#    #+#             */
/*   Updated: 2015/11/30 15:42:45 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;
	void	*data;

	if (!(ptr = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	(*ptr).next = NULL;
	if (!content)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
		return (ptr);
	}
	if (!(data = malloc(sizeof(content) * content_size)))
		return (NULL);
	ptr->content = ft_memcpy(data, content, content_size);
	ptr->content_size = content_size;
	return (ptr);
}
