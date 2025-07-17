#include "pipex.h"

char **cmd_array(int argc, char **argv)
{
    char **cmd;

    if (argc < 1 || !argv)
        return (NULL);
    cmd = ft_split(argv[argc - 1], ' ');
    if (!cmd)
        return (NULL);
    return (cmd);    
}

char **find_path(char **envp)
{
    char *one_line;
    char **path;
    
    if (!envp)
        return (NULL);
    one_line = NULL;
    while (*envp != NULL)
    {
        if (ft_strncmp(*envp, "PATH=", 5) == 0)
        {
            one_line = ft_strdup(*envp + 5);
            break;
        }
        envp++;
    }
    if (!one_line)
        return (NULL);
    path = ft_split(one_line, ':');
    if (!path)
        return (NULL);
    return (path);
}

char *get_cmd_path(char **path, char **cmd_array)
{
    int i;
    char *full_path;
    char *cmd;
    size_t path_len;
    size_t total_len;

    i = 0;
    while (path[i])
    {
        cmd = cmd_array[0];
        path_len = ft_strlen(path[i]);
        total_len = path_len + ft_strlen(cmd) + 2;
        full_path = malloc(total_len);
        if (!full_path)
            return (NULL);
        ft_memcpy(full_path, path[i], path_len);
        full_path[path_len] = '/';
        ft_strlcat(full_path, cmd, total_len);
        if (access(full_path, X_OK) == 0)
            return (full_path);
        // else
        // {
        //     free(full_path);
        //     full_path
        //     ft_perror("access failed");
        // }
        free(full_path);
        i++;
    }
    return (NULL);
}