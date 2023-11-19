//Project_程序运行中的变量添加及修改_DesignedByBrianBit
#include <windows.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int defaultVar = 0;
int* varAddressList[100];
string varNameList[100];
int counter = 1;//地址集和变量名称集

void newVar(string varName) {
	varAddressList[0] = &defaultVar;
	varAddressList[counter] = varAddressList[counter-1]+1;//地址分配
	varNameList[counter] = varName;//命名
	cout<<"New Variable Type Int Name "<<varNameList[counter]<<" Address "<<varAddressList[counter]<<" Value "<<&varAddressList[counter]<<endl;
	counter++;
}//新建变量

//旧daatEdit
//void dataEdit(string mode) {
//	int value;
//	if(mode == "pointer") {
////		int* ptr = new int;
////		cout<<"Input configs(pointer value)."<<endl;
////		cin>>*ptr>>value;
////        *ptr = value;
////        delete ptr;
//		string address;
//        cout << "Input address:" << endl;
//        cin >> address;
//
//        // 将输入的地址转换为指针类型
//        int* ptr = reinterpret_cast<int*>(std::stoi(address, nullptr, 16));
//
//        // 检查指针是否有效
//        if (ptr != nullptr) {
//            // 修改指针指向的值
//            cout << "Input new value:" << endl;
//            int newValue;
//            cin >> newValue;
//            *ptr = newValue;
//            cout << "Value at address " << address << " is updated." << endl;
//        } else {
//            cout << "Error: Invalid address." << endl;
//        }
//	} else if(mode == "varName") {
//		string varName;
//		cout<<"Input configs(varName value)."<<endl;
//		cin>>varName>>value;
//		std::string* it = std::find(varNameList, varNameList + sizeof(varNameList)/sizeof(varNameList[0]), varName);
//    	if (it != varNameList + sizeof(varNameList)/sizeof(varNameList[0])) {
//        	int index = std::distance(varNameList, it);
//        	*varAddressList[index] = value;
//			//*varAddressList[varNameList.find(varName,1)] = value;//通过查询 名字 在 名字集 中的位置获取地址然后更改
//		}
//	} else {
//		cout<<"Error:Invaild Mode"<<endl;
//	}
//}//数据编辑


void dataEdit(string mode) {
	int value;
	if (mode == "pointer") {
		string address;
		cout << "Input address:" << endl;
		cin >> address;

		// 将输入的地址转换为指针类型
		int* ptr = reinterpret_cast<int*>(std::stoi(address, nullptr, 16));

		// 检查指针是否有效
		if (ptr != nullptr) {
			// 修改指针指向的值
			cout << "Input new value:" << endl;
			cin >> value;
			*ptr = value;
			cout << "Value at address " << address << " is updated." << endl;
		} else {
			cout << "Error: Invalid address." << endl;
		}
	} else if (mode == "varName") {
		string varName;
		//cout<<"Input configs(varName value)."<<endl;
		//cin>>varName>>value;
		cout<<"Input varName:"<<endl;
		cin>>varName;
		cout << "Input new value:" << endl;
		cin >> value;

		std::string* it = std::find(varNameList, varNameList + sizeof(varNameList)/sizeof(varNameList[0]), varName);
		if (it != varNameList + sizeof(varNameList)/sizeof(varNameList[0])) {
			int index = std::distance(varNameList, it);
			*varAddressList[index] = value;
			//*varAddressList[varNameList.find(varName,1)] = value;//通过查询 名字 在 名字集 中的位置获取地址然后更改
		}
	} else {
		cout << "Error: Invalid mode." << endl;
	}
}


void getAddress(string varName) {
	std::string* it = std::find(varNameList, varNameList + sizeof(varNameList)/sizeof(varNameList[0]), varName);
	if (it != varNameList + sizeof(varNameList)/sizeof(varNameList[0])) {
		int index = std::distance(varNameList, it);
		cout<<varAddressList[index]<<"  "<<*varAddressList[index]<<endl;//同理
	}

}

int main() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout<<"WARNING:Do not run this program with AntiCheat for Mutiplayer Game running,or your game account will be banned!!!"<<endl;
	cout<<"WARNING:Do not run this program with AntiCheat for Mutiplayer Game running,or your game account will be banned!!!"<<endl;
	cout<<"WARNING:Do not run this program with AntiCheat for Mutiplayer Game running,or your game account will be banned!!!"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout<<endl;

	string str;

	while(1<2) {
		cout<<endl<<"Input functions' name(newVar/dataEdit/getAddress)."<<endl;
		cin>>str;
		if(str=="exit") {
			system("pause");
			return 0;
		} else if(str=="getAddress") {
			cout<<"Input config for function(varName)."<<endl;
			string cfg;
			cin>>cfg;
			getAddress(cfg);
		} else if(str=="dataEdit") {
			cout<<"Input config for function(mode:pointer/varName)."<<endl;
			string cfg;
			cin>>cfg;
			dataEdit(cfg);
		} else if(str=="newVar") {
			cout<<"Input config for function(varName)."<<endl;
			string cfg;
			cin>>cfg;
			newVar(cfg);
		} else {
			cout<<"Error:Invaild function.";
		}

	}
}
