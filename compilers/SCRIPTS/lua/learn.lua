print("Hello World")

-- 计算字符串大小
name = "Jack"
io.write("Size of string ", #name, "\n")
io.write("Size of string ", name, "\n")


-- 打印多行字符串
longString = [[
    I am a very very ling
    string that goes on
]]
io.write(longString, "\n")


longString = longString .. name
io.write(longString, "\n")


isAbleToDrive = true
io.write(type(isAbleToDrive), "\n")

-- 如果变量值为空的话，返回nill
io.write(type(madeUpvar), "\n")


-- lua算术运算
io.write("5 + 3 = ", 5 + 3, "\n")
io.write("5 - 3 = ", 5 - 3, "\n")
io.write("5 * 3 = ", 5 * 3, "\n")
io.write("5 / 3 = ", 5 / 3, "\n")
io.write("5 % 3 = ", 5 % 3, "\n")

-- Math Functions: floor, ceil, max, min, sin, cos, tan,
-- asin, acos, exp, log, log10, pow, sqrt, random, randomseed
io.write("floor(2.345)        : ", math.floor(2.345), "\n")
io.write("ceil(2.345)         : ", math.ceil(2.345), "\n")
io.write("math.random()       : ", math.random(), "\n")
io.write("math.random(10)     : ", math.random(10), "\n")
io.write("math.random(5, 100) : ", math.random(5, 100), "\n")
math.randomseed(os.time())


-- 打印小数点后10位数
print(string.format("PI = %.10f", math.pi))
print(string.format("not true = %s", tostring(not true)))


-- Relational Operators : > < >= <= == ~= 
-- Logical Operators    : and or not
age = 13
if age < 16 then
    io.write("You can go to school", "\n")
    local localVar = 10
elseif (age <= 16) and (age < 18) then
    io.write("You can drive", "\n")
else
    io.write("You can vote", "\n")
end
print(localVar)


if (age < 14) or (age > 67) then
    io.write("You shoudn't work", "\n")
end



-- 三元组运算 canVote = age > 18 ? true : false
canVote = age > 18 and true or false
io.write("can i vote: ", tostring(canVote), "\n")


-- 字符串函数
quote = "I changed my password to incorrect. So that when i forget"
io.write("Quote Length ", string.len(quote), "\n")
io.write("Replace I with me: ", string.gsub(quote, "I", "me"), "\n")
io.write("Index of password : ", string.find(quote, "password"), "\n")
io.write("Quote Upper : ", string.upper(quote), "\n")
io.write("Quote Lower : ", string.lower(quote), "\n")


-- lua循环语法
i = 1
while (i <= 10) do
    io.write(i)
    i = i + 1
    if (i == 8) then break end
end

-- 直到在终端上输入15,程序才停止
--[[
repeat
    io.write("Enter your guess : ")
    guess = io.read()
until tonumber(guess) == 15
--]]

--- i = 起始位置， 终置位置， 步长 
for i = 1, 10, 2 do
    io.write(i)
end

months = {"January", "February", "March", "April", "June", "July", "August",
          "September",  "October", "Noveber", "December"}
for key, value in pairs(months) do
    io.write(value, "\n")
end




--- lua 一维数组
--  正如你所看到的，我们可以使用整数索引来访问数组元素，如果知道的索引没有值则返回nil。
--- 在 Lua 索引值是以 1 为起始，但你也可以指定 0 开始。
--- 除此外我们还可以以负数为数组索引值：
array = {"Lua", "Tutorial"}
for i= 0, 2 do
   print(array[i])
end


aTable = {}
for i = 1, 10 do
    aTable[i] = i
end
io.write("Table first : ", aTable[1], "\n")
io.write("Number of Items : ", #aTable, "\n")
print(table.concat(aTable, ","))
table.insert(aTable, 1, 0)
io.write("Number of Items : ", #aTable, "\n")
table.remove(aTable, 1)
print(table.concat(aTable, ", "))


--- lua多维数组
aMultiTable = {}
for i = 0, 9 do
    aMultiTable[i] = {}
    for j = 0, 9 do
        aMultiTable[i][j] = tostring(i) .. tostring(j)
    end
end
io.write("Table[0][0] : ", aMultiTable[0][0], "\n")
for i = 0, 9 do
    for j = 0, 9 do
        io.write(aMultiTable[i][j], " : ")
    end
    print()
end


-- lua函数
function getSum(num1, num2)
    return num1 + num2
end
print(string.format("5 + 2 = %d", getSum(5, 2)))


function splitStr(theString)
    stringTable = {}
    local i = 1
    for word in string.gmatch(theString, "[^%s]+") do
        stringTable[i] = word
        i = i +1
     end
     return stringTable, i
end
splitStrTable, numOfStr = splitStr("The Turtle")
for j = 1, numOfStr do
    print(string.format("%d : %s", j, splitStrTable[j]))
end


function getSumMore(...)
    local sum = 0
    for k, v in pairs{...} do
        sum = sum +v
    end
    return sum
end
io.write("Sum ", getSumMore(1,2,3), "\n")


doubleIt = function(x) return x * 2 end
print(doubleIt(4))


function outerFunc()
    local i = 0
    return function()
        i = i + 1
        return i
    end
end
getI = outerFunc()
print(getI())
print(getI())
print(getI())


co = coroutine.create(function()
    for i = 1, 10, 1 do
        print(i)
        print(coroutine.status(co))
        if (i == 5) then coroutine.yield() end
     end
end)
print(coroutine.status(co))
coroutine.resume(co)
print(coroutine.status(co))






