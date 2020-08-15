import cv2
import numpy as np

img = cv2.imread("yellow_flower.jpg")
res = cv2.resize(img,(600,400))
cv2.imshow("resized",res)


rgbl = np.array([25,90,0],np.uint8)
rgbh = np.array([50,255,255],np.uint8)
mask = cv2.inRange(res,rgbl,rgbh)

cv2.imshow("masked",mask)

kernel = np.array(([1,2,3],[2,2,1],[2,4,3]) , np.uint8)

filter = cv2.filter2D(res,-1,kernel)
cv2.imshow("filter",filter)

avg = cv2.blur(res,(5,5))
cv2.imshow("average",avg)

median = cv2.medianBlur(res,5)
cv2.imshow("median",median)

guass = cv2.GaussianBlur(res,(5,5),0)
cv2.imshow("guass",guass)

bilateral = cv2.bilateralFilter(res,5,111,111)
cv2.imshow("bilateral",bilateral)

pts = np.array([[250,400],[210,320],[375,320],[335,400]],np.int32)
pts = pts.reshape((-1,1,2))

image1 = cv2.fillPoly(res,[pts],(0,0,255))

font = cv2.FONT_HERSHEY_PLAIN
cv2.putText(image1,'Yellow flower',(75,50),font,2,(255,255,0))
cv2.imshow("test",image1)



#saving images

cv2.imwrite("resize.jpg",res)
cv2.imwrite("filter.jpg",filter)
cv2.imwrite("average_blur.jpg",avg)
cv2.imwrite("mask.jpg",mask)
cv2.imwrite("median_blur.jpg",median)
cv2.imwrite("guassian_blur.jpg",guass)
cv2.imwrite("bilateral.jpg",bilateral)
cv2.imwrite("pot.jpg",image1)




cv2.waitKey(0)
cv2.destroyAllWindows()