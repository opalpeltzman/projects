from django import forms
from django.contrib.auth.models import User
from django.contrib.auth.forms import UserCreationForm
from django.forms import ModelForm
from .models import LOOK, closet

class LOOKform(ModelForm):
    class Meta:
        model = LOOK
        fields = [ 'Userid', 'Description', 'lookImg']


class closetform(ModelForm):
    class Meta:
        model = closet
        fields = [ 'Userid', 'Itemtype', 'size', 'color', 'itemImg']

