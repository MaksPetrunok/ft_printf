/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:27:00 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/03 17:11:44 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define FLAGS_NUMBER 6

#define ABS(X) (X < 0) ? -X : X
#define MAX(A, B) (A > B) ? A : B
#define	FLAGS "#0- +'"

typedef struct	s_avlist
{
	int			id;
	void		*data;
	void		*next;
}				t_avlist;

typedef struct	s_fmarg
{
	void		*data;
	char		flags; /* '+ -0# --> 00111111 */
	int			width;
	int			precision;
	char		lengthmod;
	char		type;
}				t_fmarg;

int				get_arg_num(char **fmt);
void			*get_arg_data(int id, va_list *ap, t_avlist *av);
