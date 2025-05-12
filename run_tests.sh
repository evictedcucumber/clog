#!/usr/bin/env sh

echo "Running cmake..."
cmake -B build -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON && cmake --build build

echo "Running tests..."

find build -type f -name "clog_*_test*" -exec echo "Running {}..." \; -exec {} \;

echo "Running valgrind tests..."

find build -type f -name "clog_*_test*" -exec echo "Running valgrind on {}..." \; -exec valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes {} \;
