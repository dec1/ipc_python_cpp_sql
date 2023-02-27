
set(My_Dir ${CMAKE_CURRENT_LIST_DIR})


target_sources( ${My_TargTest} PRIVATE
    my_tests.cpp     	my_tests.h
    my_math.cpp     	my_math.h
    )
	
target_include_directories(${My_TargTest} PUBLIC ${My_Dir})
#---------------------------------------------------------

