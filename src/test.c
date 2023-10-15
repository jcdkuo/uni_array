#include "uni.h"

void print_int_element(void* element) {
    int* int_ptr = (int*)element;
    printf("%d \n", *int_ptr);
}

void print_double_element(void* element) {
    double* double_ptr = (double*)element;
    printf("%f \n", *double_ptr);
}

SCODE test_basic() {

    DEBUG("Hello World!\n");
    return S_OK;
}


void test_main() {

    test_basic();
    test_point();
    test_copy();

}

SCODE test_point() {
    INFO("Example - Point\n");

    uni_array_t point_array;
    init_uni_array(&point_array, sizeof(Point));

    Point p1 = {1, 2};
    Point p2 = {3, 4};
    Point p3 = {5, 6};

    push_to_uni_array(&point_array, &p1);
    push_to_uni_array(&point_array, &p2);
    push_to_uni_array(&point_array, &p3);

    Point* retrieved_point_1 = (Point*)get_from_uni_array(&point_array, 0);
    if (retrieved_point_1) {
        printf("Point 1: (%d, %d)\n", retrieved_point_1->x, retrieved_point_1->y);
    }

    remove_from_uni_array(&point_array, 1);

    Point* retrieved_point_2 = (Point*)get_from_uni_array(&point_array, 1);
    if (retrieved_point_2) {
        printf("Point 2: (%d, %d)\n", retrieved_point_2->x, retrieved_point_2->y);
    }

    free_uni_array(&point_array);
    return S_OK;
}

SCODE test_copy() {
    INFO("Copy uni_array_t!\n");

    uni_array_t arrayA;
    uni_array_t arrayB;

    init_uni_array(&arrayA, sizeof(int));

    int num1 = 42;
    int num2 = 77;

    push_to_uni_array(&arrayA, &num1);
    push_to_uni_array(&arrayA, &num2);

    copy_uni_array(&arrayA, &arrayB);

    print_uni_array(&arrayA, print_int_element);
    print_uni_array(&arrayB, print_int_element);

    free_uni_array(&arrayA);
    free_uni_array(&arrayB);

    return S_OK;
}
