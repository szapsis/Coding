#This code imports the urllib.request module to retrieve the HTML content of a website specified by user input.
#The code continuously loops while prompting the user to enter a website URL.
#Upon receiving a valid URL, the code attempts to retrieve the website content using urllib.request.urlopen() and read it in as UTF-8 encoded text.
#The code then counts the number of occurrences of several HTML tags (<h1>, <h2>, <h3>, and <br>) in the retrieved HTML content using the count() method,
#and prints out the counts along with the title of the webpage (located within the <title> and </title> tags).
import urllib.request
while True:
    try:
        response=urllib.request.urlopen(input("Dwse istoselida: \n")).read().decode('utf-8')

        t1=response.index("<title>")
        t2=response.index("</title>")
        title=response[(t1+7):t2]

        h1=response.count("<h1>")
        h2=response.count("<h2>")
        h3=response.count("<h3>")
        br=response.count("<br>")


        print("O Titlos einai: {}".format(title))
        print("To h1: ",h1)
        print("Ta h2: ",h2)
        print("Ta h3: ",h3)
        print("Ta br: ",br)
    except:
        print("Lathos")
        pass
