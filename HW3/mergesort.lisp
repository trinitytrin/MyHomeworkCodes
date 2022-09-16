
(defun single (sequence)
 (or (eq (length sequence) 0) (eq (length sequence) 1)))	  
	  
(defun merge-sort (sequence)
  (if (or (null sequence) (single sequence))
      sequence
      (let ((half (truncate (/ (length sequence) 2))))
        (merge (type-of sequence)
               (merge-sort (subseq sequence 0 half))
               (merge-sort (subseq sequence half))
               #'<)))) 
			   
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
(print '(before sorting the Array))
(print a) 			   




(print '(after sorting the Array))
(print (merge-sort a))

(print '(before sorting the List))
(print (setf b (list (random 100) (random 100) (random 100) (random 100) (random 100) (random 100) (random 100) (random 100))))
(print '(After sorting the List))
(print (merge-sort b))