; fibonacci sequence.
; seems too ugly, but at least it works.
(defun fib (n)
  (cond
    ((= n 1) '(1))
    ((= n 2) '(1 1))
    (t (let ((temp (fib (- n 1))))
         (return-from fib (cons (+ (first temp) (second temp)) temp))))))

(print (reverse (fib 100)))
