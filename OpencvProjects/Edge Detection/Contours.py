import cv2
import numpy as np
#计算轮廓面积
# cnt = contours[0]
# area = cv2.contourArea(cnt)
# #最新opencv的findcontours函数只返回图像轮廓列表，图像轮廓层次


path = "D:/Opencvfiles/Recour/car.jpg"
img = cv2.imread(path)
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
ret,thresh = cv2.threshold(gray,127,255,cv2.THRESH_BINARY)
contours,hierarchy= cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_NONE)
cnt = contours[0]#轮廓信息，数据类型为数组
cnt1= contours[1]
#一般轮廓检测
draw_img = img.copy()
anss = cv2.drawContours(draw_img,contours,-1,(0,0,255),2)
#轮廓近似 
draw_img = img.copy()
epsilon= 0.0005*cv2.arcLength(cnt,True)#精细系数*函数-->系数越小越精细#True->保留两点线段阈值
approximate = cv2.approxPolyDP(cnt,epsilon,True)

ans = cv2.drawContours(draw_img,[approximate],-1,(0,0,255),2)#绘制轮廓
#外接矩形
x,y,w,h = cv2.boundingRect(cnt)
result = cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
x,y,w,h = cv2.boundingRect(cnt1)
result1 = cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)#外接矩形函数
rel = result+result1
#外接圆
(x,y),radius  =cv2.minEnclosingCircle(cnt)
central = [int(x),int(y)]
radius = int(radius)
answ = cv2.circle(img,central,radius,(0,255,0),2)
cv2.imshow('b',anss)
cv2.waitKey()
cv2.destroyAllWindows()
