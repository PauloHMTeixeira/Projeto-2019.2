#!/usr/bin/env python
import sys
import os
sys.path.append('/usr/local/lib/python2.7/site-packages')
import cv2
import numpy as np
import RPi.GPIO as GPIO
from mfrc522 import SimpleMFRC522
from moviepy.editor import *

reader = SimpleMFRC522()
x1 = 915676463990
from moviepy.editor import * # imports everything, quick and dirty
import moviepy.editor as mpy # Clean. Then use mpy.VideoClip, etc.
from moviepy.editor import VideoFileClip # just import what you need
from moviepy.video.io.VideoFileClip import VideoFileClip
from moviepy.video.fx.resize import resize
clip = VideoFileClip("videoplayback.mp4")
try:
	id, text = reader.read()
	if id  == x1:
		clip.show()
finally:
	GPIO.cleanup()



