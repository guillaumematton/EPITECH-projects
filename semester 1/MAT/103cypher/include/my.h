/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

void print_help(void);
int encrypt_2x2(char **argv, double *key);
int decrypt_2x2(char **argv, double *key);
void print_decrypted(int *decrypted, int i, double *key);
void print_encrypted(int *encrypted, int *message, int i, int size);
int decrypt_3x3(char **argv, double *key);
int encrypt_3x3(char **argv, double *key);
void print_encription_matrix(double *key, int size);
void print_decription_matrix(double *key, int size);
int *get_message(char **argv, int *message);
int *get_message_2x2(char **argv, int *message);
int *get_decrypted_message(int *message, int *decrypted, double *key);

#endif /* !MY_H_ */
