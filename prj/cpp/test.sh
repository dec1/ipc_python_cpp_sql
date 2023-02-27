#!/bin/bash

source ./my_vars.sh

chmod a+x ./$MY_BUILD_DIR/my_app_test

echo "qt test runner: ./$MY_BUILD_DIR/my_app_test"
./$MY_BUILD_DIR/my_app_test -vs -o ./$MY_BUILD_DIR/test_results.xml,junitxml 

echo "cmake test runner...."
ctest --test-dir ./$MY_BUILD_DIR --verbose --output-junit ctest_results.xml
 
