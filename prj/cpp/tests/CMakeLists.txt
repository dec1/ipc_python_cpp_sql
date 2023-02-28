
set(My_Dir ${CMAKE_CURRENT_LIST_DIR})


target_sources( ${My_TargTest} PRIVATE
    ${My_Dir}/my_tests.cpp
    ${My_Dir}/my_tests.h

    ${My_Dir}/my_math.cpp
    ${My_Dir}/my_math.h

    ${My_Dir}/my_store_file.cpp
    ${My_Dir}/my_store_file.h

    ${My_Dir}/my_store_mem.cpp
    ${My_Dir}/my_store_mem.h

    )
	
target_include_directories(${My_TargTest} PUBLIC ${My_Dir})
#---------------------------------------------------------

