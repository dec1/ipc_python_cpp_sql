#!/bin/bash


# build app
# ----------

source ./my_vars.sh

# for testing (remove build dir each time to prevent cofusinon with cmake cache between runs)
# warning - use with caution - here be dragons!
#   rm -rf ./$MY_BUILD_DIR

echo " ----------------------------------------------------------"

echo "cmake version= $(cmake --version)"

# -----------------------------------------
# configure
cmake . -B./$MY_BUILD_DIR -DCMAKE_BUILD_TYPE=$MY_BUILD_TYPE -DCMAKE_PREFIX_PATH=$MY_CMAKE_PREFIX_PATH

# build
cmake --build $MY_BUILD_DIR --config $MY_BUILD_TYPE


# clang-tidy
# ---------
    # creates 'compile_commands.json' in 'build' dir
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON $MY_BUILD_DIR
    # run clang-tidy
python3 ./run-clang-tidy.py -p $MY_BUILD_DIR -checks='clang-*' -config="{WarningsAsErrors: '*'}"  -header-filter='.*'


# -----------------------------------------








