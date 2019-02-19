;; Auto-generated. Do not edit!


(when (boundp 'can::frame)
  (if (not (find-package "CAN"))
    (make-package "CAN"))
  (shadow 'frame (find-package "CAN")))
(unless (find-package "CAN::FRAME")
  (make-package "CAN::FRAME"))

(in-package "ROS")
;;//! \htmlinclude frame.msg.html


(defclass can::frame
  :super ros::object
  :slots (_id _data ))

(defmethod can::frame
  (:init
   (&key
    ((:id __id) 0)
    ((:data __data) (make-array 8 :initial-element 0 :element-type :char))
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _data __data)
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; uint32 _id
    4
    ;; uint8[8] _data
    (* 1    8)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _id
       (write-long _id s)
     ;; uint8[8] _data
     (princ _data s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8[8] _data
   (setq _data (make-array 8 :element-type :char))
   (replace _data buf :start2 ptr-) (incf ptr- 8)
   ;;
   self)
  )

(setf (get can::frame :md5sum-) "2f636bf314749eeb00e7f85696286658")
(setf (get can::frame :datatype-) "can/frame")
(setf (get can::frame :definition-)
      "uint32 id
uint8[8] data

")



(provide :can/frame "2f636bf314749eeb00e7f85696286658")


