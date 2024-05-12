import numpy as np
import cv2
from matplotlib import pyplot as plt
path = 'D:\Opencvfiles\Recour\graychart.png'
img  = cv2.imread(path,0)
img_float32=np.float32(img)
#傅里叶变换
dft = cv2.dft(img_float32,flags=cv2.DFT_COMPLEX_OUTPUT)#输出复数阵列
dft_shift = np.fft.fftshift(dft)#将频谱图像 dft 中的零频率分量移到频谱中心
#获取图像长宽
rows,cols = img.shape
crow,cclo  =int(rows/2),int(cols/2)
#制作掩码图像
mask = np.zeros((rows,cols,2),np.uint8)#全部置0
#选取中间部分
mask[crow-30:crow+30,cclo-30:cclo+30] = 1#只有中间位置为低频部分置1，只要置1的低频部分

fshift = dft_shift*mask
f_shift = np.fft.ifftshift(fshift)
img_back = cv2.idft(f_shift)
img_back = cv2.magnitude(img_back[:,:,0],img_back[:,:,1])
print(mask)
print(f_shift)
print(dft_shift)
plt.subplot(121)
plt.imshow(img,cmap='gray')
plt.title("OG")
plt.axis('off')

plt.subplot(122)
plt.imshow(img_back,cmap='gray')
plt.title("trans")
plt.axis('off')

plt.show()
