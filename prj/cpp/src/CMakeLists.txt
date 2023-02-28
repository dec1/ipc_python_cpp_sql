
set(My_Dir ${CMAKE_CURRENT_LIST_DIR})


set(My_Sources 


    ${My_Dir}/my_store.h
    ${My_Dir}/my_parse_result.h

    ${My_Dir}/my_store_db.cpp
    ${My_Dir}/my_store_db.h


    ${My_Dir}/my_net.h
    ${My_Dir}/my_net.cpp

    ${My_Dir}/my_parser.h
    ${My_Dir}/my_parser.cpp
 )
 

target_include_directories(${My_Targ} PUBLIC ${My_Dir})
target_sources(${My_Targ} PRIVATE ${My_Sources})

target_sources(${My_TargExe}  PRIVATE ${My_Dir}/main.cpp)
