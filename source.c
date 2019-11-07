//
// Created by Julius Brigette on 06/11/2019.
//
#include "header.h"

void	ft_memdel(void **ap)
{
    if (ap && *ap)
    {
        free(*ap);
        (*ap) = NULL;
    }
}

void	ft_bzero(void *s, size_t n)
{
    while (n-- >= 1)
        ((char *)s)[n] = 0;
}

void	*ft_memalloc(size_t size)
{
    void	*mem;

    if (!(mem = malloc(size)))
        return (NULL);
    ft_bzero(mem, size);
    return (mem);
}

char	*ft_strnew(size_t size)
{
    char	*str;

    if (size + 1 == 0)
        return (NULL);
    str = (char *)malloc((size + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    ft_bzero(str, size + 1);
    return (str);
}

void	*ft_memset(void *b, int c, size_t len)
{
    size_t i;

    i = 0;
    while (i < len)
        ((unsigned char *)b)[i++] = (unsigned char)c;
    return (b);
}
