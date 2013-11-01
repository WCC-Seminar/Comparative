function! s:fib(n)
	if a:n == 1
		return [1]
	elseif a:n == 2
		return [1,1]
	else
		let terms = s:fib(a:n-1)
		call add(terms, terms[-1]+terms[-2])
		return terms
	endif
endfunction

echo s:fib(20)
