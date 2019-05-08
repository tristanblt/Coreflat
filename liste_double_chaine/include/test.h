/*
** EPITECH PROJECT, 2019
** liste_double_chaine
** File description:
** test
*/

#ifndef TEST_H_
#define TEST_H_

typedef struct list_s
{
    int val;
    int id;
    struct list_s *prev;
    struct list_s *next;
} list_t;

#endif /* !TEST_H_ */