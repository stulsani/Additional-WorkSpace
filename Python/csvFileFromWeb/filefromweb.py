from urllib import request
goog_url = 'https://query1.finance.yahoo.com/v7/finance/download/GOOG?period1=1492881205&period2=1495473205&interval=1d&events=history&crumb=a7AMRPaLncp'

def download_stock_data(stock_url):
    response = request.urlopen(stock_url)
    stock = response.read()
    stock_url_str = str(stock)
    lines = stock_url_str.split('\\n')
    dest_url = r'goog.csv'
    fx = (dest_url,'w')
    for line in lines:
        fx.write(line + "\n")
    fx.close()


download_stock_data(goog_url)
