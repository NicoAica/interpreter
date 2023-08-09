cmake_minimum_required(VERSION 3.22)
project(interpreter)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        interpreter
        main.cpp
        Classes/Code/Block.cpp
        Classes/Header/Block.h
        Classes/Code/PrintStmt.cpp
        Classes/Header/PrintStmt.h
        Classes/Code/SetStmt.cpp Classes/Header/SetStmt.h Classes/Code/InputStmt.cpp Classes/Header/InputStmt.h Classes/Code/WhileStmt.cpp Classes/Header/WhileStmt.h Classes/Code/IfStmt.cpp Classes/Header/IfStmt.h Classes/Code/NumExpr.cpp Classes/Header/NumExpr.h Classes/Code/Operator.cpp Classes/Header/Operator.h Classes/Code/Number.cpp Classes/Header/Number.h Classes/Code/Variable.cpp Classes/Header/Variable.h Classes/Code/BoolExpr.cpp Classes/Header/BoolExpr.h Classes/Code/RelOp.cpp Classes/Header/RelOp.h Classes/Code/BoolConst.cpp Classes/Header/BoolConst.h Classes/Code/BoolOp.cpp Classes/Header/BoolOp.h)
