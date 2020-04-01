/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

//
// dlopen 
// dlsym
// dlclose
// dlerror
//

int getLib(char *lib);

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    getLib(av[1]);
    return (0);
}