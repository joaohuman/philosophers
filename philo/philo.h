/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:58:02 by jvictor-          #+#    #+#             */
/*   Updated: 2023/04/01 03:02:58 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define ERROR 1
# define SUCCESS 0

typedef struct s_philo
{
	int			phi_id;
	pthread_t	phi_thread;
}				t_philo;

typedef struct s_param
{
	long long	num_philo;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	how_much_eat;
	t_philo		*philo;
}				t_param;

long long	ft_atoi(const char *str);
int			ft_isdigit(int c);

#endif
