#导包
import cv2
import numpy as up
#指定路径
path ='D:\Opencvfiles\Recour\mind.png'
int = cv2.imread(path)
b,g,r = cv2.split(int)
int = cv2.merge((b,g,r))

ext_int  = int.copy()
#ext_int[:,:,0]=0
ext_int[:,:,2]=2
ext_int[:,:,1]=1
cv2.imshow('B',ext_int)
cv2.waitKey(100000)
cv2.destroyAllWindows()
