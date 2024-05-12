import cv2
import numpy as np
from matplotlib import pyplot as plt
#多模板匹配
#模板匹配可用于对象检测
path1 = 'D:\Opencvfiles\Recour\gud.jpg'
path2 = 'D:\Opencvfiles\Recour\gudtemp.jpg'
#导入原图与模板
img1 = cv2.imread(path1,cv2.COLOR_BGR2BGRA)
img2 = cv2.imread(path2,cv2.COLOR_BGR2BGRA)
#计算模板的宽和高
h,w  = img2.shape[:2]
method = ['cv2.TM_SQDIFF','cv2.TM_SQDIFF_NORMED','cv2.TM_CCORR',
          'cv2.TM_CCORR_NORMED','cv2.TM_CCOEFF','cv2.TM_CCOEFF_NORMED ']
res = cv2.matchTemplate(img1,img2,cv2.TM_CCORR_NORMED)#resul矩阵
#设定阈值来筛选结果
threshold = 0.8
new_img = img1.copy()
#函数 np.where()可以找出在函数 cv2.matchTemplate()的返回值中，哪些位置上的值是大于阈值threshold的。
loc  =np.where(res>=threshold)
#获取res矩阵的对角顶点位置坐标
#zip()将loc的位置值打包为元组
#top_left可由loc中的值得到
for pt in zip(*loc[::-1]):#loc[::-1]为行列互换
    bottom_right = (pt[0]+w,pt[1]+h)
    cv2.rectangle(new_img,pt,bottom_right,255,1)
#输出
image = [img2,res,new_img]
titles = ['template','matching_result','result']
for i in range(3):
    plt.subplot(2,3,i+1)
    plt.imshow(image[i], cmap='gray')
    plt.title(titles[i])
    plt.xticks([]),plt.yticks([])
plt.show()





