# CVkinematicsToolKit
Computer vision toolkit principally for analyzing fish biomechanics and kinematics 

2D_Tracking
---
Contains a GUI template for trying out tracking methods.  Currently uses background subtraction.

Controls:
- z,x: Forward, back 1 frame.
- a,s: Forward, back 1 frame.
- q,w: Forward, back 1 frame.
- 1,2: Forward, back 1 frame.

**Background definition**:  The background definition works by taking two images from the video where the fish is at different positions, then combining these 2 images to remove the fish from the reference image.  Do set your background image, do the following: 1) Click Background, then click the upper left and lower right area where the fish is.  2) Jump forward a few frames until the fish has moved out of the box you defined.  Then press the background button again.  You can see the resulting image to verify the fish has be cut from the image.
