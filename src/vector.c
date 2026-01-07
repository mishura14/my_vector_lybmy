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
Vector *vector_create(size_t element_size, size_t capacity)
{
    Vector* v = malloc(sizeof *v);
    if(!v) return NULL;
    v->data = malloc(capacity * element_size);
    if(!v->data){
        free(v);
        return NULL;
    }
    v->capacity = capacity;
    v->element_size = element_size;
    v->length = 0;
    return v;
};
//метод очистки вектора из памяти
void free_vector(Vector *v)
{
    free(v->data);
    free(v);
}
//метод добавление элеметов в конец вектора
void append(Vector *v, const void *value)
{
    if (v->length >= v->capacity) {
        v->capacity = (v->capacity == 0) ? 2 : v->capacity * 2;

        v->data = realloc(v->data, v->capacity * v->element_size);
        if (!v->data) {
            perror("realloc");
            exit(1);
        }
    }

    memcpy(
        (char *)v->data + v->length * v->element_size,
        value,
        v->element_size
    );

    v->length++;
}
//метод удаление элемента из конца вектора
void pop(Vector *v,void *back_element)
{
    if(v->length == 0){
        return;
    }
    v->length--;
    if(back_element){
        memcpy(back_element,(char *)v->data + v->length * v->element_size, v->element_size);
    }

}
//метод get возвращающий указатель на элемент по индексу
void* get(Vector *v, size_t index)
{
    if(index >= v->length){
        return NULL;
    }
    return (char*)v->data + index * v->element_size;
}

// метод set перезаписывающий элемент по индексу

// метод erase удалающий элемент по индексу

// метод clear очищающий элементы вектора но не удалая его самово

// метод reverse увеличивающий capacity вектора

// insert вставка по индексу
