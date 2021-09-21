testList=[100,(200,300),('Ram','Shyam')]
k=0
for i in testList:
    k=k+1
    if type(i)==tuple:
        print("Element ",k," is a tuple")
        for j in i:
            print('-',j)
    else:
        print("Element ",k," is not a tuple")