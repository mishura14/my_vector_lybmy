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
//метод добавление элеметов в вектор
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
