### 面向对象技术简介
> https://www.runoob.com/perl/perl-intro.html
> https://www.runoob.com/python3/python3-inputoutput.html
> https://www.runoob.com/ruby/ruby-class.html
+ 类, 用来描述具有相同的属性和方法的对象的集合。它定义了该集合中每个对象所共有的属性和方法。对象是类的实例。
+ 方法, 类中定义的函数。
+ 类变量, 类变量在整个实例化的对象中是公用的, 定义在类中且在函数体之外。类变量通常不作为实例变量使用。
+ 数据成员, 类变量或者实例变量用于处理类及其实例对象的相关的数据。
+ 方法重写, 如果从父类继承的方法不能满足子类的需求，可以对其进行改写，这个过程叫方法的覆盖（override），也称为方法的重写。
+ 局部变量, 定义在方法中的变量，只作用于当前实例的类。
+ 实例变量, 在类的声明中，属性是用变量来表示的。这种变量就称为实例变量，是在类声明的内部但是在类的其他成员方法之外声明的。
+ 继承, 即一个派生类（derived class）继承基类（base class）的字段和方法。
+ 继承也允许把一个派生类的对象作为一个基类对象对待。
+ 实例化：创建一个类的实例，类的具体对象。
+ 对象：通过类定义的数据结构实例。对象包括两个数据成员（类变量和实例变量）和方法。



### __init__()

+ 类有一个名为 __init__() 的特殊方法（构造方法），该方法在类实例化时会自动调用
+ 类定义了 __init__() 方法，类的实例化操作会自动调用 __init__() 方法
+ 当然， __init__() 方法可以有参数，参数通过 __init__() 传递到类的实例化操作上
```python
#!/usr/bin/python3
 
class Complex:
    def __init__(self, realpart, imagpart):
        self.r = realpart
        self.i = imagpart
x = Complex(3.0, -4.5)
print(x.r, x.i)   # 输出结果：3.0 -4.5
```

### self代表类的实例，而非类
类的方法与普通的函数只有一个特别的区别——它们必须有一个额外的第一个参数名称, 
按照惯例它的名称是 self。
```python
class Test:
    def prt(self):
        print(self)
        print(self.__class__)
 
t = Test()
t.prt()

以上实例执行结果为：

<__main__.Test instance at 0x100771878>
__main__.Test
```
+ 从执行结果可以很明显的看出，
+ self 代表的是类的实例，代表当前对象的地址，而 self.class 则指向类。
+ self 不是 python 关键字，我们把他换成 runoob 也是可以正常执行的:
```python
class Test:
    def prt(runoob):
        print(runoob)
        print(runoob.__class__)
 
t = Test()
t.prt()

以上实例执行结果为：

<__main__.Test instance at 0x100771878>
__main__.Test
```


# 类的方法

+ 在类的内部，使用 def 关键字来定义一个方法，与一般函数定义不同，
+ 类方法必须包含参数 self, 且为第一个参数，self 代表的是类的实例。

```python
#!/usr/bin/python3
class people:
    #定义基本属性
    name = ''
    age = 0
    #定义私有属性,私有属性在类外部无法直接进行访问
    __weight = 0
    #定义构造方法
    def __init__(self,n,a,w):
        self.name = n
        self.age = a
        self.__weight = w
    def speak(self):
        print("%s 说: 我 %d 岁。" %(self.name,self.age))
 
# 实例化类
p = people('runoob',10,30)
p.speak()

执行以上程序输出结果为：

runoob 说: 我 10 岁。
```

#单继承示例
```python
#!/usr/bin/python3
 
#类定义
class people:
    #定义基本属性
    name = ''
    age = 0
    #定义私有属性,私有属性在类外部无法直接进行访问
    __weight = 0
    #定义构造方法
    def __init__(self,n,a,w):
        self.name = n
        self.age = a
        self.__weight = w
    def speak(self):
        print("%s 说: 我 %d 岁。" %(self.name,self.age))
 
#单继承示例
class student(people):
    grade = ''
    def __init__(self,n,a,w,g):
        #调用父类的构函
        people.__init__(self,n,a,w)
        self.grade = g
    #覆写父类的方法
    def speak(self):
        print("%s 说: 我 %d 岁了，我在读 %d 年级"%(self.name,self.age,self.grade))
 
 
 
s = student('ken',10,60,3)
s.speak()

执行以上程序输出结果为：

ken 说: 我 10 岁了，我在读 3 年级
```

### 多重继承
```python
#!/usr/bin/python3
 
#类定义
class people:
    #定义基本属性
    name = ''
    age = 0
    #定义私有属性,私有属性在类外部无法直接进行访问
    __weight = 0
    #定义构造方法
    def __init__(self,n,a,w):
        self.name = n
        self.age = a
        self.__weight = w
    def speak(self):
        print("%s 说: 我 %d 岁。" %(self.name,self.age))
 
#单继承示例
class student(people):
    grade = ''
    def __init__(self,n,a,w,g):
        #调用父类的构函
        people.__init__(self,n,a,w)
        self.grade = g
    #覆写父类的方法
    def speak(self):
        print("%s 说: 我 %d 岁了，我在读 %d 年级"%(self.name,self.age,self.grade))
 
#另一个类，多重继承之前的准备
class speaker():
    topic = ''
    name = ''
    def __init__(self,n,t):
        self.name = n
        self.topic = t
    def speak(self):
        print("我叫 %s，我是一个演说家，我演讲的主题是 %s"%(self.name,self.topic))
 
#多重继承
class sample(speaker,student):
    a =''
    def __init__(self,n,a,w,g,t):
        student.__init__(self,n,a,w,g)
        speaker.__init__(self,n,t)
 
test = sample("Tim",25,80,4,"Python")
test.speak()   #方法名同，默认调用的是在括号中排前地父类的方法

执行以上程序输出结果为：

我叫 Tim，我是一个演说家，我演讲的主题是 Python
```


### 方法重写
```python
如果你的父类方法的功能不能满足你的需求，你可以在子类重写你父类的方法，实例如下：

#!/usr/bin/python3
 
class Parent:        # 定义父类
   def myMethod(self):
      print ('调用父类方法')
 
class Child(Parent): # 定义子类
   def myMethod(self):
      print ('调用子类方法')
 
c = Child()          # 子类实例
c.myMethod()         # 子类调用重写方法
super(Child,c).myMethod() #用子类对象调用父类已被覆盖的方法

super() 函数是用于调用父类(超类)的一个方法。

执行以上程序输出结果为：

调用子类方法
调用父类方法
```





### 类的私有方法

+ __private_method：两个下划线开头，声明该方法为私有方法，
+ 只能在类的内部调用 ，不能在类的外部调用。self.__private_methods。

```python
#!/usr/bin/python3
 
class JustCounter:
    __secretCount = 0  # 私有变量
    publicCount = 0    # 公开变量
 
    def count(self):
        self.__secretCount += 1
        self.publicCount += 1
        print (self.__secretCount)
 
counter = JustCounter()
counter.count()
counter.count()
print (counter.publicCount)
print (counter.__secretCount)  # 报错，实例不能访问私有变量

执行以上程序输出结果为：

1
2
2
Traceback (most recent call last):
  File "test.py", line 16, in <module>
    print (counter.__secretCount)  # 报错，实例不能访问私有变量
AttributeError: 'JustCounter' object has no attribute '__secretCount'

```
类的私有方法实例如下：
```python
#!/usr/bin/python3
 
class Site:
    def __init__(self, name, url):
        self.name = name       # public
        self.__url = url   # private
 
    def who(self):
        print('name  : ', self.name)
        print('url : ', self.__url)
 
    def __foo(self):          # 私有方法
        print('这是私有方法')
 
    def foo(self):            # 公共方法
        print('这是公共方法')
        self.__foo()
 
x = Site('菜鸟教程', 'www.runoob.com')
x.who()        # 正常输出
x.foo()        # 正常输出
x.__foo()      # 报错
```


### 类的专有方法：

+ __init__    : 构造函数，在生成对象时调用
+ __del__     : 析构函数，释放对象时使用
+ __repr__    : 打印，转换
+ __setitem__ : 按照索引赋值
+ __getitem__ : 按照索引获取值
+ __len__     : 获得长度
+ __cmp__     : 比较运算
+ __call__    : 函数调用
+ __add__     : 加运算
+ __sub__     : 减运算
+ __mul__     : 乘运算
+ __truediv__ : 除运算
+ __mod__     : 求余运算
+ __pow__     : 乘方


### 运算符重载

Python同样支持运算符重载，我们可以对类的专有方法进行重载，实例如下：
```python
#!/usr/bin/python3
 
class Vector:
   def __init__(self, a, b):
      self.a = a
      self.b = b
 
   def __str__(self):
      return 'Vector (%d, %d)' % (self.a, self.b)
   
   def __add__(self,other):
      return Vector(self.a + other.a, self.b + other.b)
 
v1 = Vector(2,10)
v2 = Vector(5,-2)
print (v1 + v2)

以上代码执行结果如下所示:

Vector(7,8)
```



### Python 子类继承父类构造函数说明

+ 如果在子类中需要父类的构造方法就需要显式地调用父类的构造方法，或者不重写父类的构造方法。
+ 子类不重写 __init__，实例化子类时，会自动调用父类定义的 __init__。
```python
class Father(object):
    def __init__(self, name):
        self.name=name
        print ( "name: %s" %( self.name) )
    def getName(self):
        return 'Father ' + self.name
 
class Son(Father):
    def getName(self):
        return 'Son '+self.name
 
if __name__=='__main__':
    son=Son('runoob')
    print ( son.getName() )

输出结果为：

name: runoob
Son runoob
```


如果重写了__init__ 时，实例化子类，就不会调用父类已经定义的 __init__，语法格式如下：
```pythopn
class Father(object):
    def __init__(self, name):
        self.name=name
        print ( "name: %s" %( self.name) )
    def getName(self):
        return 'Father ' + self.name
 
class Son(Father):
    def __init__(self, name):
        print ( "hi" )
        self.name =  name
    def getName(self):
        return 'Son '+self.name
 
if __name__=='__main__':
    son=Son('runoob')
    print ( son.getName() )

输出结果为：

hi
Son runoob
```


+ 如果重写了__init__ 时，要继承父类的构造方法，可以使用 super 关键字：
`super(子类，self).__init__(参数1，参数2，....)`


+ 还有一种经典写法：
+ 父类名称.__init__(self,参数1，参数2，...)

```python
class Father(object):
    def __init__(self, name):
        self.name=name
        print ( "name: %s" %( self.name))
    def getName(self):
        return 'Father ' + self.name
 
class Son(Father):
    def __init__(self, name):
        super(Son, self).__init__(name)
        print ("hi")
        self.name =  name
    def getName(self):
        return 'Son '+self.name
 
if __name__=='__main__':
    son=Son('runoob')
    print ( son.getName() )

输出结果为：

name: runoob
hi
Son runoob
```






