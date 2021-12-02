def readFile():
    f = open("day_1_input.txt", "r")
    data = [int(line.strip()) for line in f]
    f.close()
    return data

def puzzleOne():
    counter = 0
    data = readFile()
    for x in range(1, len(data)):
        if data[x] > data[x-1]:
            counter += 1
    
    print("Part 1: " + counter)


if __name__ == '__main__':
    puzzleOne()
