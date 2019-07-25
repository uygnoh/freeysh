### ===========================================================================
多目录构建===标准工程	tree查看目录树
每个目录都有一个CMakeLists.txt
本次工程的全部文件：
2/CMakeLists.txt
2/core/sqrt.cpp
2/core/sqrt.h
2/core/CMakeLists.txt
2/example/demo.cpp
2/example/CMakeLists.txt
### ===========================================================================
 
2/CMakeLists.txt
++++++++++++++++
#cmake version
cmake_minimum_required(VERSION 2.8)
PROJECT(demoB)

SET(CPP_LIST ${})
MESSAGE(STATUS "initial_cpplist=" ${CPP_LIST})

ADD_SUBDIRECTORY(./core)
MESSAGE(STATUS "cpplsit_after_core=${CPP_LIST}")
ADD_SUBDIRECTORY(./example)
MESSAGE(STATUS "EXT_LIB_main" ${EXT_LIB})
MESSAGE(STATUS "CMAKE_BINARY_DIR=" ${CMAKE_BINARY_DIR})
MESSAGE(STATUS "PROJECT_BINARY_DIR=" ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "PROJECT_SOURCE_DIR=" ${PROJECT_SOURCE_DIR})

###主要通过MESSAGE去跟踪CPP_LIST和EXT_LIB两个变量，进而理解整个构建过程。


2/core/CMakeLists.txt
+++++++++++++++++++++ 
INCLUDE_DIRECTORIES(.)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/core CORE_CPP_LIST)
LIST(APPEND CPP_LIST ${CPP_LIST} ${CORE_CPP_LIST})
MESSAGE(STATUS "cpplist_core=${CPP_LIST}")
SET(CPP_LIST ${CPP_LIST} PARENT_SCOPE)
SET(EXT_LIB /usr/lib/x86_64-linux-gnu/libm.so)
SET(EXT_LIB ${EXT_LIB} PARENT_SCOPE)
MESSAGE(STATUS "EXT_LIB_cor=" ${EXT_LIB})


2/example/CMakeLists.txt
++++++++++++++++++++++++ 
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/example EXAM_CPP_LIST)
MESSAGE(STATUS "EXAM_CPP_LIST=${EXAM_CPP_LIST}")
MESSAGE(STATUS "before exam cpp_list=${EXAM_CPP_LIST}")
LIST(APPEND CPP_LIST $(CPP_LIST} ${EXAM_CPP_LIST})
MESSAGE(STATUS "cpplist_example=${CPP_LIST}")
ADD_EXECUTABLE(sqrtDemoC ${CPP_LIST})
SET(EXECUTABLE_OUTPUT_PATH"${CMAKE_BINARY_DIR}/bin")
MESSAGE(STATUS "EXT_LIB_example="${EXT_LIB})
TARGET_LINK_LIBRARBIES(sqrtDemoC ${EXT_LIB})

++++++++++++++ 
2/ mkdir build
cd build
cmake ..
make

### ===========================================================================
