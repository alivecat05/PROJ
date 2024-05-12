import numpy as np
import cv2
from matplotlib import pyplot as plt
path = 'D:\Opencvfiles\Recour\graychart.png'
img  = cv2.imread(path,0)
f = np.fft.fft2(img)
fshift = np.fft.fftshift(f)
#实现滤波器
rows,cols = img.shape
crow,ccol  =int(rows/2),int(cols/2)
fshift[crow - 30: crow+30,ccol - 30:ccol+30] = 0#高通滤波0

ishift = np.fft.fftshift(fshift)
iimg = np.fft.ifft2(ishift)
iimg = abs(iimg)

plt.subplot(121)
plt.imshow(img,cmap='gray')
plt.title("OG")
plt.axis('off')

plt.subplot(122)
plt.imshow(iimg,cmap='gray')
plt.title("trans")
plt.axis('off')

plt.show()
