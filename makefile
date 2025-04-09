neuralnetwork: driver.cpp  Module.o Block.o LinearLayer.o ReLUActivation.o NeuralNetwork.o
	g++ driver.cpp  Module.o Block.o LinearLayer.o ReLUActivation.o NeuralNetwork.o

Module.o: Module.cpp Module.h
	g++ -c Module.cpp

Block.o: Block.cpp Block.h
	g++ -c Block.cpp

LinearLayer.o: LinearLayer.cpp LinearLayer.h
	g++ -c LinearLayer.cpp

ReLUActivation.o: ReLUActivation.cpp ReLUActivation.h
	g++ -c ReLUActivation.cpp

NeuralNetwork.o: NeuralNetwork.cpp ReLUActivation.h
	g++  -c NeuralNetwork.cpp


