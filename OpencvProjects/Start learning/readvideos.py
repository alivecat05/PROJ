import cv2
#import matplotlib.pyplot as plt
import numpy as up
path ='D:\Opencvfiles\Recour\DJing.mp4' 
vc = cv2.VideoCapture(path)

if vc.isOpened():
    open, frame = vc.read()
else:
    open = False

while open:
    ret, frame = vc.read()
    if frame is None:
        break
    if ret == True:
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        cv2.imshow('ans',gray)
        if cv2.waitKey(10) & 0xFF ==27:
            break
vc.release()
cv2.destroyAllWindows()