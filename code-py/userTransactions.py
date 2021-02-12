
import requests
import datetime
import time

BASE_URL = "https://jsonmock.hackerrank.com/api/transactions/search"


def getUserTransaction(uid, txnType, monthYear):
    month, year = monthYear.split('-')
    month = int(month)
    epochThisMonth = int(time.mktime(datetime.datetime.strptime(
        '{0}-{1}'.format(month, year), '%m-%Y').timetuple()) * 1000)

    nextMonth = 1 if month == 12 else month + 1
    epochNextMonth = int(time.mktime(datetime.datetime.strptime(
        '{0}-{1}'.format(nextMonth, year), '%m-%Y').timetuple()) * 1000)

    page, maxPage, all_txns = 1, None, []
    while maxPage is None or page <= maxPage:
        r = requests.get(BASE_URL, params={
            'userId': uid,
            'page': page
        })
        obj = r.json()
        maxPage = obj['total_pages']
        page += 1

        for txn in obj['data']:
            if txnType == txn['txnType']:
                # check in range
                epoch = txn['timestamp']
                if epochThisMonth <= epoch < epochNextMonth:
                    all_txns.append(
                        (txn['id'], float(txn['amount'].replace('$', '').replace(',', ''))))
                    # print ('txn eligible ', txn['id'])
    # print(all_txns)
    meanTxn = sum([i[1] for i in all_txns]) / len(all_txns)
    # print (meanTxn)
    moreThanMean = [i[0] for i in all_txns if i[1] > meanTxn]
    # print (moreThanMean)
    return moreThanMean


if __name__ == '__main__':
    print (getUserTransaction(4, 'debit', '02-2019'))
