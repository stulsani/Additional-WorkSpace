import urllib.request
import json
import pprint
import codecs

reader = codecs.getreader("utf-8")

user_input = input("Enter location to get your lattitude and longitude: ")
modified_input = user_input.replace(' ', '+')

params = {
             'address' : modified_input,
             'sensor' : 'false',
        }
URL2 = "http://maps.googleapis.com/maps/api/geocode/json?" + urllib.parse.urlencode(params)

googleResponse = urllib.request.urlopen(URL2)
jsonResponse = json.loads(googleResponse.read().decode('utf8'))
pprint.pprint(jsonResponse)

test = json.dumps([s['geometry']['location'] for s in jsonResponse['results']], indent=3)

print(test)