import cv2
import numpy as np
from matplotlib import pyplot as plt
path = "D:/Opencvfiles/Recour/yizhuo.png"
img = cv2.imread(path)
v1 = cv2.Canny(img,80,150)
v2 = cv2.Canny(img,80,250)
ans = np.hstack((v1,v2))
ans = cv2.resize(ans,(0,0),fx=0.5,fy=0.5)
img = cv2.resize(img,(0,0),fx=0.5,fy=0.5)
cv2.imshow('v',ans)
cv2.imshow('va',img)
#阈值偏小，则检测的细节更多



cv2.waitKey(0)
cv2.destroyAllWindows()