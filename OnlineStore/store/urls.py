from django.conf.urls import url
from . import views

urlpatterns = [
    url(r'^store/$', views.store, name='store'),
    url(r'^location/$', views.location, name='location'),
    url(r'^searchedlocation/$', views.searchedlocation, name='searchedlocation'),
    url(r'^searchedlocation/(.*)/$', views.storecontains, name='storecontains'),
    url(r'^(?P<digit>\d+)/(?P<storename>.+?)/$', views.storeproducts, name='storeproducts'),
    url(r'^(?P<digit>\d+)/(?P<storename>.+?)/(?P<storeitem>.+?)/$', views.storeitems, name='storeitems'),
    url(r'^(?P<storeitem>.+?)/(?P<storename>.+?)/(?P<digit>\d+)/$', views.storeitems, name='storeitems'),
]