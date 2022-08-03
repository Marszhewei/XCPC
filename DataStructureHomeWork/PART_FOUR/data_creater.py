import random

def create_data_for_ques1(data_group=11):
    f = open('data1.txt','w',encoding='utf-8')
    base_str = 'ABCDEFGHIGKLMNOPQRSTUVWXYZ'
    for i in range(1, data_group):
        f.write("data {}\n".format(i))
        for j in range(8):
            f.write(base_str[j])
            f.write(str(random.randint(1, 100)))
        f.write('\n')
    f.close()
    return

def create_data_for_ques2(data_group=11):
    f = open('data2.txt','w',encoding='utf-8')
    base_str = 'ABCDEFGHIGKLMNOPQRSTUVWXYZ'
    for i in range(1, data_group):
        f.write("data {}\n".format(i))
        for j in range(8):
            f.write(base_str[j])
        f.write('\n')
        for j in range(11):
            f.write(str(random.randint(0, 7)) + " " + str(random.randint(0, 7)))
            if j != 10:
                f.write(" ")
        f.write('\n')
    f.close()
    return


if __name__ == "__main__":
    create_data_for_ques1()
    create_data_for_ques2()