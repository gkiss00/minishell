#include "header/minishell.h"

static void     init_data(t_data *data)
{
    data->i1 = 0;
    data->i2 = 0;
    data->i3 = 0;
    data->c1 = 0;
    data->c2 = 0;
    data->tmp = NULL;
    data->tab_tmp = NULL;
    data->gnl_ret = 0;
    data->gnl_line = NULL;
    data->gnl_tmp = NULL;
    data->tabinput = NULL;
    data->env = NULL;
    data->path = NULL;
    data->cmd = NULL;
    data->cmd_tab = NULL;
    data->cmd_act = 0;
    data->fd = 1;
    data->last_output = 0;
    data->ret = 0;
}

static int     fill_data(t_data *data)
{
    if ((data->env = ft_copy_tab(environ)) == NULL)
        return (1);
    if ((data->path = ft_calloc(1, 200)) == NULL)
    {
        ft_free_data(data);
        return(1);
    }
    if (getcwd(data->path, 200) == NULL)
    {
        ft_free_data(data);
        return (1);
    }
    return (0);
    
}

static void     launch_programme()
{
    t_data *data;

    if ((data = malloc(sizeof(t_data))) == NULL)
        return ;
    init_data(data);
    if (fill_data(data) == 1)
        return ;
    while(1)
    {
        write(1, "-> minishell # ", 15);
        ft_programme(data);
    }
    ft_free_data(data);
}

int             main(void)
{
    //signal(SIGINT, ft_sigint);
	//signal(SIGQUIT, ft_sigquit);
    launch_programme();
}