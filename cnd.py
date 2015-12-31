#!/usr/bin/python

import cv2, sys

cap = cv2.VideoCapture(0)
while True:
    ret, frame = cap.read()

    # Our operations on the frame come here
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Display the resulting frame
    sys.stdout.write(frame.tostring())


# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()


