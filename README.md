# CVkinematicsToolKit
Computer vision toolkit principally for analyzing fish biomechanics and kinematics 

## 2D_Tracking

Contains a GUI template for trying out tracking methods on a single individual.  Uses background subtraction, and `erode` to clean resulting binary images.

Controls:
- z,x: Forward, back 1 frame.
- a,s: Forward, back 10 frame.
- q,w: Forward, back 100 frame.
- 1,2: Forward, back 1000 frame.

**Background definition**:  To set your background image, do the following

1. Click Background, then click the upper left and lower right area where the fish is.
2. Jump forward a few frames until the fish has moved out of the box you defined.  Then press the background button again.  You can see the resulting image to verify the fish has be cut from the image.  Now you can view the results of the background subtraction.

### To do list
- Make visual mask so detected objects can be highlighted on video frame
- Calculate center of mass for largest detected binary objects (the fish's location)
- Save fish positions to memmap file on disk
  - So if program crahses, data is still saved on disk
- Add settings file, so changes are saved locally 
  - Should be saved with the same name as video, in video folder
- Add user input for tank dimentions (so can convert units to absolute measurements)
  - User clicks 4 corners of closest tank wall
  - Add defined tank wall to video view
- Add chart in data tab, so can view tracking info
  - Show x, y positions of fish
  - Can also show error proxies (proportion of tank area covered by detections).  This might be nice for knowing when a new background image has to be defined.
- Create analysis function for looping through whole video
  - Should be pushed on the worker thread
  - Main UI can have a statusbar showing progress
  - Implement a Stop Analysis button.
