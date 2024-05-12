import cv2
import numpy as np
from matplotlib import pyplot as plt
path = 'D:\Opencvfiles\Recour\yizhuo.png'
lena = cv2.imread(path)
#lena = cv2.cvtColor(lena1,cv2.COLOR_BGR2RGB)
# 均值滤波
blur = cv2.blur(lena,(3,3))
# cv2.imshow('lena',lena)
# cv2.imshow('blur',blur)

#方框滤波
box = cv2.boxFilter(lena,-1,(3,3),normalize=True)
# cv2.imshow('lena',lena)
# cv2.imshow('box',box)

#高斯滤波
gus = cv2.GaussianBlur(lena,(5,5),1)
# cv2.imshow('lena',lena)
# cv2.imshow('gus',gus)

#中值滤波
med = cv2.medianBlur(lena,5)
# cv2.imshow('lena',lena)
# cv2.imshow('med',med)
#
cv2.imwrite('D:\Opencvfiles\Recour\yizhuo1.jpg',med)
titles = ['OG','blur','box','gus','med']
images = [lena,blur,box,gus,med]
for i in range(5):
    plt.subplot(2,3,i+1),plt.imshow(images[i])
    plt.title(titles[i])
    plt.xticks([]),plt.yticks([])
plt.show()
    
cv2.waitKey(0)
cv2.destroyAllWindows()