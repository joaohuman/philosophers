/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:30:42 by jvictor-          #+#    #+#             */
/*   Updated: 2023/04/17 02:43:26 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	long long unsigned	num;

	num = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str)
		return (-1);
	return (num);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	while (n--)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

int	ft_usleep(unsigned long ms)
{
	unsigned long	start;

	start = get_time();
	while (ms > get_time() - start)
		usleep(100);
	return (0);
}
