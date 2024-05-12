import cv2
import numpy as np
from matplotlib import pyplot as plt
path = "D:/Opencvfiles/Recour/mao.png"
rb=cv2.imread(path)
cv2.imshow('rb',rb)
kernel = np.ones((5,5),np.uint8)#创建数组
erosion =cv2.erode(rb,kernel,iterations=1)#腐蚀

dialate = cv2.dilate(erosion,kernel,iterations=1)#膨胀


cv2.imshow('ero',erosion)
cv2.imshow('dia',dialate)
cv2.imwrite("D:/Opencvfiles/Recour/mao1.png",erosion)
cv2.waitKey(0)
cv2.destroyAllWindows()