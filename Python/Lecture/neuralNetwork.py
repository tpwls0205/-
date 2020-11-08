# 1) 초기화 : 입력, 은닉, 출력노드의 수 설정
# 2) 학습 : 학습데이터를 통해 오차역전파 : 가중치 업데이트
# 3) 질의 : 학습이 끝난 후 입력을 받아 순전파의 결과를 응답

import numpy
import scipy.special
import matplotlib.pyplot
#%matplotlib inline          # jypyter notebook 설정

# 신경망 클래스
class neuralNetwork:

    # 생성자 : 신경망 초기화
    def __init__(self, inputnodes, hiddennodes, outputnodes, learningrate):
        # 각 계층의 노드수를 멤버변수에 저장
        self.inodes = inputnodes
        self.hnodes = hiddennodes
        self.onodes = outputnodes

        # 학습률 저장
        self.lr = learningrate

        # 가중치 행렬 wih와 who
        self.wih = numpy.random.normal(0.0, pow(self.hnodes, -0.5),
                                       (self.hnodes, self.inodes))
        self.who = numpy.random.normal(0.0, pow(self.onodes, -0.5),
                                       (self.onodes, self.hnodes))

        # 활성화 함수 => 시그모이드 함수 사용
        self.activation_function = lambda x : scipy.special.expit(x)

    # 신경망 학습(오류 역전파)
    def train(self, inputs_list, targets_list):
        # 입력 리스트를 2차원의 행렬로 변환
        inputs = numpy.array(inputs_list, ndmin=2).T
        targets = numpy.array(targets_list, ndmin=2).T

        # 순전파 begin-----------------------
        # 은닉 계층으로 들어오는 신호를 계산
        hidden_inputs = numpy.dot(self.wih, inputs)
        # 은닉 계층에서 나가는 신호를 계산
        hidden_outputs = self.activation_function(hidden_inputs)

        # 최종 출력 계층으로 들어오는 신호를 계산
        final_inputs = numpy.dot(self.who, hidden_outputs)
        final_outputs = self.activation_function(final_inputs)
        # 순전파 end-----------------------

        # 오차역전파 begin-----------------------
        # 출력 계층의 오차는 (실제값 - 계산 값)
        output_errors = targets - final_outputs
        #output_errors = pow(targets - final_outputs, 2)
        # 은닉 계층의 오차는 가중치에 의해 나뉜 출력 계층의 오차들을 재조합해 계산
        hidden_errors = numpy.dot(self.who.T, output_errors)

        # 은닉 계층과 출력 계층간의 가중치 업데이트(학습)
        self.who += self.lr * numpy.dot((output_errors * final_outputs * (1.0 - final_outputs)),
                                        numpy.transpose(hidden_outputs))

        # 입력 계층과 은닉 계층간의 가중치 업데이트(학습)
        self.wih += self.lr * numpy.dot((hidden_errors * hidden_outputs * (1.0 - hidden_outputs)),
                                        numpy.transpose(inputs))
        # 오차역전파 end-----------------------

    # 질의(순전파)
    def query(self, inputs_list):
        # 입력 리스트를 2차원 행렬로 변환
        inputs = numpy.array(inputs_list, ndmin=2).T
        
        # 은닉계층으로 들어오는 신호를 계산
        hidden_inputs = numpy.dot(self.wih, inputs)
        # 은닉계층에서 나가는 신호를 계산
        hidden_outputs = self.activation_function(hidden_inputs)

        # 최종 출력 계층으로 들어오는 신호를 계산
        final_inputs = numpy.dot(self.who, hidden_outputs)
        # 최종 출력 계층에서 나가는 신호를 계산
        final_outputs = self.activation_function(final_inputs)

        return final_outputs

def showMNIST():
    data_file = open("mnist_dataset/mnist_train_100.csv", "r")
    data_list = data_file.readlines()
    data_file.close()
    all_values = data_list[0].split(',')
    image_array = numpy.asfarray(all_values[1:]).reshape((28, 28))
    matplotlib.pyplot.imshow(image_array, cmap='Greys', interpolation='None')
    matplotlib.pyplot.show()

def runDeepLearining():
    input_nodes = 784       # 28x28 픽셀수
    hidden_nodes = 100      # 적당한 중간계층 수
    output_nodes = 10       # 0 ~ 9 분류 가지수

    learning_rate = 0.3

    n = neuralNetwork(input_nodes, hidden_nodes, output_nodes, learning_rate)

    # mnist 학습 데이터인 csv파일을 리스트로 불러오기
    training_data_file = open("mnist_dataset/mnist_train.csv", "r")
    training_data_list = training_data_file.readlines()
    training_data_file.close()

    epochs = 3  # 반복 학습 회수(에포크)

    # 신경망 학습시키기
    for e in range(epochs):
        print("epoch : ",(e+1), "회")
        for record in training_data_list:
            # 레코드를 쉼표로 분리
            all_values = record.split(',')
            # 입력값의 범위와 값조정(정규화) 0 ~ 255 => 0.01 ~ 1.0
            inputs = (numpy.asfarray(all_values[1:])/255.0*0.99)+0.01
            # 레이블에 해당되는 노드의 타겟값은 0.99, 나머지는 0.01로 타겟값 설정
            targets = numpy.zeros(output_nodes) + 0.01
            targets[int(all_values[0])] = 0.99
            # 학습 진행
            n.train(inputs, targets)

    # 신경망에 질의하기
    test_data_file = open("mnist_dataset/mnist_test.csv", "r")
    test_data_list = test_data_file.readlines()
    test_data_file.close()

    scorecard = []

    for record in test_data_list:
        all_values = record.split(",")
        correct_label = int(all_values[0])
        inputs = (numpy.asfarray(all_values[1:])/255.0*0.99)+0.01
        outputs = n.query(inputs)
        label = numpy.argmax(outputs)
        print(label, "network's answer")
        if(label == correct_label):
            scorecard.append(1)
        else:
            scorecard.append(0)

    print(scorecard)
    scorecard_array = numpy.asarray(scorecard)
    print("performance = ", scorecard_array.sum()/scorecard_array.size)

# 실행코드
# neuralNetwork.py를 직접 실행할 경우 true가 반환
# 다른 코드에서 neuralNetwork를 import해서 사용할 경우는 false를 반환
if __name__ == '__main__':
    #showMNIST()
    runDeepLearining()




