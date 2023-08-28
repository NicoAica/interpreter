cmake_minimum_required(VERSION 3.21)
project(interpreter)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        interpreter
        main.cpp
        Classes/Program/Code/Block.cpp
        Classes/Program/Header/Block.h
        Classes/Program/Code/PrintStmt.cpp
        Classes/Program/Header/PrintStmt.h
        Classes/Program/Code/SetStmt.cpp Classes/Program/Header/SetStmt.h Classes/Program/Code/InputStmt.cpp Classes/Program/Header/InputStmt.h Classes/Program/Code/WhileStmt.cpp Classes/Program/Header/WhileStmt.h Classes/Program/Code/IfStmt.cpp Classes/Program/Header/IfStmt.h Classes/Program/Code/NumExpr.cpp Classes/Program/Header/NumExpr.h Classes/Program/Code/Operator.cpp Classes/Program/Header/Operator.h Classes/Program/Code/Number.cpp Classes/Program/Header/Number.h Classes/Program/Code/Variable.cpp Classes/Program/Header/Variable.h Classes/Program/Code/BoolExpr.cpp Classes/Program/Header/BoolExpr.h Classes/Program/Code/RelOp.cpp Classes/Program/Header/RelOp.h Classes/Program/Code/BoolConst.cpp Classes/Program/Header/BoolConst.h Classes/Program/Code/BoolOp.cpp Classes/Program/Header/BoolOp.h Classes/Token/Token.cpp Classes/Token/Token.h Classes/Token/Token.cpp Classes/Token/Token.h Classes/Token/Tokenizer.cpp Classes/Token/Tokenizer.h Classes/Error/Exceptions.h Classes/Helpers/StringHelper.h Classes/Manager/Manager.cpp Classes/Manager/Manager.h Classes/Program/Code/Statement.cpp Classes/Program/Header/Statement.h Classes/Program/Code/Program.cpp Classes/Program/Header/Program.h Classes/Parser/Parser.cpp Classes/Parser/Parser.h Classes/Helpers/TokenHelper.h Classes/Helpers/Helper.cpp Classes/Helpers/Helper.h)
