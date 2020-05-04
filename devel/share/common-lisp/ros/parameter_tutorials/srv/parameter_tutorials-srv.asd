
(cl:in-package :asdf)

(defsystem "parameter_tutorials-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "SrvTutorial" :depends-on ("_package_SrvTutorial"))
    (:file "_package_SrvTutorial" :depends-on ("_package"))
  ))