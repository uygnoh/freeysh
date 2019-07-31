### swithc case
```c
void print_msg(int a)
{
    switch (a) {
    case 1:
        printf("a == 1\n");
        break;
    case 2:
        printf("a == 2\n");
        break;
    }
}
```
##### 手动去除这些行尾的空格是一件头大的事情，但对于sed来说不过是举手之劳：
 `sed 's/[ \t]*$//g' your_code.c`
 
 
### 一些需要注意的代码风格
1. 使用空格缩进“4个空格”
2. switch ... case ...语句中，switch和case具有相同的缩进（参考上文）；
3. 花括号的使用参考K&R风格。
4. 如果是函数，左花括号另起一行：
```c
int function(int x)
{
    body of function
}
```
+ 否则，花括号紧接在语句的最后：
```c
    if (x is true) {
        we do y
    }
```
+ 如果只有一行语句，则不需要用花括号：
```c
    if (condition)
        action();
```
+ 但是，对于条件语句来说，如果一个分支是一行语句，
+ 另一个分支是多行，则需要保持一致，使用花括号：
```c
    if (condition) {
        do_this();
        do_that();
    } else {
        otherwise();
    }
```
5. 空格, 在关键字“if, switch, case, for, do, while”之后需要加上空格，如：
    `if (something)`
6. 在关键字“sizeof, typeof, alignof, or __attribute__”之后不要加空格，如：
    `sizeof(struct file)`
7. 在括号里的表达式两边不要加空格，比如，下面是一个反面的例子：
    `sizeof( struct file )` warnings
8. 大多说的二元和三元运算符两边需要空格，
>  如“= + - < > * / % | & ^ <= >= == != ? :”；
9. 一元运算符后面不要空格，
>  如“& * + - ~ ! sizeof typeof alignof __attribute__ defined”；
10. 在前缀自增自减运算符之后和后缀自增自减运算符之前不需要空格（“++”和“--”）；
11. 成员运算符（“.”和“->”）的两边不需要空格；
12. 行尾不需要空格；
13. 注释, 使用C89的“/* ... */”风格.
14. 对于多行注释，可以参考下例：
```
/*
 * This is the preferred style for multi-line
 * comments in the Linux kernel source code.
 * Please use it consistently.
 *
 * Description: A column of asterisks on the left side,
 * with beginning and ending almost-blank lines.
 */
```
15. 多行的宏定义需要用“do .. while”封装，如：
```c
    #define macrofun(a, b, c)   \
    do {                        \
        if (a == 5)             \
            do_this(b, c);      \
    } while (0)
```











