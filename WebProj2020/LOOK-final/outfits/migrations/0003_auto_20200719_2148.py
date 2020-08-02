# Generated by Django 3.0.4 on 2020-07-19 18:48

from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
        ('outfits', '0002_auto_20200719_1633'),
    ]

    operations = [
        migrations.AlterField(
            model_name='closet',
            name='Userid',
            field=models.ForeignKey(default=-1, on_delete=django.db.models.deletion.SET_DEFAULT, to=settings.AUTH_USER_MODEL),
        ),
        migrations.AlterField(
            model_name='look',
            name='Userid',
            field=models.ForeignKey(default=-1, on_delete=django.db.models.deletion.SET_DEFAULT, to=settings.AUTH_USER_MODEL),
        ),
    ]
