/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:57:17 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/25 13:57:21 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

typedef struct s1_list
{
	va_list		*args;
	const char	*str;
	char		*substr;
	char		prefix;
	int			printed;
	int			dot_flag;
	int			min_flag;
	int			zero_flag;
	int			hash_flag;
	int			percent;
	size_t		width;
	size_t		precision;

}	t_list1;

int		ft_printf(const char *format, ...);

void	ft_subprint(t_list1 *datalist);
int		ft_conversion(t_list1 *datalist);
char	*ft_itoa_s(int n, t_list1 *datalist);
void	ft_init(t_list1 *dlst);
int		ft_flags(t_list1 *dlst);
char	*ft_conv_x(t_list1 *dlst);
char	*ft_conv_p(t_list1 *dlst);
char	*ft_conv_c(t_list1 *dlst);
char	*ft_conv_s(t_list1 *dlst);
int		ft_hexdigits(unsigned long int dec);
char	*ft_itoa_pf(long int n);

#endif
