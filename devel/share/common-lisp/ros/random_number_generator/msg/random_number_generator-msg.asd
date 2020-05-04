
(cl:in-package :asdf)

(defsystem "random_number_generator-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "rn" :depends-on ("_package_rn"))
    (:file "_package_rn" :depends-on ("_package"))
  ))