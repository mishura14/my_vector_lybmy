#include <stdio.h>
#include <assert.h>
#include "vector.h"

void test_create_vector(void) {
    Vector *v = vector_create(sizeof(int), 4);

    assert(v != NULL);
    assert(v->data != NULL);
    assert(v->capacity == 4);
    assert(v->element_size == sizeof(int));
    assert(v->length == 0);

    free_vector(v);
    printf("✔ test_create_vector passed\n");
}

void test_append_ints(void) {
    Vector *v = vector_create(sizeof(int), 2);
    assert(v != NULL);

    for (int i = 0; i < 10; i++) {
        append(v, &i);
    }

    assert(v->length == 10);
    assert(v->capacity >= 10);

    for (size_t i = 0; i < v->length; i++) {
        int value = *(int *)((char *)v->data + i * v->element_size);
        assert(value == (int)i);
    }

    free_vector(v);
    printf("✔ test_append_ints passed\n");
}

void test_resize(void) {
    Vector *v = vector_create(sizeof(int), 1);
    assert(v != NULL);
    assert(v->capacity == 1);

    int a = 1, b = 2, c = 3;
    append(v, &a);
    append(v, &b);
    append(v, &c);

    assert(v->length == 3);
    assert(v->capacity >= 3);

    free_vector(v);
    printf("✔ test_resize passed\n");
}

int main(void) {
    test_create_vector();
    test_append_ints();
    test_resize();

    printf("\n✅ ALL TESTS PASSED\n");
    return 0;
}
