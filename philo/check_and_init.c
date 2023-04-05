/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:01:02 by jvictor-          #+#    #+#             */
/*   Updated: 2023/04/05 02:05:49 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		print_how_use();
		return (ERROR);
	}
	if (check_is_int(argv))
		return (printf("Invalid number, needs to be int\n"));
	else if (ft_atoi(argv[1]) <= 0)
		return (printf("Invalid number of Philosophers\n"));
	else if (ft_atoi(argv[2]) <= 0)
		return (printf("Incorrect time to die\n"));
	else if (ft_atoi(argv[3]) <= 0)
		return (printf("Incorrect time to eat\n"));
	else if (ft_atoi(argv[4]) <= 0)
		return (printf("Incorrect time to sleep\n"));
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0)
			return (printf("Incorrect number of times to eat\n"));
	}
	return (SUCCESS);
}

int	check_is_int(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (ERROR);
			j++;
		}
		if (ft_atoi(str[i]) < -2147483647 -1 || ft_atoi(str[i]) > 2147483647)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

void	init_param(t_param *p, int argc, char **argv)
{
	p->num_philo = ft_atoi(argv[1]);
	p->time_to_die = ft_atoi(argv[2]);
	p->time_to_eat = ft_atoi(argv[3]);
	p->time_to_sleep = ft_atoi(argv[4]);
	p->init_time = get_time();
	p->how_much_eat = 0;
	if (argc == 6)
		p->how_much_eat = ft_atoi(argv[5]);
	p->philo = malloc(sizeof(t_philo) * p->num_philo);
}

void	init_philo(t_param *p)
{
	int	i;

	i = 0;
	while (i < p->num_philo)
	{
		p->philo[i].phi_id = i + 1;
		p->philo[i].phi_thread = 0;
		p->philo[i].last_eat = 0;
		p->philo[i].death = 0;
		p->philo[i].num_eat = 0;
		p->philo[i].param = p;
		i++;
	}
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
