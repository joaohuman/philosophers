/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:58:02 by jvictor-          #+#    #+#             */
/*   Updated: 2023/04/14 02:33:15 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define ERROR 1
# define SUCCESS 0

typedef struct s_philo	t_philo;
typedef struct s_param	t_param;

struct s_philo
{
	int				phi_id;
	pthread_t		phi_thread;
	long long		last_eat;
	int				death;
	int				num_eat;
	pthread_mutex_t	fork;
	int				i;
	t_param			*param;
};

struct s_param
{
	long long	num_philo;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	init_time;
	long long	how_much_eat;
	t_philo		*philo;
};

long long	ft_atoi(const char *str);
int			ft_isdigit(int c);
void		print_how_use(void);
int			check_args(int argc, char **argv);
int			check_is_int(char **str);
int			init_param(t_param *p, int argc, char **argv);
int			init_philo(t_param *p);
long long	get_time(void);

#endif
