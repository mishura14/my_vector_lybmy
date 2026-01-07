#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



typedef struct{
    void *data;
    size_t capacity;
    size_t element_size;
    size_t length;

}Vector;

//метод создания вектора
Vector *vector_create(size_t element_size, size_t capacity);

//метод очистки вектора из памяти
void free_vector(Vector *v);

//метод добавление элеметов в вектор
void append(Vector *v, const void *value);

//метод удаление элемента из конца вектора
void pop(Vector *v,void *back_element);

//метод get возвращающий указатель на элемент по индексу
void* get(Vector *v, size_t index);
