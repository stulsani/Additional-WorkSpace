from django.shortcuts import render
from django.views.decorators.csrf import csrf_exempt
from rest_framework.response import Response
from rest_framework.decorators import api_view
from geopy.geocoders import Nominatim
from geopy.distance import great_circle
from . models import Store,Personalcare
from . serializers import StoreSerializer


@csrf_exempt
@api_view(['GET'])
def store(request):
    store_details = Store.objects.all()
    serializers = StoreSerializer(store_details, many=True)
    # return render(request, 'index.html', {'store_details': store_details})
    return Response(serializers.data)

def location(request):
    return render(request, 'location.html', {})

def searchedlocation(request):
    if request.method == 'GET':
        geolocator = Nominatim()
        searchthis = request.GET.get('locationentered')
        location = geolocator.geocode(searchthis)
        userEnteredSearch = (location.latitude, location.longitude)
    else:
        userEnteredSearch = ( request.POST['lat'], request.POST['long'] )
    storeList = []
    storesFromDatabase = Store.objects.all()
    for object in storesFromDatabase:
        lat= object.latitude
        long = object.longitude
        fromDatabase = (lat, long)
        myDistance = great_circle(userEnteredSearch, fromDatabase).miles
        if myDistance < 10:
            storeObject = [object.name,object.address,object.id]
            storeList.append(storeObject)

    context = {
        'storeList': storeList
    }
    return render(request, 'storedetails.html', context)

def storecontains(request, store_id):
    nameOfStore = ''
    iterateOverStores = Store.objects.all()
    for ourStore in iterateOverStores:
        if str(ourStore.id) == str(store_id):
            nameOfStore = ourStore.name
            break
    return render(request, 'storecontains.html', {'nameOfStore' : nameOfStore})

def storeproducts(request, digit,storename):
    itemsList = []
    if str(digit) == str(1):
        itemsFromDatabase = Personalcare.objects(store_ref = storename)
        for itemCategory in itemsFromDatabase:
            if(itemCategory.product_type not in itemsList):
                itemsList.append(itemCategory.product_type)
    return render(request, 'storeproducts.html',{'itemsList' : itemsList, 'storename': storename, 'digit': digit })

def storeitems(request, storeitem, storename, digit):
    itemsList = []
    if str(digit) == str(1):
        itemsFromDatabase = Personalcare.objects(store_ref = storename, product_type=storeitem)
        for product in itemsFromDatabase:
            itemsObject = [product.product_name, product.price]
            itemsList.append(itemsObject)
    return render(request, 'storeitems.html',{'itemsList':itemsList, 'storename':storename})

