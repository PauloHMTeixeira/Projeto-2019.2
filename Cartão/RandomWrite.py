#!/usr/bin/env python
# -*- coding: utf8 -*-
from random import randint
import json
import os
import sys
import signal
import RPi.GPIO as GPIO
from mfrc522 import SimpleMFRC522

acessos_autorizados = [915676463990]

reader = SimpleMFRC522()

try:
	id, text = reader.read()
	print(id)
	teste = randint(1,10)
	ale = str(teste)
	text = "Cartao " + ale
	reader.write(text)
	print("Escrito: ")
	print(text)



finally:
	GPIO.cleanup()



