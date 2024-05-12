import cv2
import numpy as np
from matplotlib import pyplot as plt
#对直方图进行均衡化处理
#目的：使图像像素值的灰度均匀分布，就具有高对比度和多变的灰度色调
path = 'D:\Opencvfiles\Recour\graychart.png'
img  = cv2.imread(path,0)
color = ('b','g','r')
hist =  cv2.calcHist([img],[0],None,[256],[0,256])


#直方图1输出后发现中间的灰度值过高
equ = cv2.equalizeHist(img)
plt.hist(equ.ravel(),256)
plt.hist(img.ravel(),256)
#经过对比，发现均衡化后的直方图灰度值分布更加广
# plt.show()
res = np.hstack((img,equ))
# cv2.imshow('equ',res)
#但是一般均衡化后，图像可能损失一些细节
#进行自适应均衡化
clahe = cv2.createCLAHE(clipLimit=2.0,tileGridSize=(8,8))
ans = clahe.apply(img)
rel = np.hstack((img,equ,ans))
cv2.imshow('rel',rel)
#对比得知自适应均衡化之后，图像的灰度值均衡化的同时，细节更加明显
cv2.waitKey()
cv2.destroyAllWindows()



