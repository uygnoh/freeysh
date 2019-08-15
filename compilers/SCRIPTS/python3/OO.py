


# 封装
class Mian:
    # 整个对象共有属性
    attr1 = '汤' #类属性中的变量 
    attr2 = '面' #类属性中的变量

one_mian = Mian()
two_mian = Mian()
print(one_mian.attr1)
print(one_mian.attr2)
print(one_mian)


# two_mian.attr3为私有属性
two_mian.attr3 = '香菜'
print(two_mian.attr3)


# 类属性中的变量，在实例中共享
Mian.attr1 = '开水'
print(one_mian.attr1)
print(two_mian.attr1)


class Mian:
    flag = '李老师面店' #类的变量属性 
    attr1 = '开水'
    def __init__(self): #为实例时行数据的初始化， 此函数为解释器自动调用执行
        self.attr1 = '汤' # 实例的变量属性，默认指向了当前的实例对象
        self.attr2 = '面' # 实例会图覆盖掉全局这个同名的
        # self维护了这个变量和生产出来的实例之间的关系
                
one = Mian()
# 隐含了init函数的调用，为自己分配了两个私有的变量 attr1, attr2
two = Mian()
print(one.flag)
print(one.attr1)
print(one.attr2)
Mian.attr1 = "abc"




class Human:
    notice = ''
    def __init__(self, name):
        self.w = '上'
        self.s = '下'
        self.a = '左'
        self.d = '右'
        self.name = name
    


Human.notice = 'close ------'

h1 = Human('小红')
h2 = Human('小明')
h3 = Human('小白')





