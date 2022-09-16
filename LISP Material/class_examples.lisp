;; (setq a (read))
;; setf covers setq which is an old command, refer to CMU website 
;; pay attention to which is function, which is macro, and which is special-form
;; http://www.cs.cmu.edu/afs/cs/Web/Groups/AI/html/cltl/clm/index.html#I 

(defun power (x y) (if (= y 0) 1 (* x (power x (1- y)))))
(defun factorial (x) (if (<= x 0) 1 (* x (factorial (1- x)))))

(do ((x 1 (1+ x)) (y 5 (1- y)))
    ((> x 5) y)
    (print (list x y)))
	
(setf m (make-array '(10)))
(print m)

(loop (print a) (incf a 2) (when (> a 7) (return a)))

;; when, unless, and let's bodys allow multiple functions
(when (> a 0) (print a) (print b) (print c)) 
(unless (> a 0) (print a) (print b) (print c)) 
(let ((a 1) (b a)) (print a) (print b))		;; compare with the following
(let* ((a 1) (b a)) (print a) (print b))

(incf a 3)		; macro, increase a by 3 and assign the result to a
(incf a)		; macro, similar to (1+ a), change a's value
(decf a 3)		; macro, decrease a by 3 and assign the result to a
(gcd 12 36 108)	; function, return greatest common divisor
(lcm 12 36 108)	; function, return least common multiple

(dotimes (i 10) (setf (aref m i) (random 100)))
(print m)

;; functions and parameters
(defun baaz (&optional (x 3) (y 10)) (+ x y))	; both x and y are optional 
(defun bar (x &optional y) (if y x 0))			; y is optional without initial value
;(defun bar (x &optional (y 3)) (+ x y))		; y is optional with initial value
(defun foo (x &rest y) y) 						; all but the first parameter are put into a list
(defun fun (&key x y) (cons x y))				; function with ‘keyword’ parameters
(fun :x 5 :y '(3))

;; how to print: newline ~%, any lisp object ~s, any integer ~d
(format t "~%")
(format t "~%This number ~s ~%is bigger than this ~s ~%" 5 3)

;; how to receive a number from input
(setf a (read))
(setf b (random 100.0))

;; how to read a whole line, with or without spaces, always returns a string
(setf c (read-line))
;; function read-char always requires just one char input

;; lambda expression, to define temporary functions 
(setf product (lambda (x y) (* x y)))
(funcall product 3 4)
(apply product '(3 4))

;; mapcar applies a function repeatedly, to each element of a list and returns a list of the result
(mapcar #'factorial '(3 4 10))	
(mapcar #'power '(3 4 10) '(5 3 2))			;; the result is (243 64 100)
(mapcar #'sort '((1 3 2) (3 1 2)) '(> <))	;; sort two lists ascendingly and descendingly

;; progn allows multiple functions to ran sequentially	
(if (> a 0) (progn (print a) (print b)) (print c))
	
(funcall #'+ 2 3)
;; (funcall #'product 3 4) ; incorrect, prodcut is not a pre-defined function
(apply #'+ 2 '(3 4))
	
;; #'< represent function name, compared with above "product"
;; built-in sorting algorithm
(sort '(2 1 5 4 6) #'<)
(sort '(2 1 5 4 6) #'>)		

;; test if an <item> and the elements of a list using test or test-not condition, not both 
;; if the item is found to match an element of the <list>, 
;; a list containing all the elements from <item> to the end of <list> is returned.
(member 3 '(1 2 5 4)) ; return nil
(member 3 '(1 2 3 4) :test #'<)
(member 3 '(1 2 3 4) :test-not #'=)

(find 'a '(b d a c))			;another way to do set-membership, not case-senstive
(subsetp '(a b) '(a d e))		;set containment
(intersection '(a b c) '(b))	;set intersection
(union '(a) '(b))				;set union
(set-difference '(a b) '(a))	;set difference

;; file open & close, the following example open the file, read the first line, and print it
(let ((in (open "c:/examples/clisp/2015.lisp")))
  (format t "~a~%" (read-line in))
  (close in))

;; using a list like a stack
(setf d nil)
(push 1 d)
(push 2 d)
(pop d)

;; function description
(function +)			; will show that + is a system defined function
(function factorial)	; will show the source code of factorial function

(quote (+ 3 4))		; quote prevents its arguments from being evaluated.

(numberp 2)      	; t
(numberp 'a)     	; nil
(listp '(1 2 3)) 	; t
(functionp #'+)   	; t
(functionp '+)   	; nil, interpreted as character '+'
(functionp +)   	; nil

;; macro definition
(defmacro 2plus (x) (+ x 2))
(2plus 3) ; => 5, the parameter must be a number

