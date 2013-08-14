function PE1(Maxnum)
	local Sum
	Sum=0
	for i=1,Maxnum-1 do
		if i%3==0 or i%5==0 then
			Sum=Sum+i
		end
	end
	return Sum
end

print(PE1(1000))
