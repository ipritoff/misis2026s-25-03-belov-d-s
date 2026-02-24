#include <arrayd/arrayd.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[arrayd] - constructor") {
    ArrayD arr1;
    CHECK(arr1.size() == 0);

    ArrayD arr2(5);
    CHECK(arr2.size() == 5);

    CHECK_THROWS(ArrayD(-1));
}

TEST_CASE("[arrayd] - copy") {
    ArrayD arr1(3);
    arr1[0] = 1.0;
    arr1[1] = 2.0;
    arr1[2] = 3.0;

    ArrayD arr2(arr1);
    CHECK(arr2.size() == 3);
    CHECK(arr2[0] == 1.0);
    CHECK(arr2[1] == 2.0);
    CHECK(arr2[2] == 3.0);

    arr2[0] = 10.0;
    CHECK(arr1[0] == 1.0);
}

TEST_CASE("[arrayd] - resize") {
    ArrayD arr;
    CHECK(arr.size() == 0);

    arr.resize(3);
    CHECK(arr.size() == 3);

    arr[0] = 1.0;
    arr[1] = 2.0;
    arr[2] = 3.0;

    arr.resize(5);
    CHECK(arr.size() == 5);
    CHECK(arr[0] == 1.0);
    CHECK(arr[1] == 2.0);
    CHECK(arr[2] == 3.0);

    arr.resize(2);
    CHECK(arr.size() == 2);
    CHECK(arr[0] == 1.0);
    CHECK(arr[1] == 2.0);

    CHECK_THROWS(arr.resize(-1));
}

TEST_CASE("[arrayd] - insert and remove") {
    ArrayD arr(3);
    arr[0] = 1.0;
    arr[1] = 2.0;
    arr[2] = 3.0;

    SUBCASE("insert") {
        arr.insert(1, 5.0);
        CHECK(arr.size() == 4);
        CHECK(arr[0] == 1.0);
        CHECK(arr[1] == 5.0);
        CHECK(arr[2] == 2.0);
        CHECK(arr[3] == 3.0);

        CHECK_THROWS(arr.insert(-1, 0.0));
        CHECK_THROWS(arr.insert(5, 0.0));
    }

    SUBCASE("remove") {
        arr.remove(1);
        CHECK(arr.size() == 2);
        CHECK(arr[0] == 1.0);
        CHECK(arr[1] == 3.0);

        CHECK_THROWS(arr.remove(-1));
        CHECK_THROWS(arr.remove(2));
    }
}

TEST_CASE("[arrayd] - exceptions") {
    ArrayD arr(3);

    CHECK_THROWS(arr[-1]);
    CHECK_THROWS(arr[3]);

    const ArrayD& const_arr = arr;
    CHECK_THROWS(const_arr[-1]);
    CHECK_THROWS(const_arr[3]);
}