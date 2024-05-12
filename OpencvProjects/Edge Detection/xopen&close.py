import cv2
import numpy as np
from matplotlib import pyplot as plt
path = "D:/Opencvfiles/Recour/10.jpg"
img = cv2.imread(path)
kernel = np.ones((3,4),np.uint8)
open = cv2.morphologyEx(img,cv2.MORPH_GRADIENT,kernel)#梯度运算，获取轮廓
res = np.hstack((img,open))
cv2.imshow('res',res)


cv2.waitKey(0)
cv2.destroyAllWindows()