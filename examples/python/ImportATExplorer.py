import atexplorer

print (atexplorer.MyTest(33))

a = atexplorer.ATObject()

for i in range(1000000):
    print (str(i) + str(": ") + a.getTypeName())


