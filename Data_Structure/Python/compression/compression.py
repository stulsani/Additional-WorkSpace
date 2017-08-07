from collections import defaultdict

def compressed(para):
    mydict = defaultdict(list)
    i = 0
    for word in para.split(" "):
        mydict[word].append(i)
        i += len(word) + 1
    return mydict

def decompress(mydict,parasize):
    ans = [' '] * parasize
    for key in mydict:
        for value in mydict[key]:
            count = value
            for w in key:
                ans[count] = w
                count += 1
    strans = ''.join(str(e) for e in ans)
    return strans

para = "This is a good time to do this thing which is a good thing to do"
mydict = compressed(para)
print("Orignal Para: ", decompress(mydict,len(para)))
