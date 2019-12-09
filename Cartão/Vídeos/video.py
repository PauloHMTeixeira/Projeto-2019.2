#!/usr/bin/env python
import os
import RPi.GPIO as GPIO
from mfrc522 import SimpleMFRC522
x1 = 915676463990
x2 = 451497212058
x3 = 707945167965
reader = SimpleMFRC522()
try:
	print("Bote o cartao")
	id,text = reader.read()
	if id  == x1:
		os.system("omxplayer -o local --vol -3000 videoplayback.mp4")
	if id == x2:
		os.system("mpg321 Clarice_conv.mp3")
	if id == x3:
		os.system("mpg321 leopoldo_eng_conv.mp3")
finally:
	GPIO.cleanup()



