/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include "lib.h"
    #include <stddef.h>

int exec_cd(char **array, env_t **env);
int exec_env(char **array, env_t **environ);
int exec_setenv(char **array, env_t **environ);
int exec_unsetenv(char **array, env_t **environ);
int exec_cmd(char **array, env_t **environ);
int modify_old_pwd(env_t **env);
int modify_pwd(env_t **env, char *path);
char *if_not_tty(char *buffer, size_t len);
int find_tty(void);
int cd_home(char **array, env_t **env);
int cd_home_other_user(env_t **env, char **array);
void cmd_err(char *oldpath, char **tenv);
void double_free(char *oldpath, char **tenv);
int cd_go_to_old(char *newvar, env_t *envlist, env_t **env);

#endif /* !MY_H_ */
