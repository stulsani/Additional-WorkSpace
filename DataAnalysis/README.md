Question 1 :
I have results for date 2017-03-28, that is I have compared I have compared 2017-03-28 date
folder to 2017-02-28 folder to get results for 2017-03-28 date. The solution to this question
lies in solution folder.

Question 2:
I have compared all the teams to each other for dates 2017-03-28 and 2017-02-28
and stored the result in solution2 folder for each specific date.

Question 3:
I have connected to the mlab instance using pymongo and inserted the data to MongoDB.
The data just contains few enteries (I did'nt want to post everything to avoid loss of space)

NOTE: Question 1 & 2 have been solved using ProcessPoolExecutor, which creates N independent
running Python interpreters where N is number of available CPUs detected n the system.
The ProcessPoolExecutor is a part of concurrent.futures library and has many advantages like:
- It can/should be used to execute computational intensive functions.
- It creates instance of separately running python interpreter, hence overcoming the problem
of GIL (Global Interpreter Lock) which allows only one Python thread to execute at a given time.
