#include "philosophers.h"

void print_status(t_philo *philo, char *status)
{
    long time;

    pthread_mutex_lock(&philo->data->mtx);
    if (!philo->data->end_flag)
    {
        pthread_mutex_lock(&philo->data->print);
        time = get_time() - philo->data->start_time;
        printf("%ld %d %s\n", time, philo->id, status);
        pthread_mutex_unlock(&philo->data->print);
    }
    pthread_mutex_unlock(&philo->data->mtx);
}