import cv2
import numpy as np
path = "D:/Opencvfiles/Recour/10.jpg"
img = cv2.imread(path)
#向下采样
G0 = img
G1 = cv2.pyrDown(G0)
G2 = cv2.pyrDown(G1)
G3 = cv2.pyrDown(G2)
#拉普拉斯金字塔
L0 = G0 - cv2.pyrUp(G1)
L1 = G1 - cv2.pyrUp(G2)
L2 = G2 - cv2.pyrUp(G3)
#由拉普拉斯金字塔获得的缺失值加上向上采样值，从而提高分辨率
rst_G0 = L0 + cv2.pyrUp(G1)
rst_G1 = L1 + cv2.pyrUp(G2)
rst_G2 = L2 + cv2.pyrUp(G3)

print('rst_G0', np.sum(abs(G0 - rst_G0)))
print('rst_G1', np.sum(abs(G1 - rst_G1)))
print('rst_G2', np.sum(abs(G2 - rst_G2)))

cv2.imshow('G0', G0)
cv2.imshow('G1', G1)
cv2.imshow('G2', G2)

cv2.imshow('rst_G0', rst_G0)
cv2.imshow('rst_G1', rst_G1)
cv2.imshow('rst_G2', rst_G2)

cv2.waitKey()
cv2.destroyAllWindows()

