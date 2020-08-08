import cv2

img = cv2.imread("text.jpg")
cv2.imshow("original",img)

gray = cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)
hsv =  cv2.cvtColor(img,cv2.COLOR_RGB2HSV)

cv2.imshow("grayscale",gray)
cv2.imshow("hsv",hsv)

res = cv2.resize(img,(300,300))
cv2.imshow("resized",res)

print("showing Shape and Size of original image - " , img.shape , img.size)
print("showing Shape and Size of resized image - " , res.shape , res.size)


ret,thresh_binary = cv2.threshold(gray,150,255,cv2.THRESH_BINARY)
ret,thresh_binary_inv = cv2.threshold(gray,150,255,cv2.THRESH_BINARY_INV)
ret,thresh_otsu = cv2.threshold(gray,150,255,cv2.THRESH_OTSU)

cv2.imshow("simple binary",thresh_binary)
cv2.imshow("simple binary inv",thresh_binary_inv)
cv2.imshow("simple otsu",thresh_otsu)



ad_thresh_mean = cv2.adaptiveThreshold(gray,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,5,2)
ad_thresh_guass = cv2.adaptiveThreshold(gray,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY,5,2)

cv2.imshow("adaptive mean",ad_thresh_mean)
cv2.imshow("adaptive guass",ad_thresh_guass)


cv2.imwrite("grayscale.jpg",gray)
cv2.imwrite("hsv.jpg",hsv)
cv2.imwrite("simple_binary.jpg",thresh_binary)
cv2.imwrite("simple_binary_inv.jpg",thresh_binary_inv)
cv2.imwrite("simple_otsu.jpg",thresh_otsu)
cv2.imwrite("adaptive_mean.jpg",ad_thresh_mean)
cv2.imwrite("adaptive_guass.jpg",ad_thresh_guass)



print("ALL IMAGES HAVE BEEN SAVED")



cv2.waitKey(0)
cv2.destroyAllWindows()