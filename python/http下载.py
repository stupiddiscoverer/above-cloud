import requests
import os

if __name__ == '__main__':
	try:
		html = requests.get('http://book.zongheng.com/chapter/1005752/61244105.html', timeout=200).content
		with open('c:/users/children/desktop/jili.txt','wb') as f:
			f.write(html)
			f.close()
	except Exception as e:
		print(e)