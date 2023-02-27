cmake_minimum_required(VERSION 3.14)

project(my_app LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#--------------------------------------------------------------------------
set(My_Targ         ${PROJECT_NAME})
set(My_TargExe      ${PROJECT_NAME}_main)
set(My_TargTest     ${PROJECT_NAME}_test)
#-----------------------------------
add_library(${My_Targ} STATIC)
add_executable(${My_TargExe})
add_executable(${My_TargTest})

#--------------------------------------------------------------------------
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Sql)
find_package(Qt6 REQUIRED COMPONENTS Test)
#find_package(Qt6 REQUIRED COMPONENTS HttpServer)
find_package(Qt6 REQUIRED COMPONENTS Network)



enable_testing(true)
#-------------------------
target_link_libraries (${My_TargExe}    PRIVATE ${My_Targ})
target_link_libraries (${My_TargTest}   PRIVATE ${My_Targ} Qt::Test)

target_link_libraries(${My_Targ} INTERFACE Qt6::Core)
target_link_libraries(${My_Targ} PRIVATE Qt6::Sql)
target_link_libraries(${My_Targ} PRIVATE Qt6::Network)
#target_link_libraries(${My_Targ} PRIVATE Qt6::HttpServer)
#-------------------------
add_test(NAME ${My_TargTest} COMMAND ${My_TargTest})

# set(CMAKE_INCLUDE_CURRENT_DIR ON)

#--------------------------------------------------------------------------
#enable_testing(true)

add_subdirectory(src)
add_subdirectory(tests)


#------------------------
