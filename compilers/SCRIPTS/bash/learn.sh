#!/bin/bash
if [ $1 = 1 -o  $1 = "read" ]; then
    echo "do_read"
elif [ $1 = 2 -o $1 = "write" ]; then
    echo "do_write"
else
    echo "do_other"
fi

# 用户输入
# read 命令接收键盘的输入，标准输入(Standard Input)


read -p "Please Enter You Name: " name
echo "Your Name Is: $name"

# 文件测试操作
-d FILE_NAM  # True if FILE_NAM is a directory
-e FILE_NAM  # True if FILE_NAM exists
-f FILE_NAM  # True if FILE_NAM exists and is a regular file
-r FILE_NAM  # True if FILE_NAM is readable
-s FILE_NAM  # True if FILE_NAM exists and is not empty
-w FILE_NAM  # True if FILE_NAM has write permission
-x FILE_NAM  # True if FILE_NAM is executable


# 字符串测试操作
-z STRING         # True if STRING is empty
-n STRING         # True if STRING is not empty
STRING1 = STRIN2  # True if strings are equal
STRING1 != STRIN2 # True if strings are not equal


# 算术测试操作
var1 -eq var2     # True if var1 is equal to var2
var1 -ne var2     # True if var1 not equal to var2
var1 -lt var2     # True if var1 is less than var2
var1 -le var2     # True if var1 is less than or equal to var2
var1 -gt var2     # True if var1 is greater than var2
var1 -ge var2     # True if var1 is greater than or equal to var2


# 条件判断 if-else if-elif-else
if [ condition-is-true ]
then
  command 1
  command 2
    ...
    ...
  command N
fi

if [ condition-is-true ]
then
  command 1
elif [ condition-is-true ]
then
  command 2
elif [ condition-is-true ]
then
  command 3
else
  command 4
fi

case "$VAR" in
  pattern_1)
    # commands when $VAR matches pattern 1
    ;;
  pattern_2)
    # commands when $VAR matches pattern 2
    ;;
  *)
    # This will run if $VAR doesnt match any of the given patterns
    ;;
esac

Example
#!/bin/bash
read -p "Enter the answer in Y/N: " ANSWER
case "$ANSWER" in
  [yY] | [yY][eE][sS])
    echo "The Answer is Yes :)"
    ;;
  [nN] | [nN][oO])
    echo "The Answer is No :("
    ;;
  *)
    echo "Invalid Answer :/"
    ;;
esac


# 迭代语句 - 循环
for VARIABLE_NAME in ITEM_1 ITEM_N
do
  command 1
  command 2
    ...
    ...
  command N
done

Example
#!/bin/bash
COLORS="red green blue"
for COLOR in $COLORS
do
  echo "The Color is: ${COLOR}"
done

for (( VAR=1;VAR<N;VAR++ ))
do
  command 1
  command 2
    ...
    ...
  command N
done

# 在当前所有txt文件前面追加new实现重命名
#!/bin/bash
FILES=$(ls *txt)
NEW="new"
for FILE in $FILES
do
  echo "Renaming $FILE to new-$FILE"
  mv $FILE $NEW-$FILE
done


while [ CONNDITION_IS_TRUE ]
do
  # Commands will change he entry condition
  command 1
  command 2
    ...
    ...
  command N
done

# 例子 一行一行读取文件内容
#!/bin/bash
LINE=1
while read CURRENT_LINE
do
  echo "${LINE}: $CURRENT_LINE"
  ((LINE++))
done < /etc/passwd
# This script loops through the file /etc/passwd line by line
注意⚠️
continue 用于结束本次循环
break 用于结束整个循环



# 参数传递
# 当我们运行脚本的时候，可以传递参数供脚本内部使用$ ./script.sh param1 param2 param3 param4
# 这些参数将被存储在特殊的变量中
$0 -- "script.sh"
$1 -- "param1"
$2 -- "param2"
$3 -- "param3"
$4 -- "param4"
$@ -- array of all positional parameters




# 逻辑操作符
# shell脚本支持逻辑与和逻辑或
逻辑与 &&
逻辑或 ||
Example
mkdir tempDir && cd tempDir && mkdir subTempDir
# 这个例子中，如果创建tempDir成功，执行后面的cd，继续创建subTempDir



# 函数
注意⚠️
# 函数包含了一些列你要重复调用的指令(函数必须先定义后调用)
# 把函数定义在程序开始或主程序之前是一个最佳实践
语法
function function_name() {
    command 1
    command 2
    command 3
      ...
      ...
    command N
}
# 调用函数 简单的给出函数名字
#!/bin/bash
function myFunc () {
    echo "Shell Scripting Is Fun!"
}
myFunc # call
# 函数参数传递
# 和脚本一样，也可以给函数传递参数完成特殊的任务，
# 第一个参数存储在变量$1中，第二个参数存储在变量$2中...，$@存储所有的参数，
# 参数之间使用空格分割 myFunc param1 param2 param3 ...



# 变量的作用范围
全局变量: 
    默认情况下，shell中的变量都定义为全局变量，
    你可以从脚本中的任何位置使用变量，但是变量在使用之前必须先定义
本地变量: 
    本地变量只能在方法内部访问，可以通过local关键词定义一个本地变量，
    定义一个本地变量的最佳实践是在函数内部


# 通配符
# 使用通配符可以完成特定的匹配
# 一些常用的通配符
* 可以通配一个或多个任意字符
*.txt
hello.*
great*.md

?匹配一个字符
?.md
Hello?

[]匹配括号内部的任意一个字符
He[loym], [AIEOU]

[!]不匹配括号内的任何字符
`[!aeiou]`
# 预先定义的通配符
[[:alpha:]]
[[:alnum:]]
[[:space:]]
[[:upper:]]
[[:lower:]]
[[:digit:]]

匹配通配符 有些情况下我们想匹配*或?等特殊字符，可以使用转义字符
\*
\?








