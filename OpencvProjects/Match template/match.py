import cv2
import numpy as np
from matplotlib import pyplot as plt
#模板匹配可用于对象检测
path1 = 'D:\Opencvfiles\Recour\lena.png'
path2 = 'D:\Opencvfiles\Recour\sublena.png'
#导入原图与模板
img1 = cv2.imread(path1,0)
img2 = cv2.imread(path2,0)
#计算模板的宽和高
h,w  = img2.shape[:2]
method = ['cv2.TM_SQDIFF','cv2.TM_SQDIFF_NORMED','cv2.TM_CCORR',
          'cv2.TM_CCORR_NORMED','cv2.TM_CCOEFF','cv2.TM_CCOEFF_NORMED ']
#得出匹配结果
# method的值为cv2.TM_SQDIFF和cv2.TM_SQDIFF_NORMED时，result值为0表示匹配度最好，值越大，表示匹配度越差。
# method 的值为 cv2.TM_CCORR、cv2.TM_CCORR_NORMED、cv2.TM_CCOEFF 和cv2.TM_CCOEFF_NORMED时，
# result的值越小表示匹配度越差，值越大表示匹配度越好。

res = cv2.matchTemplate(img1,img2,cv2.TM_SQDIFF)
#查找最值(极值)与最值所在的位置，要寻找模板的最值作为最佳匹配结果
min_val,max_val,min_loc,max_loc = cv2.minMaxLoc(res)
#计算左右顶角坐标
top_left = min_loc
bottom_right = (top_left[0] +w,+top_left[1]+h)

new_img = img1.copy()
#绘制矩形
cv2.rectangle(new_img,top_left,bottom_right,255,2)
# 输出
image = [img2,res,new_img]
titles = ['template','matching_result','result']
for i in range(3):
    plt.subplot(2,3,i+1)
    plt.imshow(image[i], cmap='gray')
    plt.title(titles[i])
    plt.xticks([]),plt.yticks([])
plt.show()



