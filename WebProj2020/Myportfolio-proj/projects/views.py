from django.shortcuts import render
from .models import Project

def homepage(request):
    projects = Project.objects.all()
    return render(request, 'projects/index.html',{'projects':projects})

def Myprojects(request):
    projects = Project.objects.all()
    return render(request, 'projects/article.html',{'projects':projects})

def sendMessage(request):
    fullName    = request.GET['fullName']
    mail        = request.GET['mail']
    message        = request.GET['message']
    msg = Project(fullName=fullName,mail=mail,message=message)
    msg.save()
    return render(request, 'projects/sendMessage.html')