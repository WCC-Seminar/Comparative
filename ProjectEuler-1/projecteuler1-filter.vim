function! s:ProjectEuler(n)
	let nums = range(a:n)
	call filter(nums, 'v:val % 3 == 0 || v:val % 5 == 0') 
	return s:sumoflist(nums)
endfunction

function! s:sumoflist(li)
	" Don't know if there's a built-in.
	let sum = 0
	for item in a:li
		let sum += item
	endfor
	return sum
endfunction

echo s:ProjectEuler(1000)
