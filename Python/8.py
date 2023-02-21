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
