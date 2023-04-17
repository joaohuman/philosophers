/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:58:02 by jvictor-          #+#    #+#             */
/*   Updated: 2023/04/17 02:43:02 by jvictor-         ###   ########.fr       */
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
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

typedef struct s_philo	t_philo;
typedef struct s_param	t_param;

struct s_philo
{
	int				phi_id;
	pthread_t		phi_thread;
	unsigned long	last_eat;
	pthread_mutex_t	last_eat_mtx;
	int				death;
	pthread_mutex_t	fork;
	int				i;
	int				num_eat;
	t_param			*param;
};

struct s_param
{
	int				num_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	init_time;
	long long		how_much_eat;
	int				someone_is_dead;
	pthread_mutex_t	print_mtx;
	t_philo			*philo;
};

long long		ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

void			print_how_use(void);
int				check_args(int argc, char **argv);
int				check_is_int(char **str);
int				init_param(t_param *p, int argc, char **argv);
int				init_philo(t_param *p);
unsigned long	get_time(void);

void			*test_philo(void *philo);
int				give_life_to_philo(t_param *p);
void			print_status(t_philo *p, char *status);
int				ft_usleep(unsigned long ms);

#endif
