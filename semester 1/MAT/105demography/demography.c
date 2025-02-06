/*
** EPITECH PROJECT, 2025
** 105demography
** File description:
** 105demography
*/

#include "include/my.h"

int read_line(char *line, char **argv)
{
    int i = 0;
    int *nbr_array = NULL;

    for (; line[i] != ';'; i++);
    i++;
    if (line[i] == argv[1][0] && line[i + 1] == argv[1][1]
        && line[i + 2] == argv[1][2])
        nbr_array = get_nbrs(line, i);
    else
        return 1;
    if (nbr_array == NULL)
        return 84;
    printf("Country : ");
    for (int j = 0; line[j] != ';'; j++)
        putchar(line[j]);
    putchar('\n');
    manipulate_values(nbr_array);
    free(nbr_array);
    return 0;
}

int open_file(char **argv)
{
    FILE *file = fopen("105demography_data.csv", "r");
    char *line = NULL;
    ssize_t size = 0;
    int temp_size = 0;
    int i = 1;

    if (file == NULL)
        return 84;
    temp_size = getline(&line, &size, file);
    if (temp_size == -1){
        fclose(file);
        free(line);
        return 84;
    }
    for (; temp_size != 0 && i == 1; temp_size = getline(&line, &size, file))
        i = read_line(line, argv);
    free(line);
    fclose(file);
    return i;
}

int demography(int argc, char **argv)
{
    if (argc < 2)
        return 84;
    if (strcmp(argv[1], "-h") == 0 && argc == 2){
        printf("USAGE\n");
        printf("    ./105demography [code]+\n");
        printf("\n");
        printf("DESCRYPTION\n");
        printf("   code     country code\n");
    } else
        open_file(argv);
    return 0;
}

int main(int argc, char *argv[])
{
    int err = 0;

    err = demography(argc, argv);
    return err;
}
