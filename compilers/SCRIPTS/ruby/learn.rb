=begin
print "Enter a Value : "
first_num = gets.to_i
print "Enter Another Value : "
second_num = gets.to_i
puts first_num.to_s + " + " + second_num.to_s + " = " + (first_num + second_num).to_s
puts "Add Them #{4 + 5} \n\n"
puts 'Add Them #{4 + 5} \n\n'



# Arithmetic Operators
puts "6 + 4 = " + (6+4).to_s
puts "6 - 4 = " + (6-4).to_s
puts "6 * 4 = " + (6*4).to_s
puts "6 / 4 = " + (6/4).to_s
puts "6 % 4 = " + (6%4).to_s
num_one = 1.000
num_two = 0.999
puts num_one.to_s + " - " + num_two.to_s + " = " + (num_one - num_two).to_s
big_float = 1.12345678901234
puts (big_float + 0.00000000000005).to_s


write_handler = File.new("yourSum.out", "w")
write_handler.puts("Randm Text").to_s
write_handler.close
data_from_file = File.read("yourSum.out")
puts "Data From File : " + data_from_file

# load "ruby_test2.rb"



# Comarison:    == != < > <= >=
# Logical:      && || ! and or not
age = 12
if (age >= 5) && (age <=6)
    puts "You're in Kindergarten"
elsif (age >= 7) && (age <= 13)
    puts "You're in Middle School"
    puts "Yeah"
else
    puts "Stay Home"
end
puts "5 <=> 10 = " + (5 <=> 10).to_s

unless age > 4
    puts "No School"
else
    puts "Go to School"
end

puts "You're Yong" if age < 30



# case
print "Enter Greeting : "
greeting = gets.chomp
case greeting
when "French", "french"
    puts "Bojour"
    exit
when "Spanish", "spanish"
    puts "Hola"
    exit
else "English"
    puts "Hello"
end



# loop while until for each
x = 1
loop do 
    x += 1
    next unless (x % 2) == 0
    puts x
    break if x >= 10
end

y = 1
while y <= 10
    y += 1
    next unless (y % 2) == 0
    puts y
end  

a = 1
until a >= 10
    a += 1
    next unless (a % 2) == 0
    puts a
end


numbers = [1,2,3,4,5]
for number in numbers
    puts "#{number}? "
end


groceries = ["FVWM", "FreeBSD", "Gentoo", "Debian", "CORTEX_M"]
groceries.each do |linux_system|
    puts "Get Some #{linux_system}"
end

(0..5).each do |i|
    puts "# #{i}"
end



# funciton
def add_nums(num_1, num_2)
    return num_1.to_i + num_2.to_i
end
puts add_nums(1, 2)


# 检查除数是否为0
print "Enter a Number : "
first_num = gets.to_i
print "Enter Another : "
second_num = gets.to_i
begin
    answer = first_num / second_num
rescue
    puts "You can't divide by zero"
    exit
end
puts "#{first_num} / #{second_num} = #{answer}"


# 检查check_age(age)中的age参数是否合法
age = 12
def check_age(age)
    raise ArgumentError, "Enter Positive Number" unless age > 0
end
begin
    check_age(-1)
rescue ArgumentError
    puts "That is an impossible age"
end
=end

multiline_string = <<-EOF
This is very long string
that contains interpolation
like #{4 + 5}
EOF
print multiline_string


first_name = "Derek"
last_name = "Banas"
full_name = first_name + last_name
middle_name = "Justin"
full_name = "#{first_name} #{middle_name} #{last_name}"
puts full_name.include?("Justin")
puts full_name.size
puts "Vowels : " + full_name.count("aeiou").to_s
puts "consonants : " + full_name.count("^aeiou").to_s
puts "Index : " + full_name.index("Banas").to_s
puts full_name.upcase
puts full_name.downcase
puts full_name.swapcase

full_name = "  " + full_name
full_name = full_name.lstrip
full_name = full_name.rstrip
full_name = full_name.strip

puts full_name.rjust(20, '.')
puts full_name.ljust(20, '.')
puts full_name.center(20, '.')










