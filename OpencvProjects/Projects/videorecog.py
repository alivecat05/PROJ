#导包
import cv2
import numpy as np
#指定路径
path ='D:\Opencvfiles\Recour\DJing.mp4' 
vc = cv2.VideoCapture(path)

if vc.isOpened():
    open, frame = vc.read()#frame为帧数
    hsv = cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
else:
    open = False

while open:
    ret, frame = vc.read()
    
    if frame is None:#帧为空
        break        
    if ret == True:
        #处理视频

        lower_hsv = np.array([0,43,46])
        higher_hsv = np.array([10,255,255])

        lower_hsv1 = np.array([156,43,46])
        higher_hsv1 = np.array([180,255,255]) 
               
        mask1 = cv2.inRange(hsv,lower_hsv,higher_hsv)
        mask2 = cv2.inRange(hsv,lower_hsv1,higher_hsv1)
            
        mask = mask1+mask2
        #result = cv2.bitwise_and(frame, frame, mask=mask)
        cv2.imshow('frame',frame)
        cv2.imshow('Mask',mask)
        if cv2.waitKey(10) & 0xFF ==27:#每处理完一帧后等待的时间(ms)
            break
vc.release()
cv2.destroyAllWindows()