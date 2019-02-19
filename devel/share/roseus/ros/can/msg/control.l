;; Auto-generated. Do not edit!


(when (boundp 'can::control)
  (if (not (find-package "CAN"))
    (make-package "CAN"))
  (shadow 'control (find-package "CAN")))
(unless (find-package "CAN::CONTROL")
  (make-package "CAN::CONTROL"))

(in-package "ROS")
;;//! \htmlinclude control.msg.html


(defclass can::control
  :super ros::object
  :slots (_speed _angle ))

(defmethod can::control
  (:init
   (&key
    ((:speed __speed) 0.0)
    ((:angle __angle) 0.0)
    )
   (send-super :init)
   (setq _speed (float __speed))
   (setq _angle (float __angle))
   self)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:serialization-length
   ()
   (+
    ;; float64 _speed
    8
    ;; float64 _angle
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _speed
       (sys::poke _speed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angle
       (sys::poke _angle (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _speed
     (setq _speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angle
     (setq _angle (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get can::control :md5sum-) "1ceff948a711f5758871c34a34e8560d")
(setf (get can::control :datatype-) "can/control")
(setf (get can::control :definition-)
      "float64 speed
float64 angle

")



(provide :can/control "1ceff948a711f5758871c34a34e8560d")


