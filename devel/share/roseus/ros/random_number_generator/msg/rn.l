;; Auto-generated. Do not edit!


(when (boundp 'random_number_generator::rn)
  (if (not (find-package "RANDOM_NUMBER_GENERATOR"))
    (make-package "RANDOM_NUMBER_GENERATOR"))
  (shadow 'rn (find-package "RANDOM_NUMBER_GENERATOR")))
(unless (find-package "RANDOM_NUMBER_GENERATOR::RN")
  (make-package "RANDOM_NUMBER_GENERATOR::RN"))

(in-package "ROS")
;;//! \htmlinclude rn.msg.html


(defclass random_number_generator::rn
  :super ros::object
  :slots (_limit _randint ))

(defmethod random_number_generator::rn
  (:init
   (&key
    ((:limit __limit) 0)
    ((:randint __randint) 0)
    )
   (send-super :init)
   (setq _limit (round __limit))
   (setq _randint (round __randint))
   self)
  (:limit
   (&optional __limit)
   (if __limit (setq _limit __limit)) _limit)
  (:randint
   (&optional __randint)
   (if __randint (setq _randint __randint)) _randint)
  (:serialization-length
   ()
   (+
    ;; int32 _limit
    4
    ;; int32 _randint
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _limit
       (write-long _limit s)
     ;; int32 _randint
       (write-long _randint s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _limit
     (setq _limit (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _randint
     (setq _randint (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get random_number_generator::rn :md5sum-) "ee411822668b6440d55b15e5b8788d4f")
(setf (get random_number_generator::rn :datatype-) "random_number_generator/rn")
(setf (get random_number_generator::rn :definition-)
      "int32 limit
int32 randint

")



(provide :random_number_generator/rn "ee411822668b6440d55b15e5b8788d4f")


