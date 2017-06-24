from multiprocessing import Pool
import multiprocessing

def myfunction(num):
    print("Process No. {}".format(num))

def job(num):
    return num*2

if __name__ == '__main__':
    for i in range(100):
        p = multiprocessing.Process(target=myfunction(i),args=(i,))
        p.start()
        p.join()

    p1 = Pool(20)
    data = list(map(job, range(5)))
    data1 = p1.map(job, [5,10])
    print(data)
    print(data1)
