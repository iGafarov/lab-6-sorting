#pragma once
#include <stdio.h>
#include <iostream>
#include <libutils/io.h>
#include <vector>
#include <chrono>

using namespace std;

template <typename T>
void Print(std::vector<T>& v) {
	std::cout << "Your vector: " << std::endl;
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}


template <typename T>
void Random_Filling(std::vector<T>& v, const size_t size) {
	for (size_t i = 0; i < size; ++i) {
		v.push_back(i);
	}
	for (size_t i = 0; i < size; ++i) {
		std::swap(v[i], v[rand() % (v.size() - i) + i]);
	}
}

//class SimpleTimer {
//private:
//	std::chrono::time_point<std::chrono::steady_clock> start, end;
//	double *_duration_count;
//public:
//	SimpleTimer() {
//		_duration_count = nullptr;
//		start = std::chrono::high_resolution_clock::now();
//	}
//	~SimpleTimer() {
//		end = std::chrono::high_resolution_clock::now();
//		std::chrono::duration<double> duration = end - start;
//		*_duration_count = duration.count();
//		cout << "Duration: " << duration.count() << " s." << endl;
//	}
//	double& operator[](const int index) {
//		return _duration_count[index];
//	}
//};

//template <typename T>
//void Merge_Sort(T* arr, size_t size) {
//
//	// ������:
//	// s - ���� ���������� (s = true - ���������� �� ������� ��������� ������� � ������� ����������� �������, s = false - ��������)
//	// f - ���� ������ �� ����������
//	// N - ������ �������
//	// i,j - ������ � ����� ��������� �������
//	// k,l - ������ � ����� ���������������� �������
//	// d - ���, � ������� ����� k (� ����������� �� ����, ���� ���� k)
//	// ������������ ��������������� � �������� ������
//
//	/*=================================
//			��������� ���������
//	=================================*/
//	bool s = true;
//	bool f;	
//
//	// ��������� ������ (��������� �������������� � ���������)
//	arr = new T[size];
//	
//	int i, j, k, l, d;
//	do {
//		// �������� ������ � ������
//		if (s) {
//			i = 0;
//			j = size - 1;
//			k = size;
//			l = 2 * size - 1;
//		}
//		// �������� ������ � �����
//		else {
//			k = 0;
//			l = size - 1;
//			i = size;
//			j = 2 * size - 1;
//		}
//
//		d = 1; f = false;
//
//		while (1) {
//
//			// ���� ������� ���� ����� (������ �� ����������� � ������� �����������)
//			if (arr[i] <= arr[j]) {
//				// ���� ������� ������� (��������� ������� � ��� ������� �� ��������)
//				if (i == j)
//				{
//					// ��������� ��������� �������
//				    arr[k] = arr[i];
//					// ������ �������� ������ �� ���������������
//					if (s)
//						s = false;
//					else
//						s = true;
//					break;
//				}
//				// ������������� ����� �����
//				arr[k] = arr[i];
//				k += d;
//				++i;
//				if (arr[i - 1] <= arr[i]) continue;
//
//				// ������������� ����� ������
//				do {
//					arr[k] = arr[j];
//					k += d;
//					--j;
//				} while (arr[j + 1] <= arr[j]);
//			}
//			// ���� ������� ���� ������
//			else {
//				// ������������� ����� ������
//				arr[k] = arr[j];
//				k += d;
//				--j;
//				if (arr[j + 1] <= arr[j]) continue;
//
//				// ������������� ����� �����
//				do {
//					arr[k] = arr[i];
//					k += d;
//					++i;
//				} while (arr[i - 1] <= arr[i]);
//			}
//			f = true;
//			// ������ ���
//			d = d * (-1);
//			std::swap(k, l);
//		}
//	} while (f);
//	// ���� ������������ �������������� ������ (������ �� ���������), �� ���������� ��� � �������� (�����)
//	if (!s) {
//		for (auto i = 0; i < size; ++i)
//		{
//			arr[i] = arr[i + size];
//		}
//	}
//	// ������ ����� ������ �� �����
//	//v.resize(N);
//}

//==================================================================================================
//template <typename T>
//void Insertion_Sort_Array(T* arr, size_t size) {
//	for (size_t i = 1; i < size; ++i) {
//		T tmp = arr[i];
//		for (size_t j = i; j > 0; j--) {
//			if (arr[j - 1] > tmp) {
//				arr[j] = arr[j - 1];
//				arr[j - 1] = tmp;
//			}
//		}		
//	}
//}

//==================================================================================================
//                                       SORTING FOR VECTOR
//==================================================================================================

template <typename T>
void Selection_Sort(std::vector<T>& v) {
	T tmp;
	for (size_t i = 0; i < v.size() - 1; ++i) {
		size_t min_index = i;
		for (size_t j = i; j < v.size(); ++j) {
			if (v[j] < v[min_index])
				min_index = j;
		}
		if (i != min_index) {
			tmp = v[i];
			v[i] = v[min_index];
			v[min_index] = tmp;
		}
	}
}

template <typename T>
void Bubble_Sort(std::vector<T>& v) {
	T tmp;
	for (size_t i = 0; i < v.size() - 1; ++i) {
		for (size_t j = 0; j < v.size() - 1 - i; ++j) {
			if (v[j + 1] < v[j]) {
				tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
		}
	}
}

template <typename T>
void Shell_Sort(std::vector<T>& v)
{
	size_t step = v.size() / 2;

	while (step > 0) {
		// ������������ ���������, ������� ����������� �� ����������� ����
		for (size_t i = step; i < v.size(); ++i) {
			// ������������ ��������� ������ ���������
			for (int j = i - step; j >= 0 && v[j + step] < v[j]; j -= step)
			{
				std::swap(v[j], v[j + step]);
			}
		}
		step /= 2;
	}
}

template <typename T>
void Quick_Sort(std::vector<T>& v) {
	if (v.size() == 1) return;
	Quick_Sort_Src(v, 0, v.size() - 1);
}

template <typename T>
void Quick_Sort_Src(std::vector<T>& v, int left, int right) {
	int l = left, r = right;
	T tmp = v[(left + right) / 2];
	while (l <= r) {
		while (v[l] < tmp) ++l;
		while (tmp < v[r]) --r;
		if (l <= r) {
			std::swap(v[l], v[r]);
			++l;
			--r;
		}
	}

	if (left < r)
		Quick_Sort_Src(v, left, r);
	if (l < right)
		Quick_Sort_Src(v, l, right);
}

template <typename T>
void Merge_Sort(std::vector<T>& v) {

	// ������:
	// s - ���� ���������� (s = true - ���������� �� ������� ��������� ������� � ������� ����������� �������, s = false - ��������)
	// f - ���� ������ �� ����������
	// N - ������ �������
	// i,j - ������ � ����� ��������� �������
	// k,l - ������ � ����� ���������������� �������
	// d - ���, � ������� ����� k (� ����������� �� ����, ���� ���� k)
	// ������������ ��������������� � �������� ������

	/*=================================
			��������� ���������
	=================================*/
	bool s = true;
	bool f;
	const int N = static_cast<int>(v.size());

	// ��������� ������ (��������� �������������� � ���������)
	v.resize(static_cast<size_t>(N) * 2);


	int i, j, k, l, d;
	do {
		// �������� ������ � ������
		if (s) {
			i = 0;
			j = N - 1;
			k = N;
			l = 2 * N - 1;
		}
		// �������� ������ � �����
		else {
			k = 0;
			l = N - 1;
			i = N;
			j = 2 * N - 1;
		}

		d = 1; f = false;

		while (1) {

			// ���� ������� ���� ����� (������ �� ����������� � ������� �����������)
			if (v[i] <= v[j]) {
				// ���� ������� ������� (��������� ������� � ��� ������� �� ��������)
				if (i == j)
				{
					// ��������� ��������� �������
					v[k] = v[i];
					// ������ �������� ������ �� ���������������
					if (s)
						s = false;
					else
						s = true;
					break;
				}
				// ������������� ����� �����
				v[k] = v[i];
				k += d;
				++i;
				if (v[static_cast<size_t>(i) - 1] <= v[i]) continue;

				// ������������� ����� ������
				do {
					v[k] = v[j];
					k += d;
					--j;
				} while (v[static_cast<size_t>(j) + 1] <= v[j]);
			}
			// ���� ������� ���� ������
			else {
				// ������������� ����� ������
				v[k] = v[j];
				k += d;
				--j;
				if (v[static_cast<size_t>(j) + 1] <= v[j]) continue;

				// ������������� ����� �����
				do {
					v[k] = v[i];
					k += d;
					++i;
				} while (v[static_cast<size_t>(i) - 1] <= v[i]);
			}
			f = true;
			// ������ ���
			d = d * (-1);
			std::swap(k, l);
		}
	} while (f);
	// ���� ������������ �������������� ������ (������ �� ���������), �� ���������� ��� � �������� (�����)
	if (!s) {
		for (auto i = 0; i < N; ++i)
		{
			v[i] = v[static_cast<size_t>(i) + N];
		}
	}
	// ������ ����� ������ �� �����
	v.resize(N);
}

//==================================================================================================
//                                                Clocks
//==================================================================================================
template<typename T>
double Clock(int i, std::vector<T>& v)
{
	if (i == 0) {
		auto start = std::chrono::steady_clock::now();
		Selection_Sort(v);
		auto end = std::chrono::steady_clock::now();
		chrono::duration<double> duration = end - start;
		return duration.count();
	}
	if (i == 1) {
		auto start = std::chrono::steady_clock::now();
		Bubble_Sort(v);
		auto end = std::chrono::steady_clock::now();
		chrono::duration<double> duration = end - start;
		return duration.count();
	}
	if (i == 2) {
		auto start = std::chrono::steady_clock::now();
		Shell_Sort(v);
		auto end = std::chrono::steady_clock::now();
		chrono::duration<double> duration = end - start;
		return duration.count();
	}
	if (i == 3) {
		auto start = chrono::steady_clock::now();
		Quick_Sort(v);
		auto end = chrono::steady_clock::now();
		chrono::duration<double> duration = end - start;
		return duration.count();
	}
	if (i == 4) {
		auto start = std::chrono::steady_clock::now();
		Merge_Sort(v);
		auto end = std::chrono::steady_clock::now();
		chrono::duration<double> duration = end - start;
		return duration.count();
	}
}
