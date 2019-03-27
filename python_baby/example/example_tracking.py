#! python3
#nubmer face
import numpy as np  #   librarie for the IHM
import cv2          #   librarie for the camera capture an working
import math         #   librarie for mathematic function ( racine carre et puissance ( Â² )
import serial
import sys

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_alt.xml')
#       xml file do decript in capture the face of humans

cap = cv2.VideoCapture(0)   # 0 not 1 because is a bug ( in windows sure )
cap.set(480,640)      #   size capture ( x   y )

#ser = serial.Serial('COM9',9600,timeout=0.5)  # open serial port
#print(ser.name)         # check which port was really used
#ser.close()             # close port

passe=0
tete=0

while 1:                        #   void loooOOOOOoooop :)
    ret, img = cap.read(200)                                   #   running camera
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.3, 2)     #   parameter of contoure of face

    for (x,y,w,h) in faces:                                 #   made a contour cube on face
        font = cv2.FONT_HERSHEY_SIMPLEX # the font of the text
        
        tete = tete + 1
        if(tete == 1):
            cv2.putText(img,"MASTER",(x,y-28), font, 1,(0,0,0),5,cv2.LINE_AA)
            
        #---------------- PREPARE THE VARIABLE TO DISPLAY THE DISTANCE ---------------------
        #
        #    ______________________________________________________________
        #   /!\     distance d un vecteur = racinne²(xa-xb)²+(yb-ya)²    /!\
        #   ________________________________________________________________
        
            display1=x              #yb-ya = 0  ^   car yb == ya   

            c = round((((x - 0) * (180 - 0) / (640 - 0) + 0)*-1 )+180 )
       

            
            display=str(c)
            if( c > passe or c < passe):
                passe=c
                b = str.encode("dd")
                print("send")
                ser.write(b)

            
        #------------ END PREPARE THE VARIABLE TO DISPLAY THE DISTANCE ---------------------
            
        cv2.putText(img,str(tete),(x,y+28), font, 1,(0,0,0),5,cv2.LINE_AA)
        cv2.rectangle(img,(x,y),(x+w,y+h),(0,120,255),3)
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = img[y:y+h, x:x+w]

        cv2.circle(img,(int(x+(w/2)),int(y+(h/2))), 10, (0,0,255), -1)  # display point on center face
    

        font = cv2.FONT_HERSHEY_SIMPLEX # the font of the text
        
        #cv2.putText(img,display,((int(x+(w/2)),int(y+(h/2)))), font, 1,(0,250,0),5,cv2.LINE_AA)
        #           (img,string,(x,y),font,(size of caractere),(color),size of caractere,cv2.LINE_AA) 
        #   display a text with a variable (display) is the distance (px) of your head and the 1/2 screen 
        
        cv2.line(img,((int(x+(w/2)),int(y+(h/2)))),(320,int(y+(h/2))),(0,0,255),5)
        #   line to connecte the face with the 1/2 screen 
        
    cv2.line(img,(320,0),(320,int(600/4)),(1,170,120),5)   #   cut the screen in 2 parts withe a line x axe made
        #         (x,y) ,   (x,y)
    cv2.line(img,(320,int(600/4)*2),(320,600),(1,170,120),5)   #   cut the screen in 2 parts withe a line X axe mades
        #         (x,y) ,   (x,y)

    cv2.line(img,(0,240),(int(640/4),240),(1,170,120),5)   #   cut the screen in 2 parts withe a line Y axe mades
        #         (x,y) ,   (x,y)
    cv2.line(img,(int(640/4)*3,240),(640,240),(1,170,120),5)   #   cut the screen in 2 parts withe a line Y axe mades
        #         (x,y) ,   (x,y)

    cv2.rectangle(img,(int(640/4)*3,int(600/4)*2),(int(640/4),int(600/4)),(1,170,120),5)        #   center
        #                           (x,y)       ,          (x,y)
    if(tete==0):
        print("send 0 ")
    tete=0

    cv2.imshow('img',img)
    k = cv2.waitKey(1) &    0xff    # exit avec le code touche 'echap'
    if k == 27:
        break

cap.release()               #   end camera
cv2.destroyAllWindows()     #   close all windows
