;;(defun factorial (N)
 ;; "Compute the factorial of N."
  ;;(if (= N 1)
    ;;  1
   ;; (* N (factorial (- N 1)))))
   
   
(setf a (make-array '(10)))
(terpri)
(setf (aref a 0) (random 100))
(setf (aref a 1) (random 100))
(setf (aref a 2) (random 100))
(setf (aref a 3) (random 100))
(setf (aref a 4) (random 100))
(setf (aref a 5) (random 100))
(setf (aref a 6) (random 100))
(setf (aref a 7) (random 100))
(setf (aref a 8) (random 100))
(setf (aref a 9) (random 100))
(write a)   





(defun merge-sort (array)
  (if (small array) array
	  (merge-lists
		(merge-sort (left-half array))
		(merge-sort (right-half array))))) 
		
(defun small (array)
  (or (eq (length array) 0) (eq (length array) 1))) 

(defun right-half (array)
  (last array (ceiling (/ (length array) 2))))
(defun left-half (array)
  (ldiff array (right-half array))) 

(defun merge-lists (a1 a2)
  (merge array a1 a2 #'<))

 (merge-sort a)  
  
;;(defun merge-sort (list)
;;  (if (small list) list
;;	  (merge-lists
;;		(merge-sort (left-half list))
;;		(merge-sort (right-half list))))) 
		
;;(defun small (list)
 ;; (or (eq (length list) 0) (eq (length list) 1))) 

;;(defun right-half (list)
;;  (last list (ceiling (/ (length list) 2))))
;;(defun left-half (list)
;;  (ldiff list (right-half list))) 

;;(defun merge-lists (list1 list2)
;;  (merge 'list list1 list2 #'<))   