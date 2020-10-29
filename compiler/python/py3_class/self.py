#!/usr/bin/python3

### __str__()方法是为了程序调式使用

###########################################################
### self 理解
###########################################################
class Dog:
	def __init__(self, new_color):
		self.color = new_color

	def bark(self):
		print("---wang_wang---")

	def print_color(self):
		print("color value: ", self.color)
		
	def __str__(self):
		return "current object color:"+self.color



def test(AAA):
	AAA.print_color()


wangcai = Dog("blue")
# wangcai.print_color()

xiaoqiang = Dog("black")
# xiaoqiang.print_color()

test(wangcai)
print(wangcai)
print(id(wangcai))
