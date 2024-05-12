import cv2
import numpy as np
from matplotlib import pyplot as plt
path = "D:/Opencvfiles/Recour/yizhuo.png"
import cv2

img = cv2.imread(path)

down = cv2.pyrDown(img)
up = cv2.pyrUp(down)
diff = up - img
print('img.shape=', img.shape)
print('down.shape=', up.shape)
cv2.imshow('img', img)
cv2.imshow('up', up)
cv2.imshow('diff', diff)
cv2.waitKey()
cv2.destroyAllWindows()

# 输出结果
img.shape= (512, 512, 3)
down.shape= (512, 512, 3)

