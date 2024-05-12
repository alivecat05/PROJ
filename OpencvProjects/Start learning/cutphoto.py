#导包
import cv2
import numpy as up
#指定路径
path ='D:\Opencvfiles\Recour\mind.jpg'

img = cv2.imread(path)
mind = img[0:500,0:200]
cv2.imshow('ig',mind) 
cv2.waitKey()
cv2.destroyAllWindows()