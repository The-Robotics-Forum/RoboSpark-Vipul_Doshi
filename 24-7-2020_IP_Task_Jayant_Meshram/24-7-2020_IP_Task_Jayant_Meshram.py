import cv2
import numpy as np

img= cv2.imread("yellow_flower.jpg")
org=cv2.resize(img,(600,400))
hsv=cv2.cvtColor(org,cv2.COLOR_BGR2HSV)
'''#Getting values for yellow
def abc(x):
   pass
def colormask():
    cv2.namedWindow("masking")
    bh='blue high'
    bl='blue low'
    gh='green high'
    gl='green low'
    rh='red high'
    rl='red low'
    cv2.createTrackbar(bl,'masking',0,255,abc)
    cv2.createTrackbar(bh,'masking',0,255,abc)
    cv2.createTrackbar(gl,'masking',0,255,abc)
    cv2.createTrackbar(gh,'masking',0,255,abc)
    cv2.createTrackbar(rl,'masking',0,255,abc)
    cv2.createTrackbar(rh,'masking',0,255,abc)
    while True:
        btl=cv2.getTrackbarPos(bl,'masking')
        bth=cv2.getTrackbarPos(bh,'masking')
        gtl=cv2.getTrackbarPos(gl,'masking')
        gth=cv2.getTrackbarPos(gh,'masking')
        rtl=cv2.getTrackbarPos(rl,'masking')
        rth=cv2.getTrackbarPos(rh,'masking')
        bgrl = np.array([btl, gtl, rtl])
        bgrh = np.array([bth, gth, rth])
        mask = cv2.inRange(hsv, bgrl, bgrh)
        cv2.imshow('original', org)
        cv2.imshow('masked', mask)
        k = cv2.waitKey(1)
        if k == 32:  # 32 is ascii value for space
            break            
#got values-[20,100,100] [30,255,255]'''

bgrl=np.array([20,100,100])
bgrh=np.array([30,255,255])

mask=cv2.inRange(hsv,bgrl,bgrh)

cv2.imshow('original',org)
cv2.imshow('masked',mask)

#_________filter2d_________
kernel=np.ones((5,5),np.float32)/25
masked_filter2d= cv2.filter2D(mask,-1,kernel)
org_filter2d= cv2.filter2D(org,-1,kernel )
cv2.imshow("Masked_Filter2d",masked_filter2d)
cv2.imshow("Original_Filter2d",org_filter2d)

#_________averaging_________
org_averaging = cv2.blur(org,(5,5))
masked_averaging = cv2.blur(mask,(5,5))
cv2.imshow("Masked_Average",masked_averaging)
cv2.imshow("Original_Average",org_averaging)

#_________gausian_blur_________
org_gaussian = cv2.GaussianBlur(org,(5,5),0)
masked_gaussian = cv2.GaussianBlur(mask,(5,5),0)
cv2.imshow("Masked_gaussian",masked_gaussian)
cv2.imshow("Original_gaussian",org_gaussian)

#_________median_blur_________
org_median = cv2.medianBlur(org,5)
masked_median = cv2.medianBlur(mask,5)
cv2.imshow("Masked_median",masked_median)
cv2.imshow("Original_median",org_median)


#_________bilateral_________
org_bilateral = cv2.bilateralFilter(org,15,75,75)
masked_bilateral = cv2.bilateralFilter(mask,15,75,75)
cv2.imshow("Masked_Bilateral",masked_bilateral)
cv2.imshow("Original_Bilateral",org_bilateral)

cv2.imwrite("Outputs/1.Mask.jpg",mask)

cv2.imwrite("Outputs/masked_blurred_outputs/1.Filter2D.jpg",masked_filter2d)
cv2.imwrite("Outputs/masked_blurred_outputs/2.Averaging.jpg",masked_averaging)
cv2.imwrite("Outputs/masked_blurred_outputs/3.Gaussian.jpg",masked_gaussian)
cv2.imwrite("Outputs/masked_blurred_outputs/4.Median.jpg",masked_median)
cv2.imwrite("Outputs/masked_blurred_outputs/5.Bilateral.jpg",masked_bilateral)

cv2.imwrite("Outputs/original_blurred_outputs/1.Filter2D.jpg",org_filter2d)
cv2.imwrite("Outputs/original_blurred_outputs/2.Averaging.jpg",org_averaging)
cv2.imwrite("Outputs/original_blurred_outputs/3.Gaussian.jpg",org_gaussian)
cv2.imwrite("Outputs/original_blurred_outputs/4.Median.jpg",org_median)
cv2.imwrite("Outputs/original_blurred_outputs/5.Bilateral.jpg",org_bilateral)

#_________drawing flower pot on bilateral masked output______
pot_i = cv2.imread("Outputs/masked_blurred_outputs/5.Bilateral.jpg")
pot = cv2.resize(pot_i,(400,600))
pot = cv2.ellipse(pot,(200,480),(100,30),180,0,360,(255,255,255),10)
pot = cv2.ellipse(pot,(100,520),(40,25),270,0,180,(255,255,255),10)
pot = cv2.ellipse(pot,(300,520),(40,25),90,0,180,(255,255,255),10)
pot = cv2.ellipse(pot,(100,580),(25,10),90,0,180,(255,255,255),10)
pot = cv2.ellipse(pot,(300,580),(25,10),270,0,180,(255,255,255),10)
font=cv2.FONT_HERSHEY_COMPLEX
pot = cv2.putText(pot,"Yellow_Flower",(0,50),font,1,(255,255,255),1)
cv2.imshow("Flower_pot",pot)

cv2.imwrite("Outputs/2.FlowerPot_on_bilateralMask.jpg",pot)




#colormask()
cv2.waitKey(0)
cv2.destroyAllWindows()