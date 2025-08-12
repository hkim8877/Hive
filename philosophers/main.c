#include "philosophers.h"

int main(int argc, char **argv)
{
    int i;
    t_data data;
    pthread_t monitor;
    
    if (!check_args(argc, argv))
        ft_error("Error: invalid args", 1);
    init_data(&data, argc, argv);
    if (data.num_philos == 1)
		single_philo(&data);
    i = 0;
    while (i < data.num_philos)
    {
        pthread_create(&data.philos[i].thread, NULL, routine, &data.philos[i]);
        i++;
    }
    pthread_create(&monitor, NULL, monitoring, &data);
    pthread_join(monitor, NULL);
    i = 0;
    while (i < data.num_philos)
    {
        pthread_join(data.philos[i].thread, NULL);
        i++;
    }
    free_all(&data);
    return (0);
}