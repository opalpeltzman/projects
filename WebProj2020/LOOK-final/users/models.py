from django.db import models
from django import forms
from django.db.models import Model
from django.contrib.auth.models import User

class users(models.Model):
    PROFILE =(
                ('user','user'),
            )
    Username = models.CharField(max_length = 70, null=True )
    Email = models.EmailField(max_length = 254, null=True )
    Password = models.CharField(max_length = 50, null=True )
    profile = models.CharField(max_length=200,null=True, choices=PROFILE)

    def __str__(self):
    		return self.id

class stylists(models.Model):
    PROFILE =(
                ('stylist','stylist'),
            )

    Username = models.CharField(max_length = 70, null=True )
    Email = models.EmailField(max_length = 254, null=True )
    Password = models.CharField(max_length = 50, null=True )
    profile = models.CharField(max_length=200,null=True, choices=PROFILE)

    def __str__(self):
    		return self.id






