#include "uni.h"

SCODE test_basic() {

    DEBUG("Hello World!\n");
    return S_OK;
}

void test_main() {

    test_basic();
    test_point();
    test_copy();
    test_worker();

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

SCODE test_worker() {
    INFO("Example - Worker\n");

    uni_array_t worker;
    init_uni_array(&worker, sizeof(worker_t));

    time_t current_time = current_unix_timestamp();
    time_t ten_days_later = current_time + (10 * 24 * 60 * 60);

    worker_t worker1 = {
        .revision                   = 1690269167291067486,
        .worker_id                  = "worker_id_01",
        .worker_name                = "worker1",
        .worker_alias               = "alias_worker1",
        .worker_status              = "status_01",
        .worker_type                = "user",
        .worker_lifecycle_starttime = current_time,
        .worker_lifecycle_endtime   = ten_days_later
    };

    worker_t worker2 = {
        .revision                   = 1690269167291067486,
        .worker_id                  = "worker_id_02",
        .worker_name                = "worker2",
        .worker_alias               = "alias_worker2",
        .worker_status              = "status_02",
        .worker_type                = "visitor",
        .worker_lifecycle_starttime = current_time,
        .worker_lifecycle_endtime   = ten_days_later
    };

    worker_t worker3 = {
        .revision                   = 1690269167291067486,
        .worker_id                  = "worker_id_03",
        .worker_name                = "worker3",
        .worker_alias               = "alias_worker3",
        .worker_status              = "status_03",
        .worker_type                = "user",
        .worker_lifecycle_starttime = current_time,
        .worker_lifecycle_endtime   = ten_days_later
    };

    push_to_uni_array(&worker, &worker1);
    push_to_uni_array(&worker, &worker2);
    push_to_uni_array(&worker, &worker3);
    
    print_uni_array(&worker, print_worker_element);
    DEBUG("worker_ua count: %d\n", (int)worker.count);

    free_uni_array(&worker);

    return S_OK;
}