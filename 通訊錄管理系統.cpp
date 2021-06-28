#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
//�]�p�pô�H���c��
struct person {
	string m_name;
	int m_sex;//1:boy 2:girl
	int m_age;
	string m_phone;
	string m_addr;


 };
// �]�p�q�T�����c��

struct addressbooks {
	//�q�T���O�s�pô�H�}�C
	struct person personarray[MAX];
	//�q�T��������e�pô�H��
	int m_size;
};

//1.�K�[�pô�H
void addperson(addressbooks* abs) {
	//�P�_�q�T���O�_���Afull�N���K�[
	if (abs->m_size == MAX) {
		cout << "�q�T���w���A�L�k�K�[" << endl;
		return;
	}
	else {
		//�K�[�����pô�H
		//�m�W
		string name;
		cout << "�п�J�m�W: " << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;
		//�ʧO
		cout << "�п�J�ʧO: " << endl;
		cout << "1----boy" << endl;
		cout << "2---girl" << endl;
		int sex = 0;
		while (true) {//��J�D1�A2���ܡA���s��J
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "��J�����A���s��J" << endl;
		}
		//�~��
		cout << "�п�J�~��: " << endl;
		int age = 0;
		cin >> age;
		abs->personarray[abs->m_size].m_age = age;
	
		//�q��
		cout << "�п�J�pô�q��: " << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;

		//��}
		cout << "�п�J�a�x��}: " << endl;
		string address;
		cin >> address;
		abs->personarray[abs->m_size].m_addr = address;

		//��s�q�T���H��
		abs->m_size++;

		cout << "�K�[���\" << endl;

		system("pause");
		system("cls");
	}
}
//2.��ܩҦ��pô�H
void showperson(addressbooks* abs) {
	//�P�_�H�ƬO�_��0�A�p�G��0�A���ܬ�����0
	//�p�G����0�A����pô�H�H��

	if (abs->m_size == 0) {
		cout << "��e����������" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "�m�W: " << abs->personarray[i].m_name <<"\t";
			cout << "�ʧO: " << (abs->personarray[i].m_sex==1?"�k":"�k" )<< "\t";
			cout << "�~��: " << abs->personarray[i].m_age << "\t";
			cout << "�q��: " << abs->personarray[i].m_phone << "\t";
			cout << "�a�}: " << abs->personarray[i].m_addr << endl;

		}
	}
	system("pause");
	system("cls");
}

//�˴��H�O�_�s�b�A�p�G�s�b�A��^�pô�H�Ҧb�}�C����m�A���s�b��^-1
int isexit(addressbooks *abs,string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personarray[i].m_name == name) {
			return i;
		}
		return -1;
	}
}
//3.�R���pô�H
void deleteperson(addressbooks* abs) {
	cout << "�п�J�R���pô�H" << endl;
	string name;
	cin >> name;
	//ret==-1 ���d��
	//ret!=1 �d��
	int ret = isexit(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_size; i++) {
			//��Ʃ��e
			abs->personarray[i] = abs->personarray[i + 1];

		}
		abs->m_size--;//��s�q�T���H��
		cout << "�R�����\" << endl;

	}
	else{
		cout << "�d�L���H" << endl;
	}
	system("pause");
	system("cls");

}
//4.�d����w�pô�H
void findperson(addressbooks* abs) {
	cout << "�п�J�A�n�d�䪺�pô�H" << endl;
	string name;
	cin >> name;

	//�P�_���w�pô�H�O�_�s�b�q�T����
	int ret=isexit(abs, name);
	if (ret != -1) {
		cout << "�m�W: " << abs->personarray[ret].m_name << "\t";
		cout << "�ʧO: " << (abs->personarray[ret].m_sex == 1 ? "�k" : "�k") << "\t";
		cout << "�~��: " << abs->personarray[ret].m_age << "\t";
		cout << "�q��: " << abs->personarray[ret].m_phone << "\t";
		cout << "�a�}: " << abs->personarray[ret].m_addr << endl;

	}
	else {
		cout << "�d�L���H" << endl;
	}

	system("pause");
	system("cls");
}
//5.�ק���w�pô�H
void modifyperson(addressbooks *abs) {
	cout << "�п�J�A�n�ק諸�pô�H" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1) {
		string name;
		cout << "�п�J�m�W: " << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;
		//�ʧO
		cout << "�п�J�ʧO: " << endl;
		cout << "1----boy" << endl;
		cout << "2---girl" << endl;
		int sex = 0;
		while (true) {//��J�D1�A2���ܡA���s��J
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "��J�����A���s��J" << endl;
		}
		//�~��
		cout << "�п�J�~��: " << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].m_age = age;

		//�q��
		cout << "�п�J�pô�q��: " << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;

		//��}
		cout << "�п�J�a�x��}: " << endl;
		string address;
		cin >> address;
		abs->personarray[ret].m_addr = address;


		cout << "�ק令�\" << endl;
	}
	else {
		cout << "�d�L���H" << endl;
	}
	system("pause");
	system("cls");
}
//6.�M�Ÿ��
void clearperson(addressbooks* abs) {
	int select = 0;
	cout << "��J1�M�� �� ��J2���M��" << endl;
	cin >> select;
	abs->m_size = 0;
	if (select == 1) {
		cout << "�q�T���w�M��" << endl;
	}
	else {
		system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}
//��椶��
void showmenu() {
	cout << "*************************" << endl;
	cout << "***** 1. �K�[�pô�H *****" << endl;
	cout << "***** 2. ����pô�H *****" << endl;
	cout << "***** 3. �R���pô�H *****" << endl;
	cout << "***** 4. �d���pô�H *****" << endl;
	cout << "***** 5. �ק��pô�H *****" << endl;
	cout << "***** 6. �M���pô�H *****" << endl;
	cout << "***** 0. �h�X�q�T�� *****" << endl;
	cout << "*************************" << endl;
}

int main() {

	//�Ыسq�T�����c�ܶq
	addressbooks abs;
	//��l�Ƴq�T������e�H��
	abs.m_size = 0;

	int select = 0;

	while (true) {
		showmenu();

		cin >> select;

		switch (select) {
		case 1://1. �K�[�pô�H
			addperson(&abs);//�Q�Φa�}�ǻ�
			break;
		case 2://2. ����pô�H
			showperson(&abs);
			break;
		case 3://3. �R���pô�H
		/* {
			cout << "�п�J�R���pô�H�m�W: " << endl;
			string name;
			cin >> name;
			if (isexit(&abs, name) == -1) {
				cout << "�d�L���H" << endl;
			}
			else {
				cout << "��즹�H" << endl;
			}
		}*/
			deleteperson(&abs);
			break;
		case 4://4. �d���pô�H
			findperson(&abs);
			break;
		case 5://5. �ק��pô�H
			modifyperson(&abs);
			break;
		case 6://6. �M���pô�H
			clearperson(&abs);
			break;
		case 0://0. �h�X�q�T��
			cout << "�w��U���ϥ�" << endl;
			return 0;
			break;
		default:
			break;
		}
	}


	return 0;
}