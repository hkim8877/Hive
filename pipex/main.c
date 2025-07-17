#include "pipex.h"


// static void child_1(t_args args)
// {
//     int infile;

//     infile = open(av[1], O_RDONLY);
//     if (infile == -1)
//         ft_perror("infile error");
    
// }

// static void child_2(t_args args)



/*
static void init_args(int argc, char **argv, char** envp)
*/

int main(int argc, char **argv, char **envp)
{
   int pipes[2];
   t_list pipex;

   if (argc != 5)
      ft_error("arguments error\n");
   if (pipe(pipes) == -1)
      ft_perror("pipe");
   //pipex.argc = argc;
   //pipex.argv = argv;
   pipex.cmd1 = cmd_array(3, argv);
   pipex.cmd2 = cmd_array(4, argv);
   pipex.path = find_path(envp);
   char *cmd1_path =  get_cmd_path(pipex.path, pipex.cmd1);
   char *cmd2_path =  get_cmd_path(pipex.path, pipex.cmd2);
   printf("%s\n", cmd1_path);
   printf("%s\n", cmd2_path);
   free(pipex.cmd1);
   free(pipex.cmd2);
   free(pipex.path);
    return (0);
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