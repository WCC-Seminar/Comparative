#!/usr/bin/python
def main():
    print "".join(chr(int(sum([((n == i == 0 and 1) or ((i>0 and reduce(lambda x,y : x*y, range(n+1-i, n+1),1 )) or 0))* [72, 101.0, -47.0, 14.5, -3.2083333333333335, -0.05, 0.39861111111111114, -0.17440476190476195, 0.044270833333333356, -0.007688492063492068, 0.0009245480599647256, -6.308120891454207e-05, -2.624208353374473e-06][i] for i in range(13)]))) for n in range(13) )
if __name__ == '__main__':
    main()


