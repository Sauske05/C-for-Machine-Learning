#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


class SimpleLinearRegression {
private:
	double weights;
	double bias;
	double learning_rate;
	int epoches;
public:
	SimpleLinearRegression(double lr = 0.01, int epoches=20) : 
		learning_rate(lr), epoches(epoches){
		weights = 0.0;
		bias = 0.0;
	}

	double predict(double x,double y) {
		return weights * x + bias;
	}
	double loss_function(vector<double> y_pred, vector<double> y_actual) {
		int length = y_pred.size();
		double total_loss = 0;
		for (int i = 0; i < length; i++) {
			total_loss += pow((y_actual[i] - y_pred[i]), 2);
		}
		return total_loss / length;
	}


	pair<double, double> compute_gradients(vector<double> y_train,
		vector<double> y_pred, vector<double> x) {
		int length = y_train.size();
		double dw = 0; double db = 0;
		for (int i = 0; i < length; i++) {
			dw += (y_train[i] - y_pred[i]) * x[i];
			db += y_train[i] - y_pred[i];
		}

		dw = -2 * dw / length;
		db = -2 * db / length;

		return { dw, db };

	}


	void train(vector<double>& x_train, vector<double>& y_train) {
		int length = x_train.end() - x_train.begin();
		for (int i = 0; i < epoches; i++) {
			vector<double> y_pred = {};
			for (int j = 0; j < length; j++) {
				y_pred.push_back(predict(x_train[j], y_train[j]));
			}
			double epoch_loss = loss_function(y_pred, y_train);
			pair<double, double> gradients = compute_gradients(y_train, y_pred, x_train);
			double dw = gradients.first;
			double db = gradients.second;

			weights -= dw * learning_rate;
			bias -= db * learning_rate;
			
			cout << "Train loss at epoch:" << i + 1 << "--> " <<
				epoch_loss << endl;
		}

	}
	
	
};

int main() {
	SimpleLinearRegression regression;
	vector<double> x_train= { 1.0,2.0,3.0,4.0,5.0,6.0,7.0 };
	vector<double> y_train = { 2.0,4.0,6.0,8.0,10.0,12.0,14.0 };
	regression.train(x_train, y_train);
	return 0;
}