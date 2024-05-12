import numpy as np
import cv2
from matplotlib import pyplot as plt
path = 'D:\Opencvfiles\Recour\graychart.png'
img  = cv2.imread(path,0)
img_float32=np.float32(img)
dft = cv2.dft(img_float32,flags=cv2.DFT_COMPLEX_OUTPUT)
dft_shift = np.fft.fftshift(dft)

rows,cols = img.shape
crow,cclo  =int(rows/2),int(cols/2)
#高通通
mask = np.ones((rows,cols,2),np.uint8)#返回给定形状和数据类型的数组，将其内元素置1
mask[crow-30:crow+30,cclo-30:cclo+30] = 0   #只有中间位置低频部分置0，不要这部分

fshift = dft_shift*mask
f_shift = np.fft.ifftshift(fshift)
img_back = cv2.idft(f_shift)
img_back = cv2.magnitude(img_back[:,:,0],img_back[:,:,1])

# print(mask)
# print(f_shift)
# print(dft_shift)



plt.subplot(121)
plt.imshow(img,cmap='gray')
plt.title("OG")
plt.axis('off')

plt.subplot(122)
plt.imshow(img_back,cmap='gray')
plt.title("trans")
plt.axis('off')

plt.show()
