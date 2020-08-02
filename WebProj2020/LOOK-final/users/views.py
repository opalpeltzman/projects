from django.shortcuts import render, redirect, get_object_or_404
from django.contrib import messages
from .forms import UserRegisterForm
from django.contrib.auth import authenticate, login, logout
from LOOK.allow import allowed_users


# Create your views here.

def mylogin(request):
    if request.method == 'POST':
        form = UserRegisterForm(request.POST)
        username = request.POST.get('username')
        password = request.POST.get('password1')
        user = authenticate(request, username=username, password=password)
        if user is not None:
            login(request, user)
            return redirect('home')
        else:
            messages.info(request, 'username or password were incorrect')
    else:
        form = UserRegisterForm()

    return render(request, 'users/login.html',{'form': form} )


def mylogout(request):
    logout(request)
    return redirect('login')

def register(request):
    if request.method == 'POST':    
        form = UserRegisterForm(request.POST)
        if form.is_valid():
            form.save()
            username = form.cleaned_data.get('username')
            messages.success(request, f'account created for {username}')
            return redirect('login')
    else:
        form = UserRegisterForm()
    return render(request, 'users/register.html' ,{'form': form})


