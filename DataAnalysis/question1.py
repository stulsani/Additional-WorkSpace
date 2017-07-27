import os
from datetime import datetime
import re
from itertools import chain
from concurrent.futures import ProcessPoolExecutor

class ProcessInput():
    def __init__(self):
        pass
    def get_date(self):
        dateToSearch = input("Enter the date in YYYY-MM-DD format: ")
        try:
            datetime.strptime(dateToSearch, '%Y-%m-%d')
        except ValueError:
            print ("Incorrect format!!")
            return
        return dateToSearch

    def get_comman_files(self,dateToSearch):
        datesFolder = [name for name in os.listdir(".") if os.path.isdir(name)]
        datesFolder = sorted(datesFolder)
        myFiles = []
        prevDate = None
        if dateToSearch in datesFolder:
            indexForDate = datesFolder.index(dateToSearch) - 1
            if indexForDate > -1:
                prevDate = datesFolder[indexForDate]
                currDateList = os.listdir(dateToSearch)
                prevDateList = os.listdir(prevDate)
                myFiles = [i for e in currDateList for i in prevDateList if e in i]
            return prevDate,myFiles


class ProcessData():
    def __init__(self):
        pass
    def process_data(self,myFiles,dateToSearch,prevDate):
        print(prevDate)
        for data in myFiles:
            fpath1 = os.path.join(dateToSearch, data)
            fpath2 = os.path.join(prevDate, data)
            f1 = open(fpath1)
            records1 = []
            for record in re.split(r'[,;\[\]\n]+',f1.read()):
                 records1.append(record)
            f1.close()
            records2 = []
            f2 = open(fpath2)
            for record in re.split(r'[,;\[\]\n]+',f2.read()):
                records2.append(record)
            f2.close()
            records = []
            records1 = [int(x) for x in records1 if x not in '']
            records2 = [int(x) for x in records2 if x not in '']
            records = [a for a in chain(records1, records2) if (a not in records1) or (a not in records2)]
            records = [int(x) for x in records]
            filepath = 'solution/' + dateToSearch + '/' + data
            if not os.path.exists(os.path.dirname(filepath)):
                os.makedirs(os.path.dirname(filepath))
            with open(filepath, 'w') as temp_file:
                 temp_file.write(str(records))


processInput = ProcessInput()
dateToSearch = processInput.get_date()
if dateToSearch is not None:
    myFiles = []
    prevDate,myFiles = processInput.get_comman_files(dateToSearch)
    if prevDate is not None:
        pd = ProcessData()
        with ProcessPoolExecutor() as pool:
            pd.process_data(myFiles,dateToSearch,prevDate)
    else:
        print("Previous date data not available!!")
else:
    print("Enter date properly!!")
