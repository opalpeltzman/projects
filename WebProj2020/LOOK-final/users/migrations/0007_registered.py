# Generated by Django 3.0.4 on 2020-07-20 00:48

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
        ('users', '0006_delete_registered'),
    ]

    operations = [
        migrations.CreateModel(
            name='registered',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('Username', models.CharField(max_length=70, null=True)),
                ('Email', models.EmailField(max_length=254, null=True)),
                ('Password', models.CharField(max_length=50, null=True)),
                ('userType', models.CharField(choices=[('stylist', 'stylist'), ('standart', 'standart')], max_length=200, null=True)),
            ],
        ),
    ]
