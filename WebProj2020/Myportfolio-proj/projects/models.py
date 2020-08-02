from django.db import models

class Project(models.Model):
    fullName    = models.CharField(max_length=70)
    mail        = models.CharField(max_length=70 , default='DEFAULT VALUE')
    message     = models.TextField(max_length=200 , default='DEFAULT VALUE')
