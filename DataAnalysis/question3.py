import sys
import pymongo
from datetime import datetime
import re
import os
import itertools

uri = 'mongodb://test_user:test_password@ds151141.mlab.com:51141/fanai_test'

class ProcessData():
    def __init__(self):
        pass

    def get_date(self):
        dateToSearch = input("Enter the date in YYYY-MM-DD format for which you want to insert records: ")
        try:
            datetime.strptime(dateToSearch, '%Y-%m-%d')
        except ValueError:
            print ("Incorrect format!!")
            return
        return dateToSearch

    def get_data(self,dateToSearch):
        filelocation = 'solution/' + dateToSearch
        filesInFolder = []
        try:
            filesInFolder = os.listdir(filelocation)
        except FileNotFoundError:
            print("Entered date unavailable!!")
        return filesInFolder

    def put_data_in_mongodb(self,myFiles,dateToSearch):
        client = pymongo.MongoClient(uri)
        db = client.get_default_database()
        db = db['test_followers']
        solutionFolder = 'solution/' + dateToSearch
        records = []
        for idx in myFiles:
            if idx.endswith('.json'):
                fpath = os.path.join(solutionFolder, idx)
                f = open(fpath)
                for x in re.split(r'[,;\[\]\n]+',f.read()):
                    records.append(x)
                d = [dict(itertools.zip_longest(*[iter(records)] * 2, fillvalue=""))]
                db.insert_many(d)
        client.close()


def main(args):
    pd = ProcessData()
    dateToSearch = pd.get_date()
    if dateToSearch is not None:
        myFiles = pd.get_data(dateToSearch)
        pd.put_data_in_mongodb(myFiles,dateToSearch)
    else:
        print("Entered date unavilable!!")


if __name__ == '__main__':
    main(sys.argv[1:])
