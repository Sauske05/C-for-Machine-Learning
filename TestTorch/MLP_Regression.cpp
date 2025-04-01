#include <iostream>
#include <vector>

using namespace std;
using matrix = vector<vector<double>>;

class MatrixClass {
public:
	static matrix multiply(matrix A, matrix B) {
	//base check :
		// A --> (m, n) then B has to be of shape (n,q)
		if (A.empty() || B.empty() || A[0].size() != B.size()) {
			// Return empty matrix or throw an error if dimensions don't match
			return matrix();
		}
	
		int m = A.size();        // rows of A
		int n = B.size();        // columns of A / rows of B
		int p = B[0].size();
		matrix C(m , vector<double>(p, 0.0));
	for (int i = 0; i < m; i++) {

		for (int j = 0; j < p; j++) {
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}

		}

	}

	return C;
};
	//square matrix only!
	static matrix transpose(matrix x) {
		matrix out = vector<vector<double>>(x[0].size(), vector<double>(x.size(), 0.0));
		for (int i = 0; i < x.size(); i++) {
			for (int j = 0; j < x.size(); j++) {

				out[i][j] = x[j][i];
			}
		}

		return out;
	}



	static matrix add(matrix A, matrix B) {
		matrix C(A.size(), vector<double>(A[0].size(), 0.0));
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A[0].size(); j++) {
				C[i][j] = A[i][j] + B[i][j];
			}
			}

		return C;
	}

	static vector<double> squeeze(matrix A) {
		// the matrix is 2D. Assumption
		vector<double> squeezed_matrix;
		for (int i = 0; i < A[0].size(); i++) {

			squeezed_matrix.push_back(A[0][i]);
		}

		return squeezed_matrix;
	}
};


class LinearLayer {
private:
	int in_features;
	int out_features;
	//bool bias = false;
	vector<double> layer_bias;
	vector<vector<double>> layer_weights;
public:
	LinearLayer(int in_features, int out_features) :
		in_features(in_features), out_features(out_features)
		 {
		// out_features will be used for bias dim.
		
		layer_weights = vector<vector<double>>(out_features, vector<double>(in_features, 0.0));
		layer_bias = vector<double>(out_features, 0.0);

		
	}


	vector<double> forward(const vector<double> &x) {
		//weights --> (out_features, in_features)
		matrix x_mat = vector<vector<double>>(1, x);
		matrix bias_mat = vector<vector<double>>(1, layer_bias);
		//bias --> (1, out_features)
		//x --> (1, in_features)
		matrix output_matrix(1, vector<double>(out_features, 0.0));
		vector<double> out_vector;
		// return xA.T + b
		MatrixClass matrix;
		output_matrix = matrix.add(matrix.multiply(x_mat, matrix.transpose(layer_weights)), bias_mat);
		
		out_vector = matrix.squeeze(output_matrix);
		return out_vector;
	
	}


	void shape_check() {
		cout << "Weights : " << layer_weights.size() << endl;
		for (vector<double> rows : layer_weights) {
			for (int j : rows) {
				cout << j << " ";
			}
			cout << endl;

		}
		cout << "Bias : " << layer_bias.size() << endl;

		for (int j : layer_bias) {
			cout << j << " ";
		}

	}

	
};

int main() {
	vector<double> x = { 1.0,2.0,3.0,4.0 };
	LinearLayer layer(x.size(), 2);
	layer.shape_check();
	vector<double> out_vector = layer.forward(x);
	cout << "Size of the input vector: " << x.size() << endl;
	cout << "Size of the output vector: " << out_vector.size() << endl;
	
	return 0;

}