from django.shortcuts import render, redirect, get_object_or_404
from django.contrib.auth.decorators import login_required
from django.contrib import messages
from .forms import LOOKform, closetform
from .models import LOOK
from django.http import JsonResponse
from LOOK.allow import allowed_users

# Create your views here.

@login_required(login_url='login')
def homepage(request):
    return render(request,'outfits/browseLook.html')

@login_required(login_url='login')
def profile(request):
    return render(request,'outfits/index.html')    


@login_required(login_url='login')
def stylist(request):
    return render(request,'outfits/findstylist.html')    
    
@login_required(login_url='login')    
def camera(request):
    return render(request,'outfits/camera.html')   


@login_required(login_url='login')
@allowed_users(allowed_roles=['stylist'])
def buildlook(request):
    return render(request,'outfits/stylistCreate.html')     


@login_required(login_url='login')
def profileAfterchanges(request):
    return render(request,'outfits/index.html') 

def createplusLook(request):
    return render(request,'outfits/createLook.html') 


@login_required(login_url='login')
def updatelook(request):
    if request.method == 'GET':
        form = LOOKform()
        return render(request, 'outfits/createLook.html', {'form':form})
    else:
        try:
            form = LOOKform(request.POST , instance=look)
            form.save()
            return redirect(request, 'profile')
        except ValueError:
            return render(request, 'outfits/createLook.html', { 'form': LOOKform(), 'errMsg':'data mistake'})



@login_required(login_url='login')
def profile(request):
    looks = LOOK.objects.filter(Userid=request.user)
    return render(request, 'outfits/index.html', {'mylooks':looks})


@login_required(login_url='login')
def image_upload_view(request):
    """Process images uploaded by users"""
    if request.method == 'POST':
        form = closetform(request.POST, request.FILES)
        if form.is_valid():
            form.save()
            img_obj = form.instance
            return render(request, 'outfits/upload.html', {'form': form, 'img_obj': img_obj})
    else:
        form = closetform()
    return render(request, 'outfits/upload.html', {'form': form})


@login_required(login_url='login')
def stylistceartLook(request):
    return render(request, 'outfits/createLook.html')


def send_json(request):
    looks = [
        {
            "userid":"13",
            "lookid":"1",
            "img": "../images/o1"
            
        },
        {
            "userid":"13",
            "lookid":"1",
            "img": "../images/o2"
        },
        {
            "userid":"13",
            "lookid":"2",
            "img": "../images/o3"
        },
        {
            "userid":"13",
            "lookid":"3",
            "img": "../images/o4"
        },
        {
            "userid":"dana123",
            "lookid":"1",
            "img": "../images/o5"
        },
        {
            "userid":"dana123",
            "lookid":"1",
            "img": "../images/o6"
        }
    ]


    return JsonResponse({'looks' : looks})

