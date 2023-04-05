/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:14:55 by jvictor-          #+#    #+#             */
/*   Updated: 2023/04/05 04:26:00 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	*test_philo(void *philo)
{
	t_philo *phi;
	int		i;

	phi = (t_philo *)philo;
	i = phi->i;

	//preciso pegar "&phi->param->philo[i+1].fork" e colocar em uma variavel
	// lembrando que esse i+1 pode dar problema, entao antes verificar
	// para que o ultimo nao tente acessar memoria que nao deve
	// ele precisa entao retornar para o primeiro garfo
	
	pthread_mutex_lock(&phi->fork);
	printf("filosofo %i has taken a fork\n", phi->phi_id);
	pthread_mutex_lock(&phi->param->philo[i+1].fork);
	printf("filosofo %i has taken a 2 fork\n", phi->phi_id);
	pthread_mutex_unlock(&phi->param->philo[i+1].fork);
	printf("filosofo %i has released a 2 fork\n", phi->phi_id);
	pthread_mutex_unlock(&phi->fork);
	printf("filosofo %i has released a fork\n", phi->phi_id);
	return(NULL);
}

int	main(int argc, char **argv)
{
	t_param	p;
	int		i;
	
	i = 0;
	if (check_args(argc, argv))
		return (ERROR);
	init_param(&p, argc, argv);
	init_philo(&p);
	while (i < p.num_philo)
	{
		p.philo[i].i = i;
		if(pthread_create(&p.philo[i].phi_thread, NULL, test_philo, &p.philo[i]))
			return(printf("Error creating thread"), ERROR);
		i++;
	}
	i = 0;
	while (i < p.num_philo)
	{
		pthread_join(p.philo[i].phi_thread, NULL);
		i++;
	}
	free(p.philo);
	return (SUCCESS);
}
