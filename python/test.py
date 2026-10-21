import csv
import operator
header=["Symbol","Volume","Max","Min"]
with open("YOLO.txt", "r") as f:  # open in write mode
    reader = csv.reader(f)
    line = next(reader)
    with open("new.csv", "w",newline='') as g:
        writer = csv.writer(g)
        writer.writerow(header)
        k=0
        for x in sorted(reader, key=operator.itemgetter(0)):
            if k == 0:
                max=float(x[1])
                min=float(x[1])
            if float(x[1]) > max:
                max=float(x[1])
            if float(x[1]) < min:
                min=float(x[1])
            y = [x[0], int(x[5]), max, min]
            writer.writerow(y)
            k=k+1