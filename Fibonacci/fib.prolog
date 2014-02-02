fib(1,1).
fib(2,1).

fib(Y,X) :- ZZ is Y-2, fib(ZZ,WW), Z is Y-1, fib(Z,W), X is W+WW.
