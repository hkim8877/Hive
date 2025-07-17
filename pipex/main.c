#include "pipex.h"

void process(t_list *pipex, char **argv)
{
   int infile;
   int outfile;
   int fd[2];

   if (pipe(fd) == -1)
     ft_perror("pipe");
   pipex->pid = fork();
   if (pipex->pid == -1)
      ft_perror("fork");
   else if (pipex->pid == 0)
   {
      infile = open(argv[1], O_RDONLY);
      if (infile == -1)
         ft_perror("infile error");
      dup2(infile, STDIN_FILENO);
      close(infile);
      dup2(fd[1], STDOUT_FILENO);
      close(fd[0]);
      close(fd[1]);
      char *cmd1_path = get_cmd_path(pipex->path, pipex->cmd1);
      execve(cmd1_path, pipex->cmd1, NULL);
   }
   else
   {
      dup2(fd[0], STDIN_FILENO);
      close(fd[1]);
      close(fd[0]);
      outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
      if (outfile == -1)
         ft_perror("outfile error");
      dup2(outfile, STDOUT_FILENO);
      close(outfile);
      char *cmd2_path = get_cmd_path(pipex->path, pipex->cmd2);
      execve(cmd2_path, pipex->cmd2, NULL);
   }
   close(fd[0]);
   close(fd[1]);
   waitpid(pipex->pid, NULL, 0);
}

static int init_pipex(t_list *pipex, char **argv, char **envp)
{
   pipex->pid = 0;
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
   if (init_pipex(&pipex, argv, envp))
      ft_error("Initialization error\n");
   process(&pipex, argv);
   free_pipex(&pipex);
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