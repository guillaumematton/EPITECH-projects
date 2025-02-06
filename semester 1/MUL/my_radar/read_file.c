/*
** EPITECH PROJECT, 2025
** radar
** File description:
** read_file
*/

#include "include/my.h"
#include "include/c_lib.h"

int read_airplane(char *line, airplane_t **airplane)
{
    int i = 1;

    for (int j = 0; j < 6; j++){
        if (line[i] != ' ')
            return 84;
        i++;
        if ('0' > line[i] || line[i] > '9')
            return 84;
        for (; '0' <= line[i] && line[i] <= '9'; i++);
    }
    if (line[i] != '\n' && line[i] != '\0')
        return 84;
    return 0;
}

int get_file_error_status(char *line, tower_t **tower,
    airplane_t **airplane)
{
    int status = 0;

    if (line[0] != 'A' && line[0] != 'T')
        status = 84;
    if (line[0] == 'A')
        status = read_airplane(line, airplane);
    if (line[0] == 'T')
        status = read_tower(line, tower);
    if (status == 84){
        write(2, "error : wrong file format\n", 26);
        return 84;
    }
    return status;
}

void end_getline(FILE *file, char *line)
{
    free(line);
    fclose(file);
    return;
}

int read_file(char *argv, airplane_t **airplane, tower_t **tower)
{
    FILE *file = fopen(argv, "r");
    char *line = NULL;
    size_t len = 0;
    size_t line_len = 0;
    int status = 0;

    if (file == NULL)
        return 84;
    while (status == 0) {
        line_len = getline(&line, &len, file);
        if (line_len == -1){
            end_getline(file, line);
            return 84;
        }
        status = get_file_error_status(line, tower, airplane);
    }
    end_getline(file, line);
    if (status == 84)
        return 84;
    return 0;
}
