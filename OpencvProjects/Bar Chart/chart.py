import cv2
import numpy as np
from matplotlib import pyplot as plt
path = 'D:\Opencvfiles\Recour\yizhuo.png'
img  = cv2.imread(path)
color = ('b','g','r')
# hist =  cv2.calcHist([img],[0],None,[256],[0,256])
# plt.hist(img.ravel(),256)
# plt.show()
for i,col in enumerate(color):
    hist1 = cv2.calcHist([img],[i],None,[256],[0,256])
    plt.plot(hist1,color=col)
    plt.xlim([0,256])
plt.show()
