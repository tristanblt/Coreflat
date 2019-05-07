/*
** EPITECH PROJECT, 2018
** strcmp
** File description:
** strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int rest = 0;

    while (s1[i] == s2[i] && s1[1] != '\0' && s2[i] != '\0')
        i++;
    if (s1[i] != s2[i]) {
        rest = s1[i] - s2[i];
        return (rest);
    }
    return (0);
}
