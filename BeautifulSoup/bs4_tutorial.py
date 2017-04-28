import bs4 as bs
import urllib.request

sauce = urllib.request.urlopen('https://pivotal.io/').read()
soup = bs.BeautifulSoup(sauce,'lxml')

print (soup.find_all('p'))
for paragraph in soup.find_all('p'):
    print(paragraph.text)

for url in soup.find_all('b'):
    print(url.get('body'))

nav = soup.nav

for url in nav.find_all('a'):
    print(url.get('href'))

for div in soup.find_all('div'):
    print(div.text)
