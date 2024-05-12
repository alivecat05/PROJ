import numpy as np
import cv2
from matplotlib import pyplot as plt
path = 'D:\Opencvfiles\Recour\graychart.png'
img  = cv2.imread(path,0)
dft = cv2.dft(np.float32(img),flags = cv2.DFT_COMPLEX_OUTPUT)
dft_shift = np.fft.fftshift(dft)
a = cv2.magnitude(dft_shift[:, :, 0], dft_shift[:, :, 1])
result = 20*np.log(a)
plt.subplot(121)
plt.imshow(img,cmap='gray')
plt.title('OG')
plt.axis('off')

plt.subplot(122)
plt.imshow(result,cmap='gray')
plt.title('result')
plt.axis('off')
#由图得越往图像中间的，频率越小，像素点变化快慢越小
plt.show(),print(a)