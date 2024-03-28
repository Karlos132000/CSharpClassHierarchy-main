cmake_minimum_required(VERSION 3.27)
project(CSharpClassHierarchy_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(CSharpClassHierarchy-main/src)
include_directories(CSharpClassHierarchy-main/src/models)

add_executable(CSharpClassHierarchy_main
        CSharpClassHierarchy-main/src/models/CSharpClass.cpp
        CSharpClassHierarchy-main/src/models/CSharpClass.h
        CSharpClassHierarchy-main/src/models/CSharpField.cpp
        CSharpClassHierarchy-main/src/models/CSharpField.h
        CSharpClassHierarchy-main/src/models/CSharpMethod.cpp
        CSharpClassHierarchy-main/src/models/CSharpMethod.h
        CSharpClassHierarchy-main/src/models/CSharpNamespace.cpp
        CSharpClassHierarchy-main/src/models/CSharpNamespace.h
        CSharpClassHierarchy-main/src/CSharpHierarchy.cpp
        CSharpClassHierarchy-main/src/CSharpHierarchy.h
        CSharpClassHierarchy-main/src/interface.cpp
        CSharpClassHierarchy-main/src/models/runTests.cpp
        CSharpClassHierarchy-main/src/models/runTests.h
        CSharpClassHierarchy-main/src/models/ClassInterface.cpp
        CSharpClassHierarchy-main/src/models/ClassInterface.h
        CSharpClassHierarchy-main/src/models/ClassInterface.h)
