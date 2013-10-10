; using loop macro. It's like for statement in C
(defun myanswer (n)
  (let ((sum 0))
    (loop :for i :from 1 :to (- n 1) do
          (if (or (= (mod i 3) 0) (= (mod i 5) 0))
            (incf sum i)))
    (return-from myanswer sum)))
; the : before for, from, to doesn't seem necessary.
(print (myanswer 1000))
