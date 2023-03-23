/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:14:55 by jvictor-          #+#    #+#             */
/*   Updated: 2023/03/23 01:03:16 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_how_use(void)
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
	if (ft_atoi(argv[1]) <= 0)
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

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	//init_param(&param, argc, argv);
	return (SUCCESS);
}
