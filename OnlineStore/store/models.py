from django.db import models
from mongoengine import *
from mongoengine import Document, EmbeddedDocument, fields

class Store(Document):
    name = StringField(max_length=200)
    address = StringField(max_length=500)
    latitude = FloatField(max_digits=15, decimal_places=10)
    longitude = FloatField(max_digits=15, decimal_places=10)

class Personalcare(Document):
    store_ref = StringField(max_length=200,required=True)
    category = StringField(max_length=50,required=True)
    product_type = StringField(max_length=50, required=True)
    product_name = StringField(max_length=50,required=True)
    price = DecimalField(required=True)
    quantity = IntField(required=True)