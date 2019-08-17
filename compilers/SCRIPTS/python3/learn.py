import random
import sys
import os

'''
print("Hello World")
name = "Derek"
print(name)


### 算术运算
print("5 +  2 = ", 5 +  2)
print("5 -  2 = ", 5 -  2)
print("5 *  2 = ", 5 *  2)
print("5 /  2 = ", 5 /  2)
print("5 %  2 = ", 5 %  2)
print("5 ** 2 = ", 5 ** 2)
print("5 // 2 = ", 5 // 2)


### print格式输出
quote = "\"Always remember you are unique"
multi_line_quote = ''' just
like everyone else '''
print("%s %s %s" % ('I like the quite', quote, multi_line_quote))
print("\n" * 5)
print("I don't like ", end="")
print("newlines")


### python3 列表
grocery_list = ['Juice', 'Tomatoes', 'Potatoes', 'Bananas']
print('First Item:', grocery_list[0])
print(grocery_list[1:3])
other_events = ['Wash Car', 'Pick Up Kids', 'Cash Check']
to_do_list = [other_events, grocery_list]
print(to_do_list)
print((to_do_list[1][1]))



### python3 字典
super_villains = {  'Key00'   : 'value11',
                    'Fiddler' : 'Issac Bowin',
                    'Captin ' : 'Leonard Snart',
                    'Weather' : 'Mark Markdon',
                    'Mirror ' : 'Sam Scudder',
                    'Pide P ' : 'Thomas Peterson'
}
print(super_villains)
print(super_villains['Key00'])
print(super_villains['Pide P '])



### if else elif == != > >= < <=
age = 21
if age > 16 :
    print('You are old enough to drive')
else :
    print('You are not old enough to drive')
    
if age >= 21 :
    print('You are old enough to drive a tactor traile')
elif age >= 16 :
    print('You are old enough to drive a car')
else :
    print("You are not old enough to drive")
    
if ((age >= 1) and (age <= 18)) :
    print("You get a birthday")
elif ((age == 21) or (age >= 65)) :
    print("You get a birthday")
elif not(age == 30) :
    print("You don't get a birthday")
else :
    print("You get a birthday party yeah")
    
    
    
### for while
for x in range(0, 10) :
    print(x, ' ', end="")
print()
    
grocery_list = ['Juice', 'Tomatoes', 'Potstoes', 'bananas']
for y in grocery_list :
    print(y)
    
for x in [2,4,6,8,10] :
    print(x)    
    
num_list = [[1,2,3], [10,20,30], [100, 200, 300]] 
for x in range(0, 3) :
    for y in range(0, 3) :
        print(num_list[x][y])    
    
    
    
random_num = random.randrange(0, 100) 
while (random_num != 15) :
    print(random_num)
    random_num = random.randrange(0, 100)
    
i = 0
while (i <= 20) :
    if (i % 2 == 0) :
        print(i)
    elif (i == 9) :
        break
    else :
        i = i+1
        continue
    i += 1 
   
   
    
### python function
def addNumber(fNum, lNum) :
    sumNum = fNum + lNum
    return sumNum
print("sumNumber : ", addNumber(1, 2))
'''   






### python3 class
class Animal :
    __name   = ""
    __height = 0
    __weight = 0
    __sound  = 0  
    
    def __init__(self, name, height, weight, sound) :
        self.__name     = name
        self.__height   = height
        self.__weight   = weight
        self.__sound    = sound        
    
    def set_name(self, name) :
        self.__name = name
    
    def set_height(self, height) :
        self.__height = height
        
    def set_weight(self, weight) :
        self.__weight = weight
        
    def set_sound(self, sound) :
        self.__sound = sound
           
    def get_name(self) :
        return self.__name
    
    def get_height(self) :
        return str(self.__height)
    
    def get_weight(self) :
        return str(self.__weight)
    
    def get_sound(self) :
        return self.__sound
    
    def get_type(self) :
        print("Animal")
        
    def toString(self) :
        return "{} is {} cm tall and {} kilograms and say {}".format(self.__name,
                                                                     self.__height,
                                                                     self.__weight,
                                                                     self.__sound)   
cat = Animal('Whiskers', 33, 10, 'Meow')   
print(cat.toString())


class Dog(Animal) :
    __owner = ""
    
    def __init__(self, name, height, weight, sound, owner) :
        self.__owner = owner
        super(Dog, self).__init__(name, height, weight, sound)
        
    def set_owner(self, owner) :
        self.__owner = owner
        
    def get_owner(self) :
        return self.__owner
       
    def get_type(self) :
        print("Dog")
    
    def toString(self) :
        return "{} is {} cm tall and {} kilograms and say {} His owner is {}".format(self.__name,
                                                                                     self.__height,
                                                                                     self.__weight,
                                                                                     self.__sound,
                                                                                     self.__owner)
                                                                                     
    def multiple_sounds(self, how_many=None) :
        if how_many is None :
            print(self.get_sound())
        else :
            print(self.get_sound() * how_many)


spot = Dog("Spot", 53, 27, "Ruff", "Derek")
print(spot.toString())




