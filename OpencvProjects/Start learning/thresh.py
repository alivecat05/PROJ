import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt
path = "D:\Opencvfiles\Recour\svt.jpg"
img1 = cv.imread(path,cv.IMREAD_UNCHANGED)
img = cv.imread(path,0)
ret,thresh1 = cv.threshold(img,127,255,cv.THRESH_BINARY)#二值法
ret,thresh2 = cv.threshold(img,127,255,cv.THRESH_BINARY_INV)#二值法的反转
ret,thresh3 = cv.threshold(img,127,255,cv.THRESH_TRUNC)#大于阈值不变，否则为不变
ret,thresh4 = cv.threshold(img,127,255,cv.THRESH_TOZERO)#大于阈值，否则为0
ret,thresh5 = cv.threshold(img,127,255,cv.THRESH_TOZERO_INV)#TOZERO反转
titles = ['Original Image','BINARY','BINARY_INV','TRUNC','TOZERO','TOZERO_INV']
images = [img1, thresh1, thresh2, thresh3, thresh4, thresh5]
for i in range(6):
     plt.subplot(2,3,i+1),plt.imshow(images[i],'gray')
     plt.title(titles[i])
     plt.xticks([]),plt.yticks([])
plt.show()
