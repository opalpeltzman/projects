from django import forms
from django.contrib.auth.models import User
from django.contrib.auth.forms import UserCreationForm
from django.forms import ModelForm


class UserRegisterForm(UserCreationForm):
    email = forms.EmailField()
    userType = forms.CharField(max_length = 20)
    class Meta:
        model = User
        fields = [ 'username', 'email','userType', 'password1', 'password2']

        
