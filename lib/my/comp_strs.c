/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** compares two strings
*/

int str_cmp(char const *str_one, char const *str_two)
{
    if (*str_one == '\0' && *str_two == '\0')
        return 0;
    return ((*str_one - *str_two) == 0) ? str_cmp(str_one + 1, str_two + 1) :
    (*str_one - *str_two);
}
