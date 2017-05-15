from rest_framework import serializers
from . models import Store

class StoreSerializer(serializers.Serializer):
    name = serializers.StringRelatedField()
    address = serializers.StringRelatedField()

    def restore_object(self, attrs, instance=None):
        if instance:
            instance.name = attrs.get('name', instance.name)
            instance.address = attrs.get('address', instance.address)
            return instance

        return Store(attrs.get('name'), attrs.get('address'))