import os
from datetime import datetime
import json
from pprint import pprint
import re
from concurrent.futures import ProcessPoolExecutor

class ProcessData:
    def __init__(self):
        pass
    def get_date(self):
        dateToSearch = input("Enter the date in YYYY-MM-DD format: ")
        try:
            datetime.strptime(dateToSearch, '%Y-%m-%d')
        except ValueError:
            print ("Incorrect format")
            return
        return dateToSearch


class TeamFollowers:
    def __init__(self):
        pass
    def read_team_hierarchical_file(self):
        data = []
        with open('accounts_hierarchy.json','r') as f:
            players = []
            i = 0
            for line in f:
                myLine = json.loads(line)
                data.append(myLine["screen_name"])
                handles = ''
                for each in myLine["teams"]:
                    d = {}
                    players.append(each["players"])
                    handles = each["screen_name"]
                    d[handles] = players[i]
                    i += 1
                    data.append(d)
        return data

    def get_followers_id(self,teamsInfo,dateToSearch):
        recordsList = [None]*len(teamsInfo)
        currDateList = os.listdir(dateToSearch)
        i = 0
        for followerList in teamsInfo:
            records = []
            if type(followerList) is dict:
                for key,value in followerList.items():
                    for followerfile in value:
                        followerfile = 'followers_' + followerfile + '.json'
                        fpath = os.path.join(dateToSearch, followerfile)
                        if os.path.exists(fpath):
                            f = open(fpath)
                            for record in re.split(r'[,;\[\]\n]+',f.read()):
                                 records.append(record)
                            f.close()
            else:
                followerList = 'followers_' + followerList + '.json'
                fpath = os.path.join(dateToSearch, followerList)
                if os.path.exists(fpath):
                    f = open(fpath)
                    for record in re.split(r'[,;\[\]\n]+',f.read()):
                        records.append(record)
                    f.close()
            recordsList[i] = records
            i += 1
        return recordsList

    def compare_team_followers(self,recordsList,teamsInfo,dateToSearch):
        num = 1
        lengthOfRecords = len(recordsList)
        for i in recordsList:
            d = {}
            for data in i:
                if data not in '':
                    d[data] = int(data)
            x = num
            nameOfTeam = ''
            if type(teamsInfo[num-1]) is dict:
                for key in teamsInfo[num-1]:
                    nameOfTeam = key
            else:
                nameOfTeam = teamsInfo[num-1]
            while x < lengthOfRecords:
                comparedToFile = ''
                if type(teamsInfo[x]) is dict:
                    for key in teamsInfo[x]:
                        comparedToFile = key
                else:
                    comparedToFile = teamsInfo[x]
                filepath = 'solution2/' + dateToSearch + '/' + nameOfTeam + '&' + comparedToFile + '.json'
                if not os.path.exists(os.path.dirname(filepath)):
                    os.makedirs(os.path.dirname(filepath))
                commanData = []
                for j in recordsList[x]:
                    if j in d:
                        commanData.append(j)
                with open(filepath, 'w') as temp_file:
                     temp_file.write(str(commanData))
                x += 1
            num += 1


pd = ProcessData()
dateToSearch = pd.get_date()
if dateToSearch is not None:
    td = TeamFollowers()
    data = td.read_team_hierarchical_file()
    with ProcessPoolExecutor() as pool:
        recordsList = td.get_followers_id(data,dateToSearch)
    with ProcessPoolExecutor() as pool:
        td.compare_team_followers(recordsList,data,dateToSearch)
