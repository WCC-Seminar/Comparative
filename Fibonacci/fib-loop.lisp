(defun fib (n)
  (let (( fibs '()))
    (loop :for m :from 1 :to n do
          (cond
            ((= m 1) (push 1 fibs))
            ((= m 2) (push 1 fibs))
            ( t (push (+ (first fibs) (second fibs)) fibs))))
    (return-from fib (reverse fibs))))

(print (fib 100))
