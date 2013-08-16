function sieve_of_Eratosthenes(n)
	local tablea = {}
	local tablep = {}
	local upperlimit = math.floor((n+1)/2)
	for i=2, upperlimit do
		if tablea[i]==nil then
			local jupper = math.floor(n/i)
			for j=2, jupper+1 do
				tablea[i*j] = true
			end
		end
	end
	for i=2,n do
		if tablea[i]==nil then
			tablep[#tablep+1]=i
		end
	end
	return tablep
end

function main(N)
	if N==nil then
		N = 1000
	end
	if N>81798 then
		print("too many results to show")
	else
		print(unpack(sieve_of_Eratosthenes(N)))
	end
end

main(1000)
