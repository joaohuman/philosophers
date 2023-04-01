/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:14:55 by jvictor-          #+#    #+#             */
/*   Updated: 2023/04/01 03:38:14 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	print_how_use(void)
{
	printf("\nuse: ");
	printf("philo ");
	printf("number_of_philosophers ");
	printf("time_to_die ");
	printf("time_to_eat ");
	printf("time_to_sleep ");
	printf("[times_each_philosopher_must_eat] \n\n");
	printf("  number_of_philosophers \t\t");
	printf("number of philosophers.\n");
	printf("  time_to_die \t\t\t\t");
	printf("time in milliseconds that a philosopher die of starve.\n");
	printf("  time_to_eat \t\t\t\t");
	printf("time in milliseconds it takes a philosopher to eat.\n");
	printf("  time_to_sleep \t\t\t");
	printf("time in milliseconds it takes a philosopher to sleep.\n");
	printf("  [times_each_philosopher_must_eat] \t");
	printf("number of times each philosopher must eat\n\n");
}

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

void	init_param(t_param *p, int argc, char **argv)
{
	p->num_philo = ft_atoi(argv[1]);
	p->time_to_die = ft_atoi(argv[2]);
	p->time_to_eat = ft_atoi(argv[3]);
	p->time_to_sleep = ft_atoi(argv[4]);
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
		p->philo[i].phi_id = i;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_param	p;
	int		i = 0;

	if (check_args(argc, argv))
		return (ERROR);
	init_param(&p, argc, argv);
	init_philo(&p);
	while (i < p.num_philo)
	{
		printf("id do philosofo: %i\n", p.philo[i].phi_id);
		i++;
	}
	free(p.philo);
	return (SUCCESS);
}
