
docker image
-------------
    see dockerfile: 
        qt6.4.2_mysql8_ubuntu20.04.df

docker container
------------------   
    docker rm my_ctr
    docker run  -p 8080:8080  -v /home/declan/Documents/zone/high/dev/ipc_python_cpp_sql/:/home/docker-share -it --entrypoint=/bin/bash --name my_ctr my_img
    cd /home/docker-share/prj
    

CMAKE_PREFIX_PATH (for qt)
--------------------------
    # docker (stateoftheartio)
    export CMAKE_PREFIX_PATH=/opt/Qt/6.4.0/gcc_64


    # linux
    # export CMAKE_PREFIX_PATH=/home/declan/Documents/zone/mid/dev/qt/6.4.2/gcc_64

    # mac
    # export CMAKE_PREFIX_PATH=/Users/declan/Qt/6.4.2/macos
    # export CLANG_TIDY_PATH="/Users/declan/Qt/Qt Creator.app/Contents/Resources/libexec/clang/bin/clang-tidy"


pipeline
--------
    # build cpp
    cd ./cpp && ./build.sh

    # run c++ tests
    ./build/my_app_test

    # ensure mysql service is running and create database
    sudo ./db_init.sh

    cd ../python/prj && ./venv_create.sh

    # run python test
    cd .. &&  sudo ./prj/venv/bin/pytest test/test__client.py::test_multiple_cpp_procs --capture=sys -s




