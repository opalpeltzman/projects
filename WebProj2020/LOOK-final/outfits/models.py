from django.db import models
from django.contrib.auth.models import User
from django.contrib.auth.models import User

class LOOK(models.Model):
    Userid = models.ForeignKey(User, default = -1, on_delete = models.SET_DEFAULT)
    Description = models.CharField(max_length = 300)
    lookImg = models.ImageField(upload_to="outfits/images", default="outfits/images" )

    def __str__(self):
    		return self.name


class closet(models.Model):
    Userid = models.OneToOneField(User, on_delete = models.SET_NULL , null=True)
    Itemtype = models.CharField(max_length = 50, null=True)
    size = models.CharField(max_length = 20, null=True)
    color = models.CharField(max_length = 20, null=True)
    itemImg = models.ImageField(upload_to='images')

    def __str__(self):
    		return self.name
    
    

class allLOOKS():
    LOOKid = models.ForeignKey(LOOK, default = -1, on_delete = models.SET_DEFAULT)
    Itemid = models.ForeignKey(closet, default = -1, on_delete = models.SET_DEFAULT)

    def __str__(self):
    		return self.name
    



