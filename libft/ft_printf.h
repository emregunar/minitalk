/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunar <egunar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:06:29 by egunar            #+#    #+#             */
/*   Updated: 2022/01/13 15:57:33 by egunar           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *s, ...);
int		bul(char *s, va_list *args);
int		print_char(char c);
int		string_yazdir(char *str);
int		sayi_yazdir(int i);
int		unsigned_yazdir(unsigned int nb);
int		hex_yazdir(unsigned long int nb, int s);
#endif
