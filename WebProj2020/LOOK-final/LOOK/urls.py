"""LOOK URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/3.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.conf.urls.static import static
from django.contrib.auth import views as auth_views
from django.urls import path
from users import views as users_views
from outfits import views as outfits_views
from django.conf import settings
from django.conf.urls.static import static




urlpatterns = [
    path('admin/', admin.site.urls),
    path('', users_views.mylogin, name = 'login' ),
    path('logout/', users_views.mylogout, name = 'logout' ),
    path('register/', users_views.register, name = 'register' ),
    path('home/', outfits_views.homepage, name='home'),
    path('profile/', outfits_views.profile, name='profile'),
    path('createLook/', outfits_views.updatelook, name='createLook'),
    path('stylist/', outfits_views.stylist, name='stylist'),
    path('camera/', outfits_views.camera, name='camera'),
    path('buildLook/', outfits_views.buildlook, name='buildLook'),
    path('sendjson/', outfits_views.send_json, name='send_json'),
    path('upload/', outfits_views.image_upload_view, name='upload'),
    path('profile/profile', outfits_views.profileAfterchanges, name='profileAfterchanges'),
    path('profile/createLook', outfits_views.createplusLook, name='createplusLook'),
    path('buildLook/stylistceartLook', outfits_views.stylistceartLook, name='stylistceartLook'),
    path('buildLook/profile', outfits_views.profile, name='profile'),
    path('buildLook/createLook', outfits_views.createplusLook, name='createplusLook'),
    
]

if settings.DEBUG:
    urlpatterns += static(settings.MEDIA_URL,
                          document_root=settings.MEDIA_ROOT)
