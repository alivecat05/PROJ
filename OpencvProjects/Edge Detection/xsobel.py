import cv2
import numpy as np
from matplotlib import pyplot as plt
path = "D:/Opencvfiles/Recour/hoshi.jpg"
img=cv2.imread(path,cv2.IMREAD_GRAYSCALE)
##sobel算子
#x方向
sobelx = cv2.Sobel(img,cv2.CV_64F,1,0,ksize=1)#使用sobel因子
sobelx = cv2.convertScaleAbs(sobelx)#取绝对值使同方向的图像完整
#y方向
sobely = cv2.Sobel(img,cv2.CV_64F,0,1,ksize=1)
sobely = cv2.convertScaleAbs(sobely)
add = cv2.addWeighted(sobelx,0.5,sobely,0.5,0)
# ans = np.hstack((img,conver,add))
# sobelxy = cv2.Sobel(img,cv2.CV_64F,1,1,ksize=3)<<--不建议直接计算

#scharr算子#由结果可知scharr算子更为敏感,更适合精细化检测
scharrx = cv2.Scharr(img,cv2.CV_64F,1,0)
scharrx = cv2.convertScaleAbs(scharrx)#取绝对值使同方向的图像完整
scharry = cv2.Scharr(img,cv2.CV_64F,0,1)
scharry = cv2.convertScaleAbs(scharry)#取绝对值使同方向的图像完整
sum= cv2.addWeighted(scharrx,0.5,scharry,0.5,0)
abc = np.hstack((add,sum))
res = cv2.resize(abc,(0,0),fx=0.5,fy=0.5)

cv2.imshow('s',add)
cv2.waitKey(0)
cv2.destroyAllWindows()