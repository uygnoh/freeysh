#!/usr/bin/python3
### ==============

### 定义类:	 class Class_name:
### 类名规则: 建议首字符大写


"""
 __init__()方法是python自动调用的方法，
 __init__()调用时间为：创建完对象后立马调用。
 不需要开发者调用，python解释器自动调用。
 这个方法一般情况下完成一些初始化的事情，比如添加一些属性。

class Xabc:
    def __init__(self, new_a, new_b):
        self.a = new_a
        self.b = nw_b

注意：new_a, new_b都是局部变量，并不是对象属性
    如果需要在__init__()的方法中添加属性的话，
    在使用类似 self.属性名 = 值)的格式。
    此时 self.a = new_a, 表示给对象添加了一个属性，
    这个属性名为：a
    这个属性的值为局部变量new_a里面的值。

"""


### =======================================================

### 定义一个狗类
class Dog:
	# 属性



	
	# 方法(相当于原来定义的函数)
	# 它里面规定一定有self关键字，并且在第1个位置
	# __init__()这个是PYTHON中的一个特殊方法，当创建完一个对象后立马自动调用。
	def __init__(self, color, size, high):
		print("hello, world")
		self.c = color
		self.s = size
		self.h = high
		
	def runs(self):
		print("runing...")

	def printinfo(self):
		print(self.color)
	



### 创建一个狗对象
xobj = Dog("red", 123, 89)

### 访问这个狗对象中的方法
xobj.runs()

### 添加属性(注意: 如果没有添加属性，
### 那么访问这个属性就会产生一个异常!)
### 添加属性的方法: 对象名.新的属性名 = 值
### 获取这个对象属性，有2种方法
### 1,对象.属性
### 2,定义一个方法，在这个方法中，使用“self.属性”
xobj.color = 123

print(xobj.color)

xobj.printinfo()

print(xobj.c)

print("############################################# demo_1 file of end")

	
	

	
class Player():
    def __init__(self, name):
        self.name = name
        
    def sayHelo(self):
        print("helo", self.name.title())
        
    def intro(self):
        print("I am player.")

curry = Player("curry")
print(curry.name)
curry.sayHelo()
curry.intro()
	



