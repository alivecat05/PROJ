import cv2
#import matplotlib.pyplot as plt
import numpy as np
# path ="D:\Opencvfiles\Recour\hbc.mp4"
vc = cv2.VideoCapture(0)
vc.set(cv2.CAP_PROP_FRAME_WIDTH, 1260)
vc.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
if vc.isOpened():
    open, frame = vc.read()
else:
    open = False

while open:
    ret, frame = vc.read()
    if frame is None:
        break
    if ret == True:
        # gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        gray= cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
        rete,thresh = cv2.threshold(gray,127,255,cv2.THRESH_BINARY)
        contours,hierarchy= cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_NONE)
        #一般轮廓检测
        draw_img = frame.copy()
        ans = cv2.drawContours(draw_img,contours,-1,(0,0,255),5)
        cv2.imshow('ans',ans)
        if cv2.waitKey(10) & 0xFF ==27:
            break
vc.release()
cv2.destroyAllWindows()