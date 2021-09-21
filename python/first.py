# print("hello world")

# print("bang" * 3 )

# sumer = 47

# print(sumer*4)
# sumer = "sumer"
# print(sumer)

# name = int(input("what is your age : "))


# name = name/2

# print(name)
# name = "sumer"
# last = name

# last = last + name 
# print(name)


# first = "Sumer"

# last = "Kumar"

# msg = f"{first} {last} is a faad coder "

# print(f"{first} {last} is a faad coder ")

# print(msg.upper())

# print(msg.find("umar"))
# print("umar" in msg)

# print(msg.title())
# import math

# print(13//5)

# var = 3

# var+=3
# print(var)


# print("blah ",var," blah ",var)
# print(math.ceil(3.3333))

# fog = False
# if fog:
#     print("bang " * 3)
# print("beta")

# if not fog :
#     print("wah bete wah \n" * 5)

# if(not fog):
#     print('checking')
# sumer=""
# for item in "Sumer":
#     sumer+=item+" "

# print(sumer)

# sumer = ""
# array = range(10,30,2)
# for item in array:
#     sumer+= f"{item} "
# print(sumer)

# array=["sumer",'kumar',"is",'the',"best"]
# array.append(object)
# print(array)
# array = range(1,99)
# print(max(array))

# arr = [range(1,5),
#        range(6,10),
#        range(11,15),
#        range(16,20),
#        range(21,15)]

# print(arr)
# data = ""
# for row in arr:
#     for col in row : 
#         data+=f"{col} "
#     data+="\n"
# print(data)
# arr[0].clear()
# print(arr)
# R = int(input("Enter the number of rows:"))
# C = int(input("Enter the number of columns:"))
  
# # Initialize matrix
# matrix = []
# print("Enter the entries rowwise:")
  
# # For user input
# for i in range(R):          # A for loop for row entries
#     a =[]
#     for j in range(C):      # A for loop for column entries
#          a.append(int(input()))
#     matrix.append(a)
  
# # For printing the matrix
# for i in range(R):
#     for j in range(C):
#         print(matrix[i][j], end = " ")
#     print()

#unpacking 
#size of array and size of variables must be same 
#otherwise it will through error
# a = [1,2,3]
# x,y,z=a
# print(x,y,z)

#dictnories
# person = {
#     "name" : "sumer",
#     "age" : 21,
#     "gender":'m',
#     "color":"brown"
# }

# print(person)

# print(person.get("Name"))
# if person.get("Name") == None:
    # print("not present")
    
# if "Name" in person:
#     print("pata name")

# print(type(person.get("age")))

#string splitting
# sent = "my name is sumer"
# words = sent.split(' ')

# print(f"wah bete wah {words[-1]}")


# funtions
# def func(name):
#     print("Hi",name)
# func("sumer")


#exception
# try:
#     num = int(input("enter something >>> "))
# except ValueError:
#         print(ValueError.__base__)

#classed
# class Name :
#     def __init__(self,name):
#         self.first = name
#         # self.last  = name.reverse()
#     def getFirst(self):
#         return self.first

# print("hola"+Name("sumer").getFirst())

# concatenation of lists :: so easy 
# a = ["sumer"]
# b = ["kumar"]
# print(a)


#class again

# val = 5
# val+=1
# print(val)

#sets
# a = [1,1,1,1,1,1,2]
# a = set(a)
# print(a)

# name = "sumer kumar,raj"

# name = name.split(' ')
# print(name)
#----------------------------------------------------------------------->method
def method(a):
    a="2"
    print(a)


a = "int(7)"

method(a)

print(a)