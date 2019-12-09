#!/usr/bin/env python
import sys

sys.path.append('/usr/local/lib/python2.7/site-packages')
import cv2
import numpy as np
import RPi.GPIO as GPIO
from mfrc522 import SimpleMFRC522
file_name = "videoplayback.mp4"
window_name = "window"
interframe_wait_ms = 30
reader = SimpleMFRC522()
x1 = 915676463990

try:
	id, text = reader.read()
	if id  == x1:
		cap = cv2.VideoCapture('videoplayback.mp4')
		cv2.namedWindow(window_name, cv2.WND_PROP_FULLSCREEN)
		cv2.setWindowProperty(window_name, cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN) 

		if (cap.isOpened()== False): 
  			print("Error opening video stream or file")
 

		while(cap.isOpened()):
  			ret, frame = cap.read()
  			if ret == True:
    				cv2.imshow(window_name,frame)
 
    				if cv2.waitKey(25) & 0xFF == ord('q'):
      					break
 
  # Break the loop
	  		else: 
    				break
 
# When everything done, release the video capture object
		cap.release()
 
# Closes all the frames
		cv2.destroyAllWindows()
finally:
	GPIO.cleanup()


