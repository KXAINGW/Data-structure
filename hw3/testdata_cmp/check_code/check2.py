import os

class Check:
    def __init__(self,dir_name):
        self.dir_name = dir_name
        self.fileName = ["11","12","13","14","15","16","17","18","19","20"] 
        self.output1 = []
        self.output2 = []

    def loadAllFile(self):
        for i in self.fileName:
            with open(f'{self.dir_name}.'+i+'.out.txt', 'rt') as inFile:
                self.output1 += [inFile.read()]
                print(f"Load {inFile.name} sucessful")
            with open(f'{self.dir_name}.'+i+'.myout.txt','rt') as inFile2:
                self.output2 +=[inFile2.read()]
                print(f"Load {inFile2.name} sucessful")

    def error_detection(self):
        error = 10
        for i in range(10):
            if self.output1[i] != self.output2[i]:
                print(f"test{i + 11} is error!")
            else:
                error-=1
        print(f"There are {error} errors in test\n")


if __name__ == "__main__":
    os.chdir('C:/Users/ASUS/Desktop/yzu/大二下/資結/hw/hw3/testdata_cmp')
    dir_names = ['array_product','count_point_groups','count_tuples','minimal_bst']
    for i in dir_names:
        check = Check(i)
        check.loadAllFile()
        check.error_detection()