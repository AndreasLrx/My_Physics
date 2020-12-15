/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** my pow
*/

double my_pow(double p, int n)
{
    double res = 1;

    for (int i = 0; i < n; i++)
        res *= p;
    return res;
}