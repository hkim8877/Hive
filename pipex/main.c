#include "pipex.h"

void process(t_list *pipex, char **argv)
{
   int infile;
   int outfile;
   int fd[2];
   int status;
   char *cmd1_path;

   if (pipe(fd) == -1)
     ft_perror("pipe");
   pid_t pid1 = fork();
   if (pid1 == -1)
      ft_perror("fork");
   else if (pid1 == 0)
   {
      close(fd[0]);
      infile = open(argv[1], O_RDONLY);
      if (infile == -1)
         ft_perror("infile error");
      dup2(infile, STDIN_FILENO);
      dup2(fd[1], STDOUT_FILENO);
      close(infile);
      close(fd[1]);
      cmd1_path = get_cmd_path(pipex->path, pipex->cmd1);
      if (!cmd1_path)
         return (ft_putstr_fd("command error\n", 2));
      execve(cmd1_path, pipex->cmd1, NULL);
      free(cmd1_path);
      exit(EXIT_FAILURE);
   }
   pid_t pid2 = fork();
   if (pid2 == -1)
      ft_perror("fork");
   else if (pid2 == 0)
   {
      close(fd[1]);
      outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
      if (outfile == -1)
         ft_perror("outfile error");
      dup2(fd[0], STDIN_FILENO);
      dup2(outfile, STDOUT_FILENO);
      close(fd[0]);
      close(outfile);
      char *cmd2_path = get_cmd_path(pipex->path, pipex->cmd2);
      if (!cmd2_path)
         return (ft_putstr_fd("command error\n", 2));
      execve(cmd2_path, pipex->cmd2, NULL);
      free(cmd2_path);
      exit(EXIT_FAILURE);
   }
   close(fd[0]);
   close(fd[1]);
   waitpid(pid1, &status, 0);
   waitpid(pid2, &status, 0);
}

static int init_pipex(t_list *pipex, char **argv, char **envp)
{
   pipex->cmd1 = cmd_array(3, argv);
   if (!pipex->cmd1)
      return (1);
   pipex->cmd2 = cmd_array(4, argv);
   if (!pipex->cmd2)
      return (1);
   pipex->path = find_path(envp);
   if (!pipex->path)
      return (1);
   return (0);
   //pipex.argc = argc;
   //pipex.argv = argv;
}

int main(int argc, char **argv, char **envp)
{
   t_list pipex;

   if (argc != 5)
      ft_error("arguments error\n");
   printf("Args: %s | %s | %s | %s\n", argv[1], argv[2], argv[3], argv[4]);
   if (init_pipex(&pipex, argv, envp))
      ft_error("Initialization error\n");
   printf("init successful\n");
   process(&pipex, argv);
   printf("process successful\n");
   free_pipex(&pipex);
   printf("end\n");
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