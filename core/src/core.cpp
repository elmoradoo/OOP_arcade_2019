/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** core
*/

#include <dlfcn.h>
#include "../../lib/ILib.hpp"

int getLib(char *lib)
{
    void *handle = dlopen(lib, RTLD_LAZY);
    ILib (*entry)(void);

    if (handle == nullptr)
        return (-1);
    *(ILib**)(&entry) = dlsym(handle, "entry_point");
    ILib Mourad = entry();
}



//  void *handle;
//     void (*func_print_name)(void);

//     handle = dlopen("./foo.so", RTLD_LAZY);
//     if (!handle) {
//         /* fail to load the library */
//         std::cout << "Library loading failed abort abort ffs" << std::endl;
//         return -1;
//     }
//     *(void**)(&func_print_name) = dlsym(handle, "entry_point");
//     func_print_name();
//     dlclose(handle);

