#include "pipex.h"

static void ft_error(char *error)
{
    ft_putstr_fd(error, 2);
    exit(1);
}

static int init_pipex(t_list *pipex, char **argv, char **envp)
{
   pipex->cmd1 = cmd_array(3, argv);
   pipex->cmd2 = cmd_array(4, argv);
   pipex->path = find_path(envp);
   // pipex->env = envp;
   // pipex->pid1 = 0;
   // pipex->pipe_read = pipes[0];
   // pipex->pipe_write = pipes[1];
   if (!pipex->cmd1 || !pipex->cmd2 || !pipex->path)
        return (1);

   return (0);
}

int main(int argc, char **argv, char **envp)
{
   t_list pipex;
   int exit_code;

   if (argc != 5)
      ft_error("arguments error\n");
   // if (pipe(pipes) == -1)
   //      ft_error("pipe error\n");
   if (init_pipex(&pipex, argv, envp))
      cleanup(&pipex, EXIT_FAILURE);
   exit_code = process(&pipex, argv, envp);
   free_pipex(&pipex);
   return (exit_code);
}

/*
int pipe(int fd[2]);

int access(const char *path, int mode);

pid_t wait(int *stat_loc);

pid_t waitpid(pid_t pid, int *stat_loc, int options);

int dup(int fd);

int dup2(int fd, int fd2);

pid_t fork(void);

int execve(const char *filename, char *const argv[], char *const envp[]);

void perror(cosnt char *str);

char *strerror(int errnum);

*/