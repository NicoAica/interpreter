# LISP-like Interpreter

This code is a Computer Engineering project from Genoa in which the programming of a C++ interpreter for a 'Context-free grammar' was required, as described below.

## Structure of project

First, the program performs a lexical analysis that returns a sequence of tokens; subsequently, through a syntactic analysis, a syntax tree is created. Finally, by utilizing the __Visitor__ design pattern, the tree is evaluated, thus interpreting the code.

## Usage

After compiling the program, it should be executed using the following command:

```

./interpreter.exe -[path to the file with the lisp code]

```

*The command may vary slightly depending on the operating system and how the code is compiled.*

In cmake-build-debug folder there's already inside a test file called **test.txt**

## Abstract Grammar

_Program_

<pre>
program        → stmt_block 
stmt_block     → statement | <b>( BLOCK </b>statement_list <b>)</b> 
statement_list → statement statement_list | statement 
</pre>

_Statement_

<pre>
statement → variable_def | io_stmt | cond_stmt | loop_stmt
  
variable_def → <b>( SET</b> variable_id num_expr <b>)</b>
io_stmt      → <b>( PRINT</b> num_expr <b>)</b> | <b>( INPUT</b> variable_id <b>)</b>
cond_stmt    → <b>( IF</b> bool_expr stmt_block stmt_block <b>)</b>
loop_stmt    → <b>( WHILE</b> bool_expr stmt_block <b>)</b>
</pre>

_Numerical Expression_

<pre>
num_expr → <b>( ADD</b> num_expr num_expr <b>)</b> | <b>( SUB</b> num_expr num_expr <b>)</b> | <b>( MUL</b> num_expr num_expr <b>)</b> 
         | <b>( DIV</b> num_expr num_expr <b>)</b> | <b>number</b> | <b>variable_id</b>
</pre>

_Boolean Expression_

<pre>
bool_expr → <b>( LT</b> num_expr num_expr <b>)</b> | <b>( GT</b> num_expr num_expr <b>)</b> | <b>( EQ</b> num_expr num_expr <b>)</b> 
          | <b>( AND</b> bool_expr bool_expr <b>)</b> | <b>( OR</b> bool_expr bool_expr <b>)</b> | <b>( NOT</b> bool_expr <b>)</b> | <b>TRUE</b> | <b>FALSE</b>
</pre>

_Variable name e Number_

<pre>

variable_id → alpha_list
alpha_list  → alpha alpha_list | alpha
alpha       → <b>a</b> | <b>b</b> | <b>c</b> | . . . | <b>z</b> | <b>A</b> | <b>B</b> | <b>C</b> | . . . | <b>Z</b>

number    → <b>-</b> posnumber | posnumber
posnumber → <b>0</b> | sigdigit rest
sigdigit  → <b>1</b> | . . . | <b>9</b>
rest      → digit rest | <b>ε</b>
digit     → <b>0</b> | sigdigit
</pre>

