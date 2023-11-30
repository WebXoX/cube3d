/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:27:01 by afarheen          #+#    #+#             */
/*   Updated: 2023/01/09 18:30:09 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int	ft_putnbr_base(size_t nbr, char *base, int flag);
int	ft_printf(const char *str, ...);
int	ft_putnbr(long int nbr, char *base);

#endif
