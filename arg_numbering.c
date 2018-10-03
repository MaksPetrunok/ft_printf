/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_numbering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:40:37 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/03 17:53:02 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_arg_num(char **fmt)
{
	char	*tmp;
	char	*ptr;
	char	flag;
	int		number;

	if ((ptr = ft_strchr(*fmt, '$')) == 0)
		return (0);
	flag = 0;
	tmp = *fmt;
	while (++tmp < ptr)
		if (*tmp > '0' && *tmp <= '9')
			flag = 1;
		else
		{
			flag = 0;
			break;
		}
	number = (flag) ? ft_atoi(*fmt + 1) : 0;
	if (ptr)
		*fmt = ptr + 1;
	return (number);
}

static void	*lst_addid(int id, va_list *ap, t_avlist *av)
{
	return (0);
}

static void	*lst_addlast(va_list *ap, t_avlist *av)
{
	t_avlist	*tmp;

	while (av->next != 0)
		av = av->next;
	if ((tmp = (t_avlist *)malloc(sizeof(t_avlist))) == 0)
		return (0);
	tmp->id = av->id + 1;
	tmp->data = va_arg(*ap, void *);
	tmp->next = 0;
	av->next = tmp;
	return (tmp->data);
}

void	*get_arg_data(int id, va_list *ap, t_avlist *av)
{
	if (av == 0)
	{
		if ((av = (t_avlist *)malloc(sizeof(t_avlist))) == 0)
			return (0);
		av->id = 1;
		av->data = va_arg(*ap, char *);
		av->next = 0;
	printf("================ HERE ====================\n");
	printf("DATA = %p\n", av->data);
	printf("DATA VALUE = %s\n", (av->data));
	printf("DATA VALUE = %d\n", *(int *)(av->data));
		if (id == 0 || id == 1)
			return (av->data);
	}
	if (id == 0)
		return (lst_addlast(ap, av));
	else
		return (lst_addid(id, ap, av));
}
