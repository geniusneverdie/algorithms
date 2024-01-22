//��һ������һ��-Stable Matching
#include<iostream>
using namespace std;
int n;
bool* men_engaged = new bool[n];
bool* women_engaged = new bool[n];
void StableMatching_Gale_Shapley(int** a, int** b) {
	int* Lady_Offer = new int[n];//����ƥ�������±�0-n-1ΪŮʿ��������Ϊ��ʿ
	int* men_pointer = new int[n];
	for (int i = 0; i < n; i++) {
		Lady_Offer[i] = -1;//����Ϊ����ֵ
		men_pointer[i] = 0;
	}
	while (1) {//ÿһ�춼���л���
		bool flag = true;
		for (int i = 0; i < n; i++) {//����Ƿ������˶��Ѿ�������
			if (men_engaged[i] == false)
				flag = false;
		}
		if (flag == true) {//�������˶��Ѿ���������ô�ͽ���ƥ�䣬������
			int* result = new int[n];//Ϊ�����ͳһ�������Ŀһ�£���Ϊ��ʿ��Ϊ�±꣬��֮ƥ���Ůʿ��Ϊ��ֵ
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (Lady_Offer[j] == i) {
						result[i] = j;
						break;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				cout << "(" << char(i + 65) << "," << char(result[i] + 88) << ")" << endl;
			}
			return;
		}
		else {
			for (int i = 0; i < n; i++) {
				if (men_engaged[i] == false) {
					if (women_engaged[a[i][men_pointer[i]]] == false) {//����ʱ������Ůʿ����,������Ůʿ�±꣺a[i][men_pointer[i]]
						Lady_Offer[a[i][men_pointer[i]]] = i;
						men_engaged[i] = women_engaged[a[i][men_pointer[i]]] = true;
						continue;
					}
					else {//���������Ƚ�˭��
						for (int j = 0; j < n; j++) {
							if (b[a[i][men_pointer[i]]][j] == i) {//��i��ǰ�����ϲ��i���ܾ�ԭ���Ļ�Լ����i����
								men_engaged[Lady_Offer[a[i][men_pointer[i]]]] = false;
								men_pointer[Lady_Offer[a[i][men_pointer[i]]]]++;
								Lady_Offer[a[i][men_pointer[i]]] = i;
								men_engaged[i]= true;
								break;
							}
							else if (b[a[i][men_pointer[i]]][j] == Lady_Offer[a[i][men_pointer[i]]]) {//��i�ں����ʧ��
								men_pointer[i]++;
								break;
							}
						}
					}
				}
			}
		}
	}
	return;
}
int main() {
	cin >> n;
	int** men_preference = new int* [n];//����Ĭ�ϣ�ABC��ʾ
	int** women_preference = new int* [n];//Ů��Ĭ�ϣ�XYZ��ʾ

	for (int i = 0; i < n; i++) {
		men_preference[i] = new int[n];
		women_preference[i] = new int[n];
		men_engaged[i] = women_engaged[i] = false;
	}
	for (int i = 0; i < 2 * n; i++) {
		if (i < n) {//����
			string preference;
			cin >> preference;
			int j = 2;//�ӵ�����λ�ÿ�ʼ������ð�ź�
			int count = 0;//��ü���ϲ����
			while (j<=2*n) {
					men_preference[i][count] = preference[j] - 88;//��ĸת��Ϊ���֣�X-88��Y-89��Z-90��
					count++;
					j += 2;
			}
		}
		else {//Ů��
			string preference;
				cin >> preference;
				int j = 2;//�ӵ�����λ�ÿ�ʼ������ð�ź�
				int count = 0;//��ü���ϲ����
				while (j<=2*n) {
						women_preference[i-n][count] = preference[j] - 65;//��ĸת��Ϊ���֣�A-65��B-66��C-67)
						count++;
						j += 2;
				}
			}
	}
	StableMatching_Gale_Shapley(men_preference, women_preference);
	return 0;
	}