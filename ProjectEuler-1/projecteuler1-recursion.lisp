; a solution for Project Euler 1 with recursion.
(defun myanswer (n)
  (cond 
    ((= n 0) 0)
    ((or (= (mod n 3) 0) (= (mod n 5) 0)) (+ (myanswer (- n 1)) n))
    (t (myanswer (- n 1)))))

(print (myanswer 999))
