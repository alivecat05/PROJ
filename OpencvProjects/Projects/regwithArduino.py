import cv2
import serial
import numpy as np
cap = cv2.VideoCapture(0)
ser = serial.Serial('COM3', 9600) 


def callback():
    if cap.isOpened:
        open,frame = cap.read()
        #hsv = cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    else:
        False
    while open:
        ret ,frame = cap.read()
        hsv = cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
        if frame is None:
            break
        if ret==True:

            lower_hsv = np.array([0,43,46])
            higher_hsv = np.array([10,255,255])

            lower_hsv1 = np.array([156,43,46])
            higher_hsv1 = np.array([180,255,255]) 
               
            mask1 = cv2.inRange(hsv,lower_hsv,higher_hsv)
            mask2 = cv2.inRange(hsv,lower_hsv1,higher_hsv1)
            
            ans = mask1+mask2
    return ans
def sendcommand(command):
    ser.write(command.encode())
    ser.flush()
    
if __name__=="main":
    k =  0
    if k == callback():
        sendcommand('R')
        # 释放摄像头资源
        cap.release()
        # 关闭串行端口
        ser.close()

        

    