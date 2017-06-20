def binarySearch(alist,item):
    if len(alist) == 0:
        return False
    else:
        mid = len(alist)//2
        if alist[mid] == item:
            return True
        else:
            if alist[mid] < item:
                return binarySearch(alist[mid+1:],item)
            else:
                return binarySearch(alist[:mid],item)

testList = [2,4,6,8,10,12,14,16,18,20]
print("So item is present?",binarySearch(testList,16))
print("So item is present?",binarySearch(testList,1))
