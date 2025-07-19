#include "pipex.h"

static void child_process_1(t_list *pipex, char **argv, char **envp, int *fd)
{
   char *cmd_path;
   int infile;

   close(fd[0]);
   infile = open(argv[1], O_RDONLY);
   if (infile < 0)
      ft_perror("infile open error", pipex, EXIT_FAILURE);
   if (dup2(infile, STDIN_FILENO) < 0 || dup2(fd[1], STDOUT_FILENO) < 0)
      ft_perror("dup2", pipex, EXIT_FAILURE);
   close(infile);
   close(fd[1]);
   cmd_path = get_cmd_path(pipex->path, pipex->cmd1);
   if (!cmd_path)
   {
      ft_putstr_fd("command not found\n", 2);
      cleanup(pipex, 127);
   }
   execve(cmd_path, pipex->cmd1, envp);
   free(cmd_path);
   exit(EXIT_FAILURE);
}

static void child_process_2(t_list *pipex, char **argv, char **envp, int *fd)
{
   char *cmd_path;
   int outfile;

   close(fd[1]);
   outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
   if (outfile < 0)
        ft_perror("outfile open error", pipex, EXIT_FAILURE);
   if (dup2(fd[0], STDIN_FILENO) < 0 || dup2(outfile, STDOUT_FILENO) < 0)
      ft_perror("dup2", pipex, EXIT_FAILURE);
   close(fd[0]);
   close(outfile);
   cmd_path = get_cmd_path(pipex->path, pipex->cmd2);
   if (!cmd_path)
   {
      ft_putstr_fd("command not found\n", 2);
      cleanup(pipex, 127);
   }
   execve(cmd_path, pipex->cmd2, envp);
   free(cmd_path);
   exit(EXIT_FAILURE);
}

int process(t_list *pipex, char **argv, char **envp)
{
   int fd[2];
   int status1;
   int status2;
   pid_t pid1;
   pid_t pid2;

   if (pipe(fd) == -1)
      ft_perror("pipe error", pipex, EXIT_FAILURE);
   pid1 = fork();
   if (pid1 < 0)
      ft_perror("fork error", pipex, EXIT_FAILURE);
   if (pid1 == 0)
      child_process_1(pipex, argv, envp, fd);
   pid2 = fork();
   if (pid2 < 0)
      ft_perror("fork error", pipex, EXIT_FAILURE);
   if (pid2 == 0)
      child_process_2(pipex, argv, envp, fd);
   close(fd[0]);
   close(fd[1]);
    waitpid(pid1, &status1, 0);
    waitpid(pid2, &status2, 0);
   if (WIFEXITED(status2)) 
      return (WEXITSTATUS(status2));
   else
      return (128 + WTERMSIG(status2));
}
// static int child_process(t_list *pipex, char **cmd, int fd_in, int fd_out)
// {
//    char *cmd_path;

//    if (fd_in != pipex->pipe_read)
//       close(pipex->pipe_read);
//    if (fd_out != pipex->pipe_write)
//       close(pipex->pipe_write);
//    cmd_path = get_cmd_path(pipex->path, cmd);
//    if (!cmd_path)
//    {
//       ft_putstr_fd("command not found\n", 2);
//       cleanup(pipex, 127);
//    }
//    if (dup2(fd_in, STDIN_FILENO) < 0 || dup2(fd_out, STDOUT_FILENO) < 0)
//       ft_perror("dup2", pipex, EXIT_FAILURE);
//    close(fd_in);
//    close(fd_out);
//    execve(cmd_path, cmd, pipex->env);
//    free(cmd_path);
//    exit(EXIT_FAILURE);
// }

// static int open_file(t_list *pipex, char *file, int flags)
// {
//    int fd;

//    fd = open(file, flags, 0644);
//    if (fd < 0)
//       ft_perror("file error", pipex, EXIT_FAILURE);
//    return (fd);
// }

// static pid_t exec_child(t_list *pipex, char **cmd, int fd_in, int fd_out)
// {
//    pid_t pid;

//    pid = fork();
//    if (pid == -1)
//       ft_perror("fork", pipex, EXIT_FAILURE);
//    else if (pid == 0)
//       child_process(pipex, cmd, fd_in, fd_out);
//    return (pid);
// }

// int process(t_list *pipex, char **argv)
// {
//    int status[2];
//    int infile;
//    int outfile;
//    pid_t pid[2];
  
//    infile = open_file(pipex, argv[1], O_RDONLY);
//    pid1 = exec_child(pipex, pipex->cmd1, infile, pipex->pipe_write);
//    outfile = open_file(pipex, argv[4], O_WRONLY | O_CREAT | O_TRUNC);
//    pid2 = exec_child(pipex, pipex->cmd2, pipex->pipe_read, outfile);
//    close(pipex->pipe_read);
//    close(pipex->pipe_write);
//    waitpid(pid1, &status[0], 0);
//    waitpid(pid2, &status[1], 0);
//    if (WIFEXITED(status[1])) 
//       return (WEXITSTATUS(status[1]));
//    else
//       return (128 + WTERMSIG(status[1]));   
// }

// int process(t_list *pipex, char **argv, char **envp)
// {
//    int infile;
//    int outfile;
//    int fd[2];
//    int status1;
//    int status2;
//    char *cmd1_path;

//    if (pipe(fd) == -1)
//       ft_perror("pipe", pipex, EXIT_FAILURE);
//    pid_t pid1 = fork();
//    if (pid1 == -1)
//       ft_perror("fork", pipex,EXIT_FAILURE);
//    else if (pid1 == 0)
//    {
//       close(fd[0]);
//       infile = open(argv[1], O_RDONLY);
//       if (infile < 0)
//          ft_perror("open infile", pipex, EXIT_FAILURE);
//       if (dup2(infile, STDIN_FILENO) < 0 || dup2(fd[1], STDOUT_FILENO) < 0)
//          ft_perror("dup2", pipex, EXIT_FAILURE);
//       close(infile);
//       close(fd[1]);
//       cmd1_path = get_cmd_path(pipex->path, pipex->cmd1);
//       if (!cmd1_path)
//       {
//          ft_putstr_fd("command not found\n", 2);
//          cleanup(pipex, 127);
//       }
//       execve(cmd1_path, pipex->cmd1, envp);
//       free(cmd1_path);
//       exit(EXIT_FAILURE);
//    }
//    pid_t pid2 = fork();
//    if (pid2 == -1)
//       ft_perror("fork", pipex, EXIT_FAILURE);
//    else if (pid2 == 0)
//    {
//       close(fd[1]);
//       outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
//       if (outfile < 0)
//          ft_perror("outfile error", pipex, EXIT_FAILURE);
//       if (dup2(fd[0], STDIN_FILENO) < 0 || dup2(outfile, STDOUT_FILENO) < 0)
//          ft_perror("dup2", pipex, EXIT_FAILURE);
//       close(fd[0]);
//       close(outfile);
//       char *cmd2_path = get_cmd_path(pipex->path, pipex->cmd2);
//       if (!cmd2_path)
//       {
//          ft_putstr_fd("command not found\n", 2);
//          cleanup(pipex, 127);
//       }
//       execve(cmd2_path, pipex->cmd2, envp);
//       free(cmd2_path);
//       cleanup(pipex, EXIT_FAILURE);
//    }
//    close(fd[0]);
//    close(fd[1]);
//    waitpid(pid1, &status1, 0);
//    waitpid(pid2, &status2, 0);
//    if (WIFEXITED(status2)) 
//       return (WEXITSTATUS(status2));
//    else
//       return (128 + WTERMSIG(status2));
// }