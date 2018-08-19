#ifndef __EXAMPLES_MEMORIA_HPP__
#define __EXAMPLES_MEMORIA_HPP__

#include <iostream>


int& get_stack_10()
{
    int ret = 10;
    return ret;
}


int* get_heap_10()
{
    return new int{10};
}


void p_play_example(int* ip)
{
    std::cout << "Direccion y contenido del puntero" << std::endl;
    std::cout << "memdir: " << ip << " value: "<< *ip << std::endl;
    //que pasa si pasamos a la siguiente direccion de memoria
    int* ip2 = ip + 1;
    std::cout << "Siguiente direccion" << std::endl;
    std::cout << "memdir: " << ip2 << " value: "<< *ip2 << std::endl;
    std::cout << "Siguiente direccion" << std::endl;
    std::cout << "memdir: " << ++ip2 << " value: "<< *++ip2 << std::endl;

}


void p_aritmetica()
{
    int* p      = new int{100};
    std::cout << "Direccion y contenido de p" << std::endl;
    std::cout << "memdir: " << p << " value: "<< *p << std::endl;
    int  a      = *p; //acceso al contenido
    std::cout << "Direccion y contenido de a (copia del valor en p)" << std::endl;
    std::cout << "memdir: " << &a << " value: "<< a << std::endl;
    int* p2     = p; //copia del puntero, ahora los 2 pueden acceder y modificar esa direccion de memoria
    std::cout << "Direccion y contenido de p2 (copia del puntero p)" << std::endl;
    std::cout << "memdir: " << p2 << " value: "<< *p2 << std::endl;
    *p2 += 10;
    std::cout << "Resultado de modificar p2 reflejado en p" << std::endl;
    std::cout << "memdir: " << p << " value: "<< *p << std::endl;
    int** pp    = &p; //puntero a que apunta a un puntero
    std::cout << "Direccion y contenido de pp, puntero que apunta a p" << std::endl;
    std::cout << "memdir: " << pp << " value: "<< *pp << std::endl; //una redireccion
    std::cout << "memdir: " << pp << " value: "<< **pp << std::endl;//doble redireccion
    std::cout << "Resultados de aritmetica de punteros, accesos a otras direcciones" << std::endl;
    ++p; //siguiente direccion de memoria
    std::cout << "memdir: " << ++p << " value: "<< *(++p) << std::endl;
    --p; //direccion de memoria anterior
    std::cout << "memdir: " << --p << " value: "<< *(--p) << std::endl;
    int* p3 = p + 4;//direccion cuatro ints mas lejos en memoria
    std::cout << "memdir: " << p3 << " value: "<< *p3 << std::endl;
}


void copy_reference_pointer_example(int a, int& ra, int* pa)
{
    std::cout << "Direccion y contenido de la copia" << std::endl;
    std::cout << "memdir: " << &a << " value: "<< a << std::endl;
    std::cout << "Direccion y contenido de la referencia" << std::endl;
    std::cout << "memdir: " << &ra << " value: "<< ra << std::endl;
    std::cout << "Direccion y contenido del puntero" << std::endl;
    std::cout << "memdir: " << pa << " value: "<< *pa << std::endl;

    std::cout << "a += 10" << std::endl;
    a += 10;
    std::cout << "Direccion y contenido de la copia" << std::endl;
    std::cout << "memdir: " << &a << " value: "<< a << std::endl;
    std::cout << "Direccion y contenido de la referencia" << std::endl;
    std::cout << "memdir: " << &ra << " value: "<< ra << std::endl;
    std::cout << "Direccion y contenido del puntero" << std::endl;
    std::cout << "memdir: " << pa << " value: "<< *pa << std::endl;

    std::cout << "ra += 10" << std::endl;
    ra += 10;
    std::cout << "Direccion y contenido de la copia" << std::endl;
    std::cout << "memdir: " << &a << " value: "<< a << std::endl;
    std::cout << "Direccion y contenido de la referencia" << std::endl;
    std::cout << "memdir: " << &ra << " value: "<< ra << std::endl;
    std::cout << "Direccion y contenido del puntero" << std::endl;
    std::cout << "memdir: " << pa << " value: "<< *pa << std::endl;
}

void all_memory_examples()
{
    int a = 10;
    p_play_example(&a);
    std::cout << std::endl;
    p_aritmetica();
    std::cout << std::endl;
    copy_reference_pointer_example(a, a, &a);
    std::cout << "a outside copy_reference_pointer_example_fucntion "<< std::endl;
    std::cout << "a : " << a << std::endl;
    std::cout << std::endl;
}

#endif //EXAMPLES_MEMORIA_HPP
