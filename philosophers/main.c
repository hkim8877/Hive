#include "philosophers.h"

static long ft_atol(const char *str)
{
    long result;
    int i = 0;

    result = 0;

    while (str[i] == 32 ||(str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            return (0);
        i++; 
    }
    if (!(str[i] >= '0' && str[i] <= '9'))
    {
        ft_error("Error: invalid input", 1);
        return (0);
    }
    while (str[i] >= '0' && str[i] <= '9')
        result = (result * 10) + (str[i++] - '0');
    return (result);
}

int check_args(int argc, char **argv)
{
    int i;
    long value;

    if (argc < 5 || argc > 6)
        return (0);
    i = 1;
    while (argv[i])
    {
        value = ft_atol(argv[i]);
        if (value <= 0)
            return (0);
        i++;
    }
    if (ft_atol(argv[1]) > 200)
    {
        ft_error("Error: number of philosophers cannot exceed 200", 0);
        return (0);
    }
    return (1);
}

void ft_error(char *msg, int code)
{
    if (code == 1)
    {
        printf("%s\n", msg);
        exit(1);
    }
    printf("%s\n", msg);
}

void init_philos(t_data *data)
{
    int i;

    i = 0;
    while (i < data->num_philos)
    {
        data->philos[i].id = i + 1;
        data->philos[i].eat_count = 0;
        data->philos[i].last_eat_time = data->start_time;
        data->philos[i].data = data;
        if (data->philos[i].id % 2 == 0)
        {
            data->philos[i].left_fork = (i + 1) % data->num_philos;
            data->philos[i].right_fork = i;
        }
        else
        {
            data->philos[i].left_fork = i;
            data->philos[i].right_fork = (i + 1) % data->num_philos;
        }
        i++;
    }
}

static void ft_free(t_data *data)
{
    if (data->philos)
        free(data->philos);
    if (data->forks)
        free(data->forks);
}

void init_data(t_data *data, int argc, char **argv)
{
    int i;

    data->num_philos = ft_atol(argv[1]);
    data->time_to_die = ft_atol(argv[2]);
    data->time_to_eat = ft_atol(argv[3]);
    data->time_to_sleep = ft_atol(argv[4]);
    data->end_flag = false;
    if (argc == 6)
        data->must_eat = ft_atol(argv[5]);
    else
        data->must_eat = -1;
    data->philos = malloc(sizeof(t_philo) * data->num_philos);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
    if (!data->philos || !data->forks)
    {
        ft_free(data);
        ft_error("Error: memory allocation failed\n", 1);
    }
    pthread_mutex_init(&data->mtx, NULL);
    pthread_mutex_init(&data->print, NULL);
    pthread_mutex_init(&data->eat_lock, NULL);
    i = 0;
    while (i < data->num_philos)
        pthread_mutex_init(&data->forks[i++], NULL);
    data->start_time = get_time();
    init_philos(data);
}

void free_all(t_data *data)
{
    int i;

    i= 0;
    while (i < data->num_philos)
    {
        pthread_mutex_destroy(&data->forks[i]);
        i++;
    }
    pthread_mutex_destroy(&data->mtx);
    pthread_mutex_destroy(&data->print);
    free(data->philos);
    free(data->forks); 
}

long get_time(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void ft_usleep(t_data *data, long time_to_wait)
{
    long start;

    start = get_time();
    while ((get_time() - start) < time_to_wait)
    {
        pthread_mutex_lock(&data->mtx);
        if (data->end_flag)
        {
            pthread_mutex_unlock(&data->mtx);
            break ;
        }
        pthread_mutex_unlock(&data->mtx);
        usleep(100);
    }
}

static int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

void print_status(t_philo *philo, char *status)
{
    long time;

    pthread_mutex_lock(&philo->data->print);
    pthread_mutex_lock(&philo->data->mtx);
    if (!philo->data->end_flag || ft_strcmp(status, "died") == 0)
    {
        time = get_time() - philo->data->start_time;
        printf("%ld %d %s\n", time, philo->id, status);
        if (ft_strcmp(status, "died") == 0)
            philo->data->end_flag = true;
    }
    pthread_mutex_unlock(&philo->data->mtx);
    pthread_mutex_unlock(&philo->data->print);
}

void *routine(void *philo)
{
   
}

void *monitoring(void *data)
{
   
}

void single_philo(void *data);
{

}

int main(int argc, char **argv)
{
    int i;
    t_data data;
    pthread_t monitor;
    
    if (!check_args(argc, argv))
        ft_error("Error: invalid args", 1);
    init_data(&data, argc, argv);
    if (data.num_philos == 1)
        single_philo();
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