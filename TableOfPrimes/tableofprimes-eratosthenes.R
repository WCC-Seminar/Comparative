prime2 <- function(x){ if(x<=2) return(c(2))
		      if(x<=3) return(c(2,3))
		      if(x>=4) {
				vec <- rep(0,x)
				vec[1] <- 1
				prim2 <- prime2( floor( sqrt(x) ))
				for(i in 1:length(prim2) ) {
						vec[ (2:floor(x/prim2[i]) * prim2[i]) ] <- 1
							   }
				return(which(vec==0))
				}
			}

















prime1 <- function(x){ if(x<=4) return(c(2,3))
		      if(x<=6) return(c(2,3,5))
		      if(x<=8) return(c(2,3,5,7))
		      if(x>=9) {
				vec <- rep(0,x)
				vec[1] <- 1
				prim2 <- prime1( floor( sqrt(x) ))
				for(i in 1:length(prim2) ) {
						vec[ (2:floor(x/prim2[i]) * prim2[i]) ] <- 1
							   }
				return(which(vec==0))
				}
			}


