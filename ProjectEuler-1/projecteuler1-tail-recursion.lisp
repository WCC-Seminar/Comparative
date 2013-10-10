; a solution for Project Euler 1 with tail recursion.
(defun myanswert (n psum)
  (cond 
    ((= n 0) psum)
    ((or (= (mod n 3) 0) (= (mod n 5) 0)) (myanswert (- n 1) (+ psum n)))
    (t (myanswert (- n 1) psum))))

(defun myanswer (n) (myanswert n 0))

(print (myanswer 999))
