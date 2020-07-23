import cv2
import numpy as np

img = cv2.imread("text.jpg")
gray_img = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
hsv_img = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)

cv2.imshow("Original",img)
cv2.imshow("Grayscale",gray_img)
cv2.imshow("HSV",hsv_img)

print("Image shape before Resizing",img.shape)
print("Image size befre Resizing",img.size)

img=cv2.resize(img,(300,300))

cv2.imshow("resized",img)
cv2.waitKey(0)


ret,thresh=cv2.threshold(gray_img,150,255,cv2.THRESH_BINARY)
ret,thresh1=cv2.threshold(gray_img,150,255,cv2.THRESH_BINARY_INV)
ret,thresh2=cv2.threshold(gray_img,150,255,cv2.THRESH_OTSU)
adaptive=cv2.adaptiveThreshold(gray_img,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,3,4)

cv2.imshow('Binary threshold',thresh)
cv2.imshow('Binary Inverted',thresh2)
cv2.imshow('OTSU',thresh2)

cv2.imshow('Adaptive Threshold',adaptive)

cv2.waitKey(0)
cv2.imwrite("Image Output/1.GrayImage.jpg",gray_img)
cv2.imwrite("Image Output/2.HSV_Image.jpg",hsv_img)
cv2.imwrite("Image Output/3.BinaryThreshold.jpg",thresh)
cv2.imwrite("Image Output/4.BinaryInvertedThreshold.jpg",thresh1)
cv2.imwrite("Image Output/5.OTSU.jpg",thresh2)
cv2.imwrite("Image Output/6.AdaptiveThreshold.jpg",adaptive)

cv2.destroyAllWindows()