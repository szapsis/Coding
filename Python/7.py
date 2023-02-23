#This program checks whether a given list is a sublist of another list.
#It takes two arguments: the first is the larger list and the second is the potential sublist.
def foundList (List,subList):
    if len(List) < len(subList):
        return False
    elif len(List) == len(subList):
        if List == subList:
            return True
        else:
            return False
    else:
        slcount=subList.count(subList[0])
        lcount=List.count(subList[0])
        if slcount<lcount:
            return False
        elif slcount==lcount:
            tempList=List[(List.index(subList[0])):(List.index(subList[0])+len(subList))]
            return foundList(tempList,subList)
        else:
            if (foundList(List[(List.index(sublist[0])):(List.index(subList[0])+len(subList))],subList)):
                return True
            else:
                return (foundList(List[(List.index(sublist[0])+1):],subList))

print("Dose listes sti morfi '[a,b,c,d]' gia na elenxeis an i defteri einai ypolista tis prwtis.")
while True:
    L=[]
    SL=[]

    a=input("Dose Lista:\n")
    if a.startswith("[") and a.endswith("]"):
        L=a[1:(len(a)-1)].split(sep=",")
        b=input("Dose YpoLista:\n")
        if b.startswith("[") and b.endswith("]"):
            SL=b[1:(len(b)-1)].split(sep=",")
            if foundList(L,SL):
                print("NAI, EINAI YPOLISTA!")
            else:
                print("OXI DEN EINAI YPOLISTA!")
        else:
            print("Den edwses lista!")
            continue
    else:
        print("Den edwses Lista!")
        continue
