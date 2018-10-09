/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:27:00 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/08 19:20:46 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# define ABS(X) (X < 0) ? -X : X
# define MAX(A, B) (A > B) ? A : B

# define FLAGS "#0- +'"
# define TYPES "sSpdDioOuUxXcCb%"

typedef struct	s_avlist
{
	int			id;
	void		*data;
	void		*next;
}				t_avlist;

typedef enum	e_len_mod
{
	emp = 0,
	hh = 1,
	ll = 2,
	h = 3,
	l = 4,
	j = 5,
	z = 6,
	L = 7,
}				t_lm;

typedef struct	s_fmarg
{
	void		*data;
	char		flags; /* '+ -0# --> 00111111 */
	int			width;
	int			precision;
	t_lm		lengthmod;
	char		type;
}				t_fmarg;

int				ft_printf(const char *fmt, ...);
int				print_arg(t_fmarg *arg, va_list *ap);
void			parse_flags(char **str, t_fmarg *arg);
void			arg_to_str_di(t_fmarg *arg, va_list *ap, char *buff);
void			arg_to_str_ouxX(t_fmarg *arg, va_list *ap, char *buff);
void			arg_to_str_bf(t_fmarg *arg, va_list *ap, char *buff);


//int				get_arg_num(char **fmt);
//void			*get_arg_data(int id, va_list *ap, t_avlist *av);
#endif
