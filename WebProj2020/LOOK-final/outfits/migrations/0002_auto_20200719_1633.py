# Generated by Django 3.0.4 on 2020-07-19 13:33

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('outfits', '0001_initial'),
    ]

    operations = [
        migrations.RenameField(
            model_name='look',
            old_name='Descriprion',
            new_name='Description',
        ),
        migrations.AddField(
            model_name='closet',
            name='itemImg',
            field=models.ImageField(default=-1, upload_to='outfits/images'),
            preserve_default=False,
        ),
        migrations.AddField(
            model_name='look',
            name='lookImg',
            field=models.ImageField(default='outfits/images', upload_to='outfits/images'),
        ),
    ]
