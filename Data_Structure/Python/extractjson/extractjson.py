import urllib.request, json

with urllib.request.urlopen("https://onlinegrocerystore.herokuapp.com/store/") as url:
    data = json.loads(url.read().decode())
    print(data)

    mylatitude = data[0]['latitude']
    mylongitude = data[0]['longitude']
    print("-----------------------")
    print(mylatitude)
    print("-----------------------")
    print(mylongitude)

    for d in data:
        if d['name'] == 'San Ramon Cafe 3':
            myaddress = d['address']
            print("-------------------")
            print(myaddress)

