#!/usr/bin/python

import cv2, sys, time

cap = cv2.VideoCapture(0)
video_out = open("../sd-card/vlc-out", "w")

while True:
    start_time = time.time()
    ret, frame = cap.read()
    end_time = time.time()
    elapsed = end_time - start_time
    # print elapsed

    sleepy_time = 0
    if 1 - elapsed > 0:
        sleepy_time = 1 - elapsed
    time.sleep(sleepy_time)
    sys.stdout.write(frame.tostring())

cap.release()
cv2.destroyAllWindows()


