function! s:fib(n)
	let a = 1
	let b = 1
	let fibs = []
	for i in range(a:n)
		call add(fibs, a)
		let b = a + b
		let a = b - a
	endfor
	return fibs
endfunction


echo s:fib(20)
