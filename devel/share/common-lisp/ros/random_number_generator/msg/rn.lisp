; Auto-generated. Do not edit!


(cl:in-package random_number_generator-msg)


;//! \htmlinclude rn.msg.html

(cl:defclass <rn> (roslisp-msg-protocol:ros-message)
  ((limit
    :reader limit
    :initarg :limit
    :type cl:integer
    :initform 0)
   (randint
    :reader randint
    :initarg :randint
    :type cl:integer
    :initform 0))
)

(cl:defclass rn (<rn>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <rn>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'rn)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name random_number_generator-msg:<rn> is deprecated: use random_number_generator-msg:rn instead.")))

(cl:ensure-generic-function 'limit-val :lambda-list '(m))
(cl:defmethod limit-val ((m <rn>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader random_number_generator-msg:limit-val is deprecated.  Use random_number_generator-msg:limit instead.")
  (limit m))

(cl:ensure-generic-function 'randint-val :lambda-list '(m))
(cl:defmethod randint-val ((m <rn>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader random_number_generator-msg:randint-val is deprecated.  Use random_number_generator-msg:randint instead.")
  (randint m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <rn>) ostream)
  "Serializes a message object of type '<rn>"
  (cl:let* ((signed (cl:slot-value msg 'limit)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'randint)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <rn>) istream)
  "Deserializes a message object of type '<rn>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'limit) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'randint) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<rn>)))
  "Returns string type for a message object of type '<rn>"
  "random_number_generator/rn")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'rn)))
  "Returns string type for a message object of type 'rn"
  "random_number_generator/rn")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<rn>)))
  "Returns md5sum for a message object of type '<rn>"
  "ee411822668b6440d55b15e5b8788d4f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'rn)))
  "Returns md5sum for a message object of type 'rn"
  "ee411822668b6440d55b15e5b8788d4f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<rn>)))
  "Returns full string definition for message of type '<rn>"
  (cl:format cl:nil "int32 limit~%int32 randint~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'rn)))
  "Returns full string definition for message of type 'rn"
  (cl:format cl:nil "int32 limit~%int32 randint~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <rn>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <rn>))
  "Converts a ROS message object to a list"
  (cl:list 'rn
    (cl:cons ':limit (limit msg))
    (cl:cons ':randint (randint msg))
))
