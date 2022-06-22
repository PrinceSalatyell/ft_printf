/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:49:59 by josanton          #+#    #+#             */
/*   Updated: 2022/04/06 00:22:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define DEC "0123456789"
# define HEX_U "0123456789ABCDEF"
# define HEX_L "0123456789abcdef"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);

#endif