	#include "libutils/io.h"
#include "Sorts.h"
int main() {
	int User_Choise1 = 1;
	do {
		std::vector<int> v;
		const int accuracy = utils::read_int("Enter accuracy: ", 1, 5000);//количество выполнения сортировки для векторов одного и того же размера 		
		std::vector<int> SIZES;//Вектор размеров
		int number_sizes = utils::read_int("Enter number of sizes: ", 1, 20);
		int step = utils::read_int("Enter step: ", 1, 1000000);
		for (size_t i = 1; i <= number_sizes; ++i) {
			/*if (i == 0) {
				SIZES[i] = step;
				continue;
			}
			SIZES[i] = SIZES[i - 1] + step;*/
			SIZES.push_back(step * i);
		}
		std::vector<int> vcopy = v;//создаем копию вектора 
		system("pause");
		int User_Choise2 = 1;
		std::vector<double> time;//вектор времен, за которые вычисляется определенная сортировка с векторами одного и того же размера

		double average_time = 0.0;//Среднее время выполнения одной сортировки с векторами одного и того же размера
		std::vector<double> Average_Times;//Вектор средних времен каждой сортировки со векторами разных размеров
		do {
			system("cls");
			switch (utils::read_int("Choose variant of sorting: \n 0 - Selection Sort.\n 1 - Bubble Sort.\n 2 - Shella Sort.\n 3 - Quick Sort.\n 4 - Merge Sort.\n", 0, 4))
			{
			case 0:
				//Selection_Sort(v);
				cout << "Please wait..." << endl;
				for (size_t i = 0; i < number_sizes; ++i) {
					for (size_t j = 0; j < accuracy; ++j) {
						Random_Filling(v, SIZES[i]);

						/*cout << "New vector: " << endl;
						if (utils::read_int("\t Enter '1' if you want to print your vector(NO ,PLEASE, NO!!!)\n\t Else enter '0'\n", 0, 1) == 1)
						{
							for (auto i : v) cout << i << " ";
							cout << endl;
						}*/

						time.push_back(Clock(0, v));

						/*cout << "Sorted vector: " << endl;
						if (utils::read_int("\t Enter '1' if you want to print your vector(NO ,PLEASE, NO!!!)\n\t Else enter '0'\n", 0, 1) == 1)
						{
							for (auto i : v) cout << i << " ";
							cout << endl;
						}*/

						v.clear();
					}
					for (auto i : time) {
						average_time += i;
					}
					average_time = average_time / accuracy;//получили среднее время выполнения сортировки с векторами одного размера
					time.clear();
					Average_Times.push_back(average_time);
					average_time = 0.0;
					cout << endl;
					cout << "SIZE: " << SIZES[i] << endl;
					cout << "Average time " << Average_Times[i] << endl;
				}

				break;
			case 1:
				//Bubble_Sort(v);
				cout << "Please wait..." << endl;
				for (size_t i = 0; i < number_sizes; ++i) {
					for (size_t j = 0; j < accuracy; ++j) {
						Random_Filling(v, SIZES[i]);

						time.push_back(Clock(1, v));

						v.clear();
					}
					for (auto i : time) {
						average_time += i;
					}
					average_time = average_time / accuracy;//получили среднее время выполнения сортировки с векторами одного размера
					time.clear();
					Average_Times.push_back(average_time);
					average_time = 0.0;
					cout << endl;
					cout << "SIZE: " << SIZES[i] << endl;
					cout << "Average time " << Average_Times[i] << endl;
				}
				break;
			case 2:
				//Shell_Sort(v);
				cout << "Please wait..." << endl;
				for (size_t i = 0; i < number_sizes; ++i) {
					for (size_t j = 0; j < accuracy; ++j) {
						Random_Filling(v, SIZES[i]);

						time.push_back(Clock(2, v));

						v.clear();
					}
					for (auto i : time) {
						average_time += i;
					}
					average_time = average_time / accuracy;//получили среднее время выполнения сортировки с векторами одного размера
					time.clear();
					Average_Times.push_back(average_time);
					average_time = 0.0;
					cout << endl;
					cout << "SIZE: " << SIZES[i] << endl;
					cout << "Average time " << Average_Times[i] << endl;
				}
				break;
			case 3:
				//Quick_Sort(v);
				cout << "Please wait..." << endl;
				for (size_t i = 0; i < number_sizes; ++i) {
					for (size_t j = 0; j < accuracy; ++j) {
						Random_Filling(v, SIZES[i]);

						time.push_back(Clock(3, v));

						v.clear();
					}
					for (auto i : time) {
						average_time += i;
					}
					average_time = average_time / accuracy;//получили среднее время выполнения сортировки с векторами одного размера
					time.clear();
					Average_Times.push_back(average_time);
					average_time = 0.0;
					cout << endl;
					cout << "SIZE: " << SIZES[i] << endl;
					cout << "Average time " << Average_Times[i] << endl;
				}
				break;
			case 4:
				//Merge_Sort(v);
				cout << "Please wait..." << endl;
				for (size_t i = 0; i < number_sizes; ++i) {
					for (size_t j = 0; j < accuracy; ++j) {
						Random_Filling(v, SIZES[i]);

						time.push_back(Clock(4, v));

						v.clear();
					}
					for (auto i : time) {
						average_time += i;
					}
					average_time = average_time / accuracy;//получили среднее время выполнения сортировки с векторами одного размера
					time.clear();
					Average_Times.push_back(average_time);
					average_time = 0.0;
					cout << endl;
					cout << "SIZE: " << SIZES[i] << endl;
					cout << "Average time " << Average_Times[i] << endl;
				}
				break;
			}
			User_Choise2 = utils::read_int("0 - back\n1 - choose sort again\n", 0, 1);
		} while (User_Choise2 == 1);
		system("cls");
		User_Choise1 = utils::read_int("0 - end\n1 - choose new size\n", 0, 1);
	} while (User_Choise1 == 1);
}

