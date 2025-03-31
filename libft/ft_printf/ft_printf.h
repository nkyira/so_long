/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprinft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodavis <jodavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:10:29 by jodavis           #+#    #+#             */
/*   Updated: 2024/11/02 16:12:49 by jodavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

int		ft_printf(const char *format, ...);
int		ft_putstr(const char *s);
int		ft_putchar(char c);
int		ft_putptr(void *ptr);
void	conv_alg(size_t nbr, size_t base, char *sb, int *count);
int		ft_putdec(int n);
int		ft_putui(unsigned int n);
int		ft_puthex(unsigned int n, char c);

#endif
