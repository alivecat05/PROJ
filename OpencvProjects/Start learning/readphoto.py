import cv2
import numpy as np
#import matplotlib.pyplot as plt

def imgshow(name,type):
    cv2.imshow('name'  , type)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    
   
path = 'D:\Opencvfiles\Recour\hoshi.jpg'
path1 = 'D:\Opencvfiles\Recour\svt.jpg'
#读图
img  = cv2.imread(path)
img1  = cv2.imread(path1)

k=img1.shape
m=img.shape
print(k)
print(m)

# cv2.imshow('b',img1)
# cv2.imshow('image',img1)
cv2.waitKey(0)
cv2.destroyAllWindows
#数值计算
# img2 = img+10
# k1=img[:5,0]
# k2=img2[:5,0]
# print("k1=",k1)
# print("k2=",k2)

#图像融合
img = cv2.resize(img,(0,0),fx=0.5,fy=0.5)
k=img1.shape
m=img.shape
print(k)
print(m)

cv2.imshow('a',img)
cv2.waitKey(0)
cv2.destroyAllWindows
