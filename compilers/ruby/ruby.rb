#!/usr/bin/ruby -w
# -*- coding: UTF-8 -*-
puts "Hello World!"
print("Hello World!\n")
# Ruby END   声明 code 会在程序的结尾被调用
# Ruby BEGIN 声明 code 会在程序的开头被调用


# https://www.w3cschool.cn/ruby/ruby-string.html




### ============================================================== ruby 基础语法
# Ruby 程序中的空白
print <<EOF
在 Ruby 代码中的空白字符，如空格和制表符一般会被忽略，
除非当它们出现在字符串中时才不会被忽略。然而，有时候它
们用于解释模棱两可的语句。当启用 -w 选项时，这种解释会产生警告。
EOF

# Ruby 程序中的行尾
print <<EOF
Ruby 把分号和换行符解释为语句的结尾。但是，如果 Ruby 在行尾遇到运算符，
比如 +、- 或反斜杠，它们表示一个语句的延续。
EOF

# Ruby 标识符
print <<EOF
标识符是变量、常量和方法的名称。Ruby 标识符是大小写敏感的。
这意味着 Ram 和 RAM 在 Ruby 中是两个不同的标识符。
Ruby 标识符的名称可以包含字母、数字和下划线字符（ _ ）。
EOF

# ruby 保留字
# 下表列出了 Ruby 中的保留字。
# 这些保留字不能作为常量或变量的名称。但是，它们可以作为方法名
print <<EOF
BEGIN	do	next	thenEND	else	nil	truealias	elsif	not	undef
and	end	or	unless begin	ensure	redo	untilbreak	false	rescue	when
case	for	retry	whileclass	if	return	whiledef	in	self	__FILE__
defined?	module	super	__LINE__
EOF


# Ruby 中的 Here Document
print <<EOF
"Here Document" 是指建立多行字符串。
在 << 之后，您可以指定一个字符串或标识符来终止字符串，
且当前行之后直到终止符为止的所有行是字符串的值。
如果终止符用引号括起，引号的类型决定了面向行的字符串类型。请注意<< 和终止符之间必须没有空格。
EOF




### ============================================================== ruby 数据类型


# 整型(Integer)
整型分两种，如果在31位以内（四字节），那为Fixnum实例。如果超过，即为Bignum实例。
整数范围从 -230 到 230-1 或 -262 到 262-1。在这个范围内的整数是类 Fixnum 的对象，
在这个范围外的整数存储在类 Bignum 的对象中。

您可以在整数前使用一个可选的前导符号，
一个可选的基础指标（0 对应 octal，0x 对应 hex，0b 对应 binary），
后跟一串数字。下划线字符在数字字符串中被忽略。

您可以获取一个 ASCII 字符或一个用问号标记的转义序列的整数值。




# 浮点型
Ruby 支持浮点数。它们是带有小数的数字。浮点数是类 Float 的对象，且可以是下列中任意一个。


# 算术操作
加减乘除操作符：+-*/；指数操作符为** 



### ================================================================ 字符串类型
Ruby 字符串简单地说是一个 8 位字节序列，它们是类 String 的对象。
双引号标记的字符串允许替换和使用反斜线符号，单引号标记的字符串不允许替换，
且只允许使用 \\ 和 \ 两个反斜线符号。



### ===================================================================== 数组
数组字面量通过[]中以逗号分隔定义，且支持range定义。
    （1）数组通过[]索引访问
    （2）通过赋值操作插入、删除、替换元素
    （3）通过+，－号进行合并和删除元素，且集合做为新集合出现
    （4）通过<<号向原数据追加元素
    （5）通过*号重复数组元素
    （6）通过｜和&符号做并集和交集操作（注意顺序）

#!/usr/bin/ruby -w
ary = [ "fred", 10, 3.14, "This is a string", "last element", ]
ary.each do |i|
    puts i
end



### ================================================================== 哈希类型
Ruby 哈希是在大括号内放置一系列键/值对，
键和值之间使用逗号和序列 => 分隔。尾部的逗号会被忽略。

#!/usr/bin/ruby
hsh = colors = { "red" => 0xf00, "green" => 0x0f0, "blue" => 0x00f }
hsh.each do |key, value|
    print key, " is ", value, "\n"
end




### ================================================================== 范围类型
一个范围表示一个区间。
范围是通过设置一个开始值和一个结束值来表示。范围可使用 s..e 和 s...e 来构造，或者通过 Range.new 来构造。
使用 .. 构造的范围从开始值运行到结束值（包含结束值）。使用 ... 构造的范围从开始值运行到结束值（不包含结束值）。
当作为一个迭代器使用时，范围会返回序列中的每个值。

范围(1..5)意味着它包含值 1, 2, 3, 4, 5   ||  范围(1...5)意味着它包含值 1, 2, 3, 4 

#!/usr/bin/ruby
(10..15).each do |n|
    print n, ' '
end




### ============================================================= Ruby 类和对象
Ruby 是一种完美的面向对象编程语言。面向对象编程语言的特性包括

# 数据封装
# 数据抽象
# 多态性
# 继承


一个面向对象的程序，涉及到的类和对象。类是个别对象创建的蓝图。
在面向对象的术语中，您的自行车是自行车类的一个实例。

以车辆为例，它包括车轮（wheels）、马力（horsepower）、燃油或燃气罐容量（fuel or gas tank capacity）。
这些属性形成了车辆（Vehicle）类的数据成员。借助这些属性您能把一个车辆从其他车辆中区分出来。

车辆也能包含特定的函数，比如暂停（halting）、驾驶（driving）、超速（speeding）。
这些函数形成了车辆（Vehicle）类的数据成员。因此，您可以定义类为属性和函数的组合。




### ==========================================================  在 Ruby 中定义类
为了使用 Ruby 实现面向对象编程，您需要先学习如何在 Ruby 中创建对象和类。
在 Ruby 中，类总是以关键字 class 开始，后跟类的名称。类名的首字母应该大写。类 Customer 如下所示：
class Customer
end
您可以使用关键字 end 终止一个类。类 中的所有数据成员都是介于类定义和 end 关键字之间。



### ============================================================= Ruby 类中的变量
Ruby 提供了四种类型的变量：
1 局部变量：局部变量是在方法中定义的变量。局部变量在方法外是不可用的。
在后续的章节中，您将看到有关方法的更多细节。局部变量以小写字母或 _ 开始。

2 实例变量：实例变量可以跨任何特定的实例或对象中的方法使用。这意味着，
实例变量可以从对象到对象的改变。实例变量在变量名之前放置符号（@）。

3 类变量：类变量可以跨不同的对象使用。类变量属于类，且是类的一个属性。类变量在变量名之前放置符号（@@）。

4 全局变量：类变量不能跨类使用。如果您想要有一个可以跨类使用的变量，您需要定义全局变量。
全局变量总是以美元符号（$）开始。



### =============================================== 在 Ruby 中使用 new 方法创建对象
class Customer
   @@no_of_customers=0
end


对象是类的实例。现在您将学习如何在 Ruby 中创建类的对象。在 Ruby 中，您可以使用类的方法 new 创建对象。
方法 new 是一种独特的方法，在 Ruby 库中预定义。new 方法属于类方法。
下面的实例创建了类 Customer 的两个对象 cust1 和 cust2：

cust1 = Customer.new
cust2 = Customer.new

在这里，cust1 和 cust2 是两个对象的名称。
对象名称后跟着等号（=），等号后跟着类名，然后是点运算符和关键字 new。 




### ==================================================== 自定义方法来创建 Ruby 对象
您可以给方法 new 传递参数，这些参数可用于初始化类变量。
当您想要声明带参数的 new 方法时，您需要在创建类的同时声明方法 initialize。
initialize 方法是一种特殊类型的方法，将在调用带参数的类的 new 方法时执行。

下面的实例创建了 initialize 方法：
class Customer
   @@no_of_customers=0
   def initialize(id, name, addr)
      @cust_id=id
      @cust_name=name
      @cust_addr=addr
   end
end

在本实例中，
您可以声明带有 id、name、addr 作为局部变量的 initialize方法。
在这里，def 和 end 用于定义 Ruby 方法 initialize。在后续的章节中，您将学习有关方法的更多细节。

在 initialize 方法中，把这些局部变量的值传给实例变量 @cust_id、@cust_name 和 @cust_addr。
在这里，局部变量的值是随着 new 方法进行传递的。
现在，您可以创建对象，如下所示：
cust1=Customer.new("1", "John", "Wisdom Apartments, Ludhiya")
cust2=Customer.new("2", "Poul", "New Empire road, Khandala")



#### ========================================================= Ruby 类中的成员函数
在 Ruby 中，函数被称为方法。类中的每个方法是以关键字 def 开始，后跟方法名。
方法名总是以小写字母开头。在 Ruby 中，您可以使用关键字 end 来结束一个方法。

下面的实例定义了一个 Ruby 方法：
class Sample
   def function
      statement 1
      statement 2
   end
end

在这里，statement 1 和 statement 2 是类 Sample 内的方法 function 的主体的组成部分。
这些语句可以是任何有效的 Ruby 语句。例如，我们可以使用方法 puts 来输出 Hello Ruby，如下所示：

class Sample
   def hello
      puts "Hello Ruby!"
   end
end

下面的实例将创建类 Sample 的一个对象，并调用 hello 方法：
#!/usr/bin/ruby

class Sample
   def hello
      puts "Hello Ruby!"
   end
end

### ======================================================== 使用上面的类来创建对象
object = Sample. new
object.hello

这将会产生下面的结果：
Hello Ruby!


