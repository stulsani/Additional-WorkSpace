import requests
from bs4 import BeautifulSoup
import operator

def start(url):
    word_list = []
    source_code = requests.get(url).text
    soup = BeautifulSoup(source_code)
    for ourtext in soup.findAll('a', {'class' : 'hello_world' }):
        content = ourtext.string
        words = content.lower().split()
        for each word in words:
            word_list.append(word)
        cleanUpList(word_list)

def cleanUpList(word_list):
    cleanedwordlist = []
    symbols = "!@#$%^&*()_+-:;'\""
    for word in word_list:
        for i in range(0, len(symbols)):
            word = word.replace(symbols[i],"")
        if len(word) > 0:
            cleanedwordlist.append(word)
    createDictionary(cleanedwordlist)

def createDictionary(cleanedwordlist):
    word_count = {}
    for word in cleanedwordlist:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
    for key,value in sorted(word_count.items(),key=operator.itemgetter(1)):
        print(key,value)

start('')
