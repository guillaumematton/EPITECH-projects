/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** user_case
*/

#include "include/my.h"

int verify_passwd(char *passwd, char *pass, char *line, int k)
{
    int i = 0;
    int j = 0;
    char *crypted = malloc(sizeof(char) * strlen(line));

    pass[k] = '\0';
    if (crypted == NULL)
        return 84;
    for (; line[i] != ':'; i++);
    for (i += 1; line[i] != ':'; j++){
        crypted[j] = line[i];
        i++;
    }
    crypted[j] = '\0';
    passwd = crypt(passwd, pass);
    if (strcmp(passwd, crypted) == 0){
        free(crypted);
        return 0;
    }
    free(crypted);
    return 84;
}

int help_get_passwd(char *passwd, const char *user, char *line)
{
    int i = 0;
    char *pass = NULL;
    int j = 0;
    int err = 0;

    while (user[i] != '\0' && user[i] == line[i])
        i++;
    if (user[i] == '\0' && line[i] == ':'){
        pass = malloc(sizeof(char) * (strlen(line) - i));
        if (pass == NULL)
            return 84;
        for (i += 1; line[i - 1] != '$' || j < 6; j++){
            pass[j] = line[i];
            i++;
        }
        err = verify_passwd(passwd, pass, line, j);
        free(pass);
        return err;
    }
    return 0;
}

int get_password(char *passwd, const char *user)
{
    FILE *file = fopen("/etc/shadow", "r");
    size_t len = 0;
    char *line = NULL;

    if (file == NULL){
        free(passwd);
        return 84;
    }
    while (feof(file) != 1){
        getline(&line, &len, file);
        if (help_get_passwd(passwd, user, line) == 84){
            double_free(line, file);
            free(passwd);
            return 84;
        }
    }
    free(line);
    fclose(file);
    free(passwd);
    return 0;
}

void change_eof(char *buffer)
{
    for (int i = 1; buffer[i - 1] != '\0'; i++){
        if (buffer[i] == '\n')
            buffer[i] = '\0';
    }
}

int passwd_input(char *login)
{
    char *buffer = malloc(sizeof(char) * 101);
    int err = 0;

    if (buffer == NULL)
        return 84;
    my_putstr("[my_sudo] password for ");
    my_putstr(login);
    my_putstr(": ");
    if (strcmp(login, "root") != 0){
        disable_echo();
        read(STDIN_FILENO, buffer, 100);
        enable_echo();
        change_eof(buffer);
        if (get_password(buffer, login) == 84)
            return 84;
        my_putstr("\n");
    }
    return err;
}
