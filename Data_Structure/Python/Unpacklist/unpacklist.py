def listElemInVar():
    fname, lname, money = ['Sumeet','Tulsani',110000]
    print (lname)
    print(money)

def dropFirstLast(mylist):
    first,*middle,last = mylist
    avg = sum(middle)/len(middle)
    print (avg)

listElemInVar()
dropFirstLast([50,45,57,54,64,72])
