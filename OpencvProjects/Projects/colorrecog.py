import cv2
import numpy as np
path = 'D:\Opencvfiles\Recour\hoshi.jpg'
bgr_img = cv2.imread(path)
hsv_img = cv2.cvtColor(bgr_img,cv2.COLOR_BGR2HSV)

def green_mask():
    lower_hsv = np.array([35,43,46])
    higher_hsv = np.array([77,255,255])
    
    mask = cv2.inRange(hsv_img,lower_hsv,higher_hsv)
    
    return mask

def orange_mask():
    lower_hsv = np.array([11,43,46])
    higher_hsv = np.array([25,255,255])

    # lower_hsv1 = np.array([156,43,46])
    # higher_hsv1 = np.array([180,255,255])    
    mask1 = cv2.inRange(hsv_img,lower_hsv,higher_hsv)
    # mask2 = cv2.inRange(hsv_img,lower_hsv1,higher_hsv1)
    rel = mask1
    return rel

def red_mask():
    lower_hsv = np.array([0,43,46])
    higher_hsv = np.array([10,255,255])

    lower_hsv1 = np.array([156,43,46])
    higher_hsv1 = np.array([180,255,255])    
    mask1 = cv2.inRange(hsv_img,lower_hsv,higher_hsv)
    mask2 = cv2.inRange(hsv_img,lower_hsv1,higher_hsv1)
    rel = mask1+mask2
    return rel
def blue_mask():
    lower_hsv = np.array([100,43,46])
    higher_hsv = np.array([124,255,255])  
    mask1 = cv2.inRange(hsv_img,lower_hsv,higher_hsv)

    rel = mask1    
    return rel
ans = blue_mask()
cv2.imshow('ans',ans)
k = cv2.waitKey(0)
if k ==27:
    cv2.destroyAllWindows()