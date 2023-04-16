/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_life_to_philo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:46:32 by jvictor-          #+#    #+#             */
/*   Updated: 2023/04/17 01:23:36 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    ft_usleep(unsigned long ms)
{
    unsigned long    start;

    start = get_time();
    while (ms > get_time() - start)
        usleep(100);
    return (0);
}

void	*test_philo(void *philo)
{
	pthread_mutex_t *phi_nxt;
	t_philo 		*phi;
	int				i;

	phi = (t_philo *)philo;
	i = phi->i;
	if (i != phi->param->num_philo - 1)
		phi_nxt = &phi->param->philo[i+1].fork;
	else
		phi_nxt = &phi->param->philo[0].fork;
	pthread_mutex_lock(&phi->fork);
	pthread_mutex_lock(phi_nxt);
	print_status(phi, FORK);
	print_status(phi, EAT);
	pthread_mutex_lock(&phi->last_eat_mtx);
	phi->last_eat = get_time() - phi->param->init_time;
	pthread_mutex_unlock(&phi->last_eat_mtx);
	ft_usleep(phi->param->time_to_eat);
	pthread_mutex_unlock(phi_nxt);
	pthread_mutex_unlock(&phi->fork);
	print_status(phi, SLEEP);
	ft_usleep(phi->param->time_to_sleep);
	print_status(phi, THINK);
	return(NULL);
}

void	*live_philo(void *philo)
{
	t_philo	*phi;

	phi = (t_philo *)philo;
	if (phi->phi_id % 2 == 0)
		usleep(1600);
	while ((phi->num_eat < phi->param->how_much_eat || phi->param->how_much_eat == -1) && !phi->param->someone_is_dead)
		test_philo(philo);
	return (NULL);
}

void	print_status(t_philo *p, char *status)
{
	unsigned long		time;

	pthread_mutex_lock(&p->param->print_mtx);
	time = get_time() - p->param->init_time;
	if ((!ft_strncmp(status, EAT, 9) && !p->param->someone_is_dead) || !ft_strncmp(status, DIED, 9))
	{
		if ((p->param->time_to_die <= get_time() - p->last_eat - p->param->init_time && p->last_eat != 0) || !ft_strncmp(status, DIED, 9))
			{
				p->death = 1;
				p->param->someone_is_dead = 1;
				printf("\033[1;{%06lu\033[0;} - %i %s\n", time, p->phi_id, DIED);
			}
		else
			p->num_eat++;
	}
	if (!p->param->someone_is_dead)
		printf("\033[1;{%06lu\033[0;} - %i %s\n", time, p->phi_id, status);
	pthread_mutex_unlock(&p->param->print_mtx);
}

int	give_life_to_philo(t_param *p)
{
	int i;

	i = 0;
	if (p->num_philo == 1)
	{
		print_status(&p->philo[i], DIED);
		return (SUCCESS);
	}
	while (i < p->num_philo)
	{
		p->philo[i].i = i;
		if (pthread_create(&p->philo[i].phi_thread, NULL, live_philo, &p->philo[i]))
			return (printf("Error creating thread\n"), ERROR);
		i++;
	}
	i = 0;
	while (i < p->num_philo)
	{
		if (pthread_join(p->philo[i].phi_thread, NULL))
			return (printf("Error joining thread\n"), ERROR);
		i++;
	}
	free(p->philo);
	return (SUCCESS);
}
